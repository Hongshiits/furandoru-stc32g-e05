#!/usr/bin/env python3
"""Graph simulation application for E05 wire-signal following car.

The E05 project follows electromagnetic wire signal strength. This app simulates:
- A virtual wire signal field in 2D
- Five front sensors (LV/LH/MD/RH/RV)
- Error_Turn style signal-difference steering logic from isr_leg.c
- Differential-drive car movement with live graphs

Run GUI:
    python tools/e05_pwm_virtual_env/e05_wire_graph_app.py

Run headless smoke test:
    python tools/e05_pwm_virtual_env/e05_wire_graph_app.py --headless-steps 300
"""

from __future__ import annotations

import argparse
import math
from collections import deque
from dataclasses import dataclass
from typing import Deque, Dict, List, Tuple


def clamp(value: float, low: float, high: float) -> float:
    return max(low, min(high, value))


@dataclass
class CarState:
    x: float = 0.0
    y: float = 0.30
    heading: float = 0.0
    left_speed: float = 0.0
    right_speed: float = 0.0


class WireField:
    """Signal source along a curved wire centerline."""

    def y_of_x(self, x: float) -> float:
        return 0.40 * math.sin(0.20 * x) + 0.12 * math.sin(0.65 * x)

    def nearest_distance(self, x: float, y: float) -> float:
        # Local search around x to approximate nearest distance to the wire.
        span = 2.0
        step = 0.03
        best = 1e9
        px = x - span
        while px <= x + span:
            py = self.y_of_x(px)
            d = math.hypot(x - px, y - py)
            if d < best:
                best = d
            px += step
        return best

    def signal_strength(self, x: float, y: float) -> float:
        dist = self.nearest_distance(x, y)
        sigma = 0.18
        strength = 180.0 * math.exp(-((dist / sigma) ** 2))
        return clamp(strength, 0.0, 180.0)


class E05WireFollowerSim:
    """Lightweight vehicle + control simulation aligned with E05 ideas."""

    def __init__(self, dt: float = 0.02) -> None:
        self.dt = dt
        self.time_s = 0.0
        self.field = WireField()
        self.car = CarState()

        # These follow naming style from isr_leg.c.
        self.turn_A = 3.5
        self.turn_B = 11.0
        self.turn_C = 3.5
        self.lim_turn = 3.0

        self.aim_speed = 0.85
        self.wheel_base = 0.28
        self.sensor_forward = 0.19

        # Sensor lateral offsets for LV/LH/MD/RH/RV.
        self.sensor_offsets = {
            "LV": -0.18,
            "LH": -0.09,
            "MD": 0.0,
            "RH": 0.09,
            "RV": 0.18,
        }

        self.last_error_turn = 0.0
        self.last_yaw_rate = 0.0
        self.left_pwm = 0.0
        self.right_pwm = 0.0

    def _sensor_world_xy(self, lateral: float) -> Tuple[float, float]:
        # Sensor strip is in front of the car and spread laterally.
        cx, cy, th = self.car.x, self.car.y, self.car.heading
        sx = cx + self.sensor_forward * math.cos(th) - lateral * math.sin(th)
        sy = cy + self.sensor_forward * math.sin(th) + lateral * math.cos(th)
        return sx, sy

    def read_sensors(self) -> Dict[str, float]:
        values: Dict[str, float] = {}
        for name, lat in self.sensor_offsets.items():
            sx, sy = self._sensor_world_xy(lat)
            values[name] = self.field.signal_strength(sx, sy)
        return values

    def calc_error_turn(self, s: Dict[str, float]) -> float:
        lv, lh, rh, rv = s["LV"], s["LH"], s["RH"], s["RV"]
        numerator = (self.turn_A / 10.0) * (lv - rv) + (self.turn_B / 10.0) * (lh - rh)
        denominator = (self.turn_A / 10.0) * (lv + rv) + (self.turn_C / 10.0) * abs(lh - rh)
        denominator = max(denominator, 1e-4)
        return (numerator / denominator) * self.lim_turn

    def _speed_to_pwm(self, wheel_speed: float) -> float:
        # Map wheel speed to a PWM-like number similar to firmware scale.
        return clamp(abs(wheel_speed) * 5200.0, 0.0, 7000.0)

    def step(self) -> Dict[str, float]:
        sensors = self.read_sensors()
        error_turn = self.calc_error_turn(sensors)

        # Steering from signal difference (similar idea to Error_Turn correction).
        omega_target = clamp(-1.35 * error_turn, -2.2, 2.2)

        # Use middle sensor as confidence: weak signal -> slow down.
        md_ratio = sensors["MD"] / 180.0
        speed_target = 0.45 + self.aim_speed * md_ratio

        # Convert target v, omega to wheel speeds.
        left_target = speed_target - 0.5 * self.wheel_base * omega_target
        right_target = speed_target + 0.5 * self.wheel_base * omega_target

        # First-order motor response.
        tau = 0.16
        alpha = min(1.0, self.dt / tau)
        self.car.left_speed += alpha * (left_target - self.car.left_speed)
        self.car.right_speed += alpha * (right_target - self.car.right_speed)

        v = 0.5 * (self.car.left_speed + self.car.right_speed)
        yaw_rate = (self.car.right_speed - self.car.left_speed) / self.wheel_base

        self.car.heading += yaw_rate * self.dt
        self.car.x += v * math.cos(self.car.heading) * self.dt
        self.car.y += v * math.sin(self.car.heading) * self.dt

        self.left_pwm = self._speed_to_pwm(self.car.left_speed)
        self.right_pwm = self._speed_to_pwm(self.car.right_speed)
        self.last_error_turn = error_turn
        self.last_yaw_rate = yaw_rate
        self.time_s += self.dt

        return {
            "time_s": self.time_s,
            "x": self.car.x,
            "y": self.car.y,
            "heading": self.car.heading,
            "left_speed": self.car.left_speed,
            "right_speed": self.car.right_speed,
            "yaw_rate": yaw_rate,
            "error_turn": error_turn,
            "adc_lv": sensors["LV"],
            "adc_lh": sensors["LH"],
            "adc_md": sensors["MD"],
            "adc_rh": sensors["RH"],
            "adc_rv": sensors["RV"],
            "left_pwm": self.left_pwm,
            "right_pwm": self.right_pwm,
        }


