# Furandoru STC32G E05

基于逐飞科技 `STC32G144K246 100Pin` 开源库和 Coreboard `E05_pwm_demo` 整理的循迹车固件。仓库保留了 E05 的实际工程代码、它引用的完整 Coreboard 库，以及用于控制算法快速验证的 PC 端仿真工具。

## 功能概览

- 五路 ADC 循迹信号采集与归一化（`LV / LH / MD / RH / RV`）
- 左右轮编码器反馈、PWM 电机驱动和增量式速度 PID
- IMU660RA 默认支持，可通过源码宏切换 IMU660RB
- 直线、弯道、十字和环岛等状态处理
- 串口 Horn Shell 参数调试，以及仍处于实验状态的 EEPROM 参数读写
- 双电机与虚拟导线循迹的纯 Python 仿真

> 这是竞赛/实验固件快照。首次上车前请核对引脚、电机方向、传感器量程和 PID 参数，并先架空车轮测试。

> 本仓库不是逐飞科技官方仓库。当前整理版本应保持为私有仓库：工程内含 Keil/STC 文件和两个预编译 `.LIB`，这些第三方组件的公开再分发条款尚未在原目录中找到。详见 [`THIRD_PARTY_NOTICES.md`](THIRD_PARTY_NOTICES.md)。

## 目录

```text
firmware/
├── E05_pwm_demo/
│   ├── code/       # Keil 工程保留的用户代码目录
│   ├── mdk/        # Keil C251 工程
│   └── user/       # Furandoru 应用代码
└── libraries/      # E05 工程引用的逐飞 Coreboard 库（含本项目修改）
tools/
└── e05_pwm_virtual_env/  # PC 端控制算法与导线循迹仿真
scripts/
└── verify_project.py     # 工程相对路径与发布内容检查
docs/
└── UPSTREAM_AND_CHANGES.md
```

## 构建固件

1. 安装支持 C251 的 Keil MDK 工具链和对应设备支持包。
2. 打开 [`firmware/E05_pwm_demo/mdk/seekfree.uvproj`](firmware/E05_pwm_demo/mdk/seekfree.uvproj)。
3. 确认目标设备为 `AI8052U-32Bit Series`，然后执行 Build。
4. 默认输出目录为 `firmware/E05_pwm_demo/mdk/out_file/`，输出名为 `SEEKFREE`。

工程使用相对路径 `../../libraries`，从仓库克隆后无需手工重连库文件。当前整理环境没有安装 Keil/C251，因此发布前完成的是工程引用完整性检查和 PC 仿真检查，而不是目标固件的实际编译。

## 关键配置入口

- ADC 通道：`firmware/E05_pwm_demo/user/adc.h`
- PWM、电机限幅与死区：`firmware/E05_pwm_demo/user/pwm.h`
- 编码器接口：`firmware/E05_pwm_demo/user/encoder.h`
- IMU 型号切换：`firmware/E05_pwm_demo/user/imu.h`
- 控制器初始参数：`firmware/E05_pwm_demo/user/algorithm.c`
- 赛道状态与阈值：`firmware/E05_pwm_demo/user/fsm_leg.c`

`user/ekf.*`、`user/gyro.*` 和 `user/matrix.*` 是当前保留的实验模块，尚未列入 `seekfree.uvproj` 的编译文件组。

当前源码中的主要默认连接如下：

| 功能 | 默认接口 |
| --- | --- |
| 五路循迹 ADC | `P06 / P03 / P02 / P01 / P00` |
| 电池电压 ADC | `P10` |
| 三路 PWM | `P74 / P24 / P70` |
| 电机方向 | `P35 / P36 / P37` |
| 左右编码器 | `P60/P62`、`P40/P42` |
| 调试串口 | UART5，`P05/P04`，115200 baud |
| 默认 IMU | IMU660RA；在 `imu.h` 中启用宏可切换 IMU660RB |
| 系统时钟 | 96 MHz |

EEPROM 相关源码仍带有“存在问题”的开发注释，应视为实验功能，在真机验证前不要依赖其保存关键参数。

## PC 仿真

工具仅依赖 Python 标准库；图形界面还需要 Python 自带的 Tk 支持。

```powershell
python tools/e05_pwm_virtual_env/e05_pwm_virtual_env.py --mode track --duration 8 --dt 0.01 --aim-speed 60 --direction 1
python tools/e05_pwm_virtual_env/e05_wire_graph_app.py --headless-steps 300
```

运行图形界面：

```powershell
python tools/e05_pwm_virtual_env/e05_wire_graph_app.py
```

## 发布前自检

```powershell
python scripts/verify_project.py
```

脚本会验证 Keil 工程中的源文件和包含目录是否都能在仓库内解析，并检查常见生成物是否被误收录。

## 来源与许可证

本项目基于逐飞科技 STC32G144K 开源库，原文件版权声明均予以保留。整理基准、工作区修改范围和删减规则见 [`docs/UPSTREAM_AND_CHANGES.md`](docs/UPSTREAM_AND_CHANGES.md)。部分上游 C/汇编文件保留原始 GBK 或混合编码；整理过程没有批量转码，以免改变编译输入。

逐飞来源文件继续遵循其文件头声明的 GPLv3 或后续版本，项目自有修改也拟按 GPL-3.0-or-later 发布。根目录 [LICENSE](LICENSE) 收录 GPLv3 全文。Keil、STC 和预编译库等第三方组件分别遵循其权利人的条款；在相关授权确认或组件替换完成前，请勿将整个仓库公开发布。
