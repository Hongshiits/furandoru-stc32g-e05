# E05 PWM Virtual Environment

This folder provides a PC-side simulation for `firmware/E05_pwm_demo`.

## What is simulated

- `pt_pwm_init()` channel configuration
- `Motor_act()` direction + PWM absolute duty behavior
- Incremental motor PID logic from `pid_leg.c`
- A lightweight virtual plant for left/right encoder speed and yaw

The simulator is for algorithm validation and tuning trend checks. It is not intended to replace real hardware calibration.

## Run

From repository root:

```powershell
python tools/e05_pwm_virtual_env/e05_pwm_virtual_env.py --mode track --duration 8 --dt 0.01 --aim-speed 60 --direction 1
```

Corner-like mode:

```powershell
python tools/e05_pwm_virtual_env/e05_pwm_virtual_env.py --mode corner --duration 8
```

## Output

- Console summary with average PWM and final speeds/yaw
- CSV trace file (default): `tools/e05_pwm_virtual_env/sim_trace.csv`

You can change CSV output path:

```powershell
python tools/e05_pwm_virtual_env/e05_pwm_virtual_env.py --csv tools/e05_pwm_virtual_env/my_trace.csv
```

## Main parameters

- `--mode`: `track` or `corner`
- `--duration`: total simulation time in seconds
- `--dt`: simulation step period in seconds
- `--aim-speed`: equivalent to firmware `aim_speed`
- `--direction`: 1 (counterclockwise) or 2 (clockwise)

## Graph Simulation Application (Wire Signal Following)

The file `tools/e05_pwm_virtual_env/e05_wire_graph_app.py` is a graphical app for the E05 car scenario:

- A curved virtual wire radiates signal into air
- The car captures signal strength through 5 virtual sensors (`LV/LH/MD/RH/RV`)
- Steering uses an `Error_Turn` style formula similar to `isr_leg.c`
- Live graphs show ADC strength, error/yaw rate, and left/right PWM

Run GUI:

```powershell
python tools/e05_pwm_virtual_env/e05_wire_graph_app.py
```

Run headless quick check:

```powershell
python tools/e05_pwm_virtual_env/e05_wire_graph_app.py --headless-steps 300
```