class GraphApp:
    def __init__(self, dt: float = 0.02) -> None:
        import tkinter as tk

        self.tk = tk
        self.root = tk.Tk()
        self.root.title("E05 Wire Signal Graph Simulation")
        self.root.geometry("1260x760")
        self.root.configure(bg="#11161b")

        self.sim = E05WireFollowerSim(dt=dt)
        self.running = True

        self.scene = tk.Canvas(self.root, width=820, height=720, bg="#0d1117", highlightthickness=0)
        self.scene.pack(side=tk.LEFT, padx=12, pady=12)

        right = tk.Frame(self.root, bg="#11161b")
        right.pack(side=tk.RIGHT, fill=tk.BOTH, expand=True, padx=8, pady=12)

        self.info = tk.Label(
            right,
            text="",
            justify=tk.LEFT,
            anchor="nw",
            bg="#11161b",
            fg="#d7e3f4",
            font=("Consolas", 10),
        )
        self.info.pack(fill=tk.X, pady=(0, 8))

        self.plot = tk.Canvas(right, width=390, height=620, bg="#0f141a", highlightthickness=0)
        self.plot.pack(fill=tk.BOTH, expand=True)

        btn_row = tk.Frame(right, bg="#11161b")
        btn_row.pack(fill=tk.X, pady=(8, 0))

        tk.Button(btn_row, text="Pause/Run", command=self.toggle, bg="#2f81f7", fg="white", bd=0, padx=12, pady=6).pack(side=tk.LEFT)
        tk.Button(btn_row, text="Reset", command=self.reset, bg="#3d444d", fg="white", bd=0, padx=12, pady=6).pack(side=tk.LEFT, padx=8)

        self.history: Deque[Dict[str, float]] = deque(maxlen=300)

    def toggle(self) -> None:
        self.running = not self.running

    def reset(self) -> None:
        dt = self.sim.dt
        self.sim = E05WireFollowerSim(dt=dt)
        self.history.clear()

    def world_to_scene(self, x: float, y: float) -> Tuple[float, float]:
        sx = 120.0 + x * 80.0
        sy = 360.0 - y * 80.0
        return sx, sy

    def _draw_scene(self) -> None:
        c = self.scene
        c.delete("all")

        # Grid lines for spatial context.
        for i in range(0, 821, 40):
            c.create_line(i, 0, i, 720, fill="#1b2430")
        for j in range(0, 721, 40):
            c.create_line(0, j, 820, j, fill="#1b2430")

        # Wire path around car.
        x0 = self.sim.car.x - 1.5
        x1 = self.sim.car.x + 8.0
        pts: List[float] = []
        x = x0
        while x <= x1:
            y = self.sim.field.y_of_x(x)
            sx, sy = self.world_to_scene(x, y)
            pts.extend([sx, sy])
            x += 0.04
        if len(pts) >= 4:
            c.create_line(*pts, fill="#ffd166", width=3, smooth=True)

        # Car body as a triangle.
        car = self.sim.car
        th = car.heading
        nose = (car.x + 0.20 * math.cos(th), car.y + 0.20 * math.sin(th))
        left = (car.x - 0.14 * math.cos(th) - 0.11 * math.sin(th), car.y - 0.14 * math.sin(th) + 0.11 * math.cos(th))
        right = (car.x - 0.14 * math.cos(th) + 0.11 * math.sin(th), car.y - 0.14 * math.sin(th) - 0.11 * math.cos(th))
        n = self.world_to_scene(*nose)
        l = self.world_to_scene(*left)
        r = self.world_to_scene(*right)
        c.create_polygon([n[0], n[1], l[0], l[1], r[0], r[1]], fill="#58a6ff", outline="#c9d1d9", width=2)

        # Sensor points with signal-based color.
        for name, lat in self.sim.sensor_offsets.items():
            sx_w, sy_w = self.sim._sensor_world_xy(lat)
            sx, sy = self.world_to_scene(sx_w, sy_w)
            strength = self.sim.field.signal_strength(sx_w, sy_w)
            red = int(clamp(strength / 180.0 * 255.0, 0, 255))
            blue = 255 - red
            color = f"#{red:02x}55{blue:02x}"
            c.create_oval(sx - 6, sy - 6, sx + 6, sy + 6, fill=color, outline="#e6edf3")
            c.create_text(sx, sy - 11, text=name, fill="#c9d1d9", font=("Consolas", 8))

        c.create_text(12, 14, text="Wire Field + Car Pose", anchor="nw", fill="#c9d1d9", font=("Consolas", 12, "bold"))

    def _draw_plot_panel(self) -> None:
        p = self.plot
        p.delete("all")

        p.create_text(10, 8, text="Live Graphs", anchor="nw", fill="#d7e3f4", font=("Consolas", 11, "bold"))

        self._draw_series(
            top=30,
            height=170,
            title="Signal Strength (ADC)",
            y_min=0.0,
            y_max=180.0,
            series=[("adc_lh", "#ff7b72"), ("adc_md", "#3fb950"), ("adc_rh", "#79c0ff")],
        )
        self._draw_series(
            top=230,
            height=170,
            title="Error_Turn / YawRate",
            y_min=-4.0,
            y_max=4.0,
            series=[("error_turn", "#ffa657"), ("yaw_rate", "#d2a8ff")],
        )
        self._draw_series(
            top=430,
            height=170,
            title="PWM Left/Right",
            y_min=0.0,
            y_max=7000.0,
            series=[("left_pwm", "#58a6ff"), ("right_pwm", "#f2cc60")],
        )

    def _draw_series(self, top: int, height: int, title: str, y_min: float, y_max: float, series: List[Tuple[str, str]]) -> None:
        p = self.plot
        left = 10
        right = 380
        bottom = top + height
        p.create_rectangle(left, top, right, bottom, outline="#30363d", width=1)
        p.create_text(left + 6, top + 6, text=title, anchor="nw", fill="#c9d1d9", font=("Consolas", 9, "bold"))

        rows = list(self.history)
        if len(rows) < 2:
            return

        n = len(rows)
        for key, color in series:
            pts: List[float] = []
            for i, row in enumerate(rows):
                x = left + i * (right - left) / (n - 1)
                v = row[key]
                y_norm = (v - y_min) / (y_max - y_min)
                y_norm = clamp(y_norm, 0.0, 1.0)
                y = bottom - y_norm * (height - 18)
                pts.extend([x, y])
            if len(pts) >= 4:
                p.create_line(*pts, fill=color, width=2)

        # Legend
        lx = right - 130
        ly = top + 8
        for key, color in series:
            p.create_line(lx, ly + 6, lx + 16, ly + 6, fill=color, width=3)
            p.create_text(lx + 22, ly + 6, text=key, anchor="w", fill="#8b949e", font=("Consolas", 8))
            ly += 14

    def _update_info(self, row: Dict[str, float]) -> None:
        text = (
            f"t={row['time_s']:.2f}s\n"
            f"pose: x={row['x']:.2f} y={row['y']:.2f} heading={row['heading']:.2f} rad\n"
            f"speed: L={row['left_speed']:.2f} R={row['right_speed']:.2f} m/s\n"
            f"adc: LV={row['adc_lv']:.1f} LH={row['adc_lh']:.1f} MD={row['adc_md']:.1f} RH={row['adc_rh']:.1f} RV={row['adc_rv']:.1f}\n"
            f"error_turn={row['error_turn']:.3f} yaw_rate={row['yaw_rate']:.3f}\n"
            f"pwm: left={row['left_pwm']:.0f} right={row['right_pwm']:.0f}"
        )
        self.info.configure(text=text)

    def tick(self) -> None:
        if self.running:
            row = self.sim.step()
            self.history.append(row)
            self._update_info(row)
        self._draw_scene()
        self._draw_plot_panel()
        self.root.after(int(self.sim.dt * 1000), self.tick)

    def run(self) -> None:
        self.tick()
        self.root.mainloop()


def run_headless(steps: int, dt: float) -> None:
    sim = E05WireFollowerSim(dt=dt)
    row: Dict[str, float] = {}
    for _ in range(steps):
        row = sim.step()
    print("E05 wire graph simulation headless run finished")
    print(
        f"steps={steps} t={row['time_s']:.2f}s x={row['x']:.2f} y={row['y']:.2f} "
        f"adc_md={row['adc_md']:.1f} error_turn={row['error_turn']:.3f} "
        f"pwm_l={row['left_pwm']:.0f} pwm_r={row['right_pwm']:.0f}"
    )


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="E05 wire signal graph simulation application")
    parser.add_argument("--dt", type=float, default=0.02, help="Simulation step in seconds")
    parser.add_argument("--headless-steps", type=int, default=0, help="Run without GUI for N steps")
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    if args.headless_steps > 0:
        run_headless(args.headless_steps, args.dt)
        return

    app = GraphApp(dt=args.dt)
    app.run()


if __name__ == "__main__":
    main()
