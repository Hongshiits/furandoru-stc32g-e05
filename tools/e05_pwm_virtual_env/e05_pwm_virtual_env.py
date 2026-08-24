#!/usr/bin/env python3
"""Virtual simulation environment for Example/Coreboard_Demo/E05_pwm_demo.

This simulator mirrors the key firmware behavior:
- PWM channel setup from pt_pwm_init()
- Motor_act() direction and duty mapping
- Incremental motor PID from pid_leg.c
- A lightweight plant model for encoder speed and yaw dynamics

The goal is not physical accuracy; it is control-loop validation on PC.
"""

from __future__ import annotations

import argparse
import csv
import math
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, List


PWM_CH1 = "PWM_CH1"
PWM_CH2 = "PWM_CH2"
PWM_CH3 = "PWM_CH3"

MOTOR_MAX_PWM = 7000
DEFAULT_AIM_SPEED = 60.0
DEFAULT_DT = 0.01


@dataclass
class IncrementalPID:
    kp: float
    ki: float
    kd: float
    set_value: float = 0.0
    err_last1: float = 0.0
    err_last2: float = 0.0
    control_value: float = 0.0

    def reset(self) -> None:
        self.set_value = 0.0
        self.err_last1 = 0.0
        self.err_last2 = 0.0
        self.control_value = 0.0

    def update(self, actual_value: float, set_value: float) -> float:
        self.set_value = set_value
        err = self.set_value - actual_value
        increase = (
            self.kp * (err - self.err_last1)
            + self.ki * err
            + self.kd * (err - 2.0 * self.err_last1 + self.err_last2)
        )
        self.control_value += increase
        self.err_last2 = self.err_last1
        self.err_last1 = err
        return self.control_value


@dataclass
class PwmChannelState:
    name: str
    frequency_hz: int
    duty_raw: float


@dataclass
class MotorState:
    left_dir: int = 1
    right_dir: int = 0
    left_pwm_abs: float = 0.0
    right_pwm_abs: float = 0.0


class E05PwmVirtualEnv:
    def __init__(self, dt: float, aim_speed: float) -> None:
        self.dt = dt
        self.time_s = 0.0
        self.aim_speed = aim_speed

        self.pwm_channels: Dict[str, PwmChannelState] = {}
        self.motor = MotorState()

        self.left_pid = IncrementalPID(kp=16.0, ki=1.95, kd=0.0)
        self.right_pid = IncrementalPID(kp=16.0, ki=1.95, kd=0.0)

        self.left_speed = 0.0
        self.right_speed = 0.0
        self.yaw = 0.0
        self.yaw_rate = 0.0

        self._pt_pwm_init()

    def _pt_pwm_init(self) -> None:
        self.pwm_channels[PWM_CH1] = PwmChannelState(PWM_CH1, 170000, 0.0)
        self.pwm_channels[PWM_CH2] = PwmChannelState(PWM_CH2, 170000, 0.0)
        self.pwm_channels[PWM_CH3] = PwmChannelState(PWM_CH3, 170000, 0.0)

    @staticmethod
    def _motor_duty_limit(duty: float) -> float:
        if duty > MOTOR_MAX_PWM:
            return MOTOR_MAX_PWM
        if duty < -MOTOR_MAX_PWM:
            return -MOTOR_MAX_PWM
        return duty

    def _pwm_set_duty(self, channel: str, duty: float) -> None:
        self.pwm_channels[channel].duty_raw = max(0.0, min(10000.0, duty))

    def motor_act(self, leftmotor_duty: float, rightmotor_duty: float) -> None:
        leftmotor_duty = self._motor_duty_limit(leftmotor_duty)
        rightmotor_duty = self._motor_duty_limit(rightmotor_duty)

        if leftmotor_duty >= 0:
            self.motor.left_dir = 1
            self.motor.left_pwm_abs = leftmotor_duty
            self._pwm_set_duty(PWM_CH1, leftmotor_duty)
        else:
            self.motor.left_dir = 0
            self.motor.left_pwm_abs = -leftmotor_duty
            self._pwm_set_duty(PWM_CH1, -leftmotor_duty)

        if rightmotor_duty >= 0:
            self.motor.right_dir = 0
            self.motor.right_pwm_abs = rightmotor_duty
            self._pwm_set_duty(PWM_CH2, rightmotor_duty)
        else:
            self.motor.right_dir = 1
            self.motor.right_pwm_abs = -rightmotor_duty
            self._pwm_set_duty(PWM_CH2, -rightmotor_duty)

    @staticmethod
    def _pid_steering(expect_angle: float, angle: float, kp: float = 50.0) -> float:
        return kp * (expect_angle - angle)

    def _duty_to_signed(self, pwm_abs: float, direction: int, left_motor: bool) -> float:
        # Direction wiring follows Motor_act() in pwm.c.
        if left_motor:
            sign = 1.0 if direction == 1 else -1.0
        else:
            sign = 1.0 if direction == 0 else -1.0
        return sign * pwm_abs

    def _plant_step(self) -> None:
        left_signed = self._duty_to_signed(self.motor.left_pwm_abs, self.motor.left_dir, left_motor=True)
        right_signed = self._duty_to_signed(self.motor.right_pwm_abs, self.motor.right_dir, left_motor=False)

        duty_scale = 0.020
        left_target_speed = left_signed * duty_scale
        right_target_speed = right_signed * duty_scale

        speed_tau = 0.18
        alpha = min(1.0, self.dt / speed_tau)
        self.left_speed += alpha * (left_target_speed - self.left_speed)
        self.right_speed += alpha * (right_target_speed - self.right_speed)

        yaw_gain = 0.020
        yaw_tau = 0.10
        yaw_rate_target = (self.right_speed - self.left_speed) * yaw_gain
        yaw_alpha = min(1.0, self.dt / yaw_tau)
        self.yaw_rate += yaw_alpha * (yaw_rate_target - self.yaw_rate)
        self.yaw += self.yaw_rate * self.dt

    def step_track_line(self, direction: int = 1) -> Dict[str, float]:
        expect = 3.0 if direction == 1 else -3.0
        steering = self._pid_steering(expect_angle=expect, angle=self.yaw, kp=50.0)

        left_set = self.aim_speed + steering
        right_set = self.aim_speed - steering

        left_cmd = self.left_pid.update(actual_value=self.left_speed, set_value=left_set)
        right_cmd = self.right_pid.update(actual_value=self.right_speed, set_value=right_set)

        self.motor_act(left_cmd, right_cmd)
        self._plant_step()
        self.time_s += self.dt

        return {
            "time_s": self.time_s,
            "left_speed": self.left_speed,
            "right_speed": self.right_speed,
            "yaw": self.yaw,
            "left_cmd": left_cmd,
            "right_cmd": right_cmd,
            "left_pwm": self.motor.left_pwm_abs,
            "right_pwm": self.motor.right_pwm_abs,
            "left_dir": float(self.motor.left_dir),
            "right_dir": float(self.motor.right_dir),
        }

    def step_corner(self, error_turn: float) -> Dict[str, float]:
        pid_error_speed = 80.0 * (0.0 - error_turn)
        gyro_out = 0.9 * pid_error_speed - 15.0 * self.yaw_rate

        left_set = self.aim_speed - gyro_out
        right_set = self.aim_speed + gyro_out

        left_cmd = -self.left_pid.update(actual_value=self.left_speed, set_value=left_set)
        right_cmd = self.right_pid.update(actual_value=self.right_speed, set_value=right_set)

        self.motor_act(left_cmd, right_cmd)
        self._plant_step()
        self.time_s += self.dt

        return {
            "time_s": self.time_s,
            "left_speed": self.left_speed,
            "right_speed": self.right_speed,
            "yaw": self.yaw,
            "left_cmd": left_cmd,
            "right_cmd": right_cmd,
            "left_pwm": self.motor.left_pwm_abs,
            "right_pwm": self.motor.right_pwm_abs,
            "left_dir": float(self.motor.left_dir),
            "right_dir": float(self.motor.right_dir),
            "error_turn": error_turn,
        }


def run_simulation(mode: str, duration_s: float, dt: float, aim_speed: float, direction: int) -> List[Dict[str, float]]:
    env = E05PwmVirtualEnv(dt=dt, aim_speed=aim_speed)
    steps = max(1, int(duration_s / dt))

    trace: List[Dict[str, float]] = []
    for i in range(steps):
        if mode == "track":
            row = env.step_track_line(direction=direction)
        else:
            # Deterministic synthetic Error_Turn input.
            error_turn = 2.8 * math.sin(2.0 * math.pi * 0.35 * i * dt)
            row = env.step_corner(error_turn=error_turn)
        trace.append(row)
    return trace


def write_csv(path: Path, rows: List[Dict[str, float]]) -> None:
    if not rows:
        return
    keys = list(rows[0].keys())
    with path.open("w", newline="", encoding="utf-8") as fp:
        writer = csv.DictWriter(fp, fieldnames=keys)
        writer.writeheader()
        writer.writerows(rows)


def summarize(rows: List[Dict[str, float]]) -> str:
    left_pwm_avg = sum(r["left_pwm"] for r in rows) / len(rows)
    right_pwm_avg = sum(r["right_pwm"] for r in rows) / len(rows)
    yaw_end = rows[-1]["yaw"]
    left_speed_end = rows[-1]["left_speed"]
    right_speed_end = rows[-1]["right_speed"]
    return (
        f"samples={len(rows)} | "
        f"left_pwm_avg={left_pwm_avg:.1f} | right_pwm_avg={right_pwm_avg:.1f} | "
        f"left_speed_end={left_speed_end:.2f} | right_speed_end={right_speed_end:.2f} | yaw_end={yaw_end:.3f}"
    )


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="E05 PWM virtual environment simulator")
    parser.add_argument("--mode", choices=["track", "corner"], default="track", help="Control mode to simulate")
    parser.add_argument("--duration", type=float, default=8.0, help="Simulation duration in seconds")
    parser.add_argument("--dt", type=float, default=DEFAULT_DT, help="Time step in seconds")
    parser.add_argument("--aim-speed", type=float, default=DEFAULT_AIM_SPEED, help="Aim speed equivalent to firmware aim_speed")
    parser.add_argument("--direction", type=int, choices=[1, 2], default=1, help="Track direction: 1=CCW, 2=CW")
    parser.add_argument("--csv", type=Path, default=Path("tools/e05_pwm_virtual_env/sim_trace.csv"), help="Output CSV path")
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    rows = run_simulation(
        mode=args.mode,
        duration_s=args.duration,
        dt=args.dt,
        aim_speed=args.aim_speed,
        direction=args.direction,
    )
    args.csv.parent.mkdir(parents=True, exist_ok=True)
    write_csv(args.csv, rows)
    print("E05 PWM virtual simulation finished")
    print(summarize(rows))
    print(f"trace_csv={args.csv}")


if __name__ == "__main__":
    main()
