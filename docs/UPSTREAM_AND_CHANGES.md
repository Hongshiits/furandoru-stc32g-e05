# 来源与整理记录

## 整理来源

- 本地工作副本：`STC32G144K246_100Pin_Library-master`
- 工作副本远端：<https://github.com/Hongshiits/iot-furan-STC32G144K246_100Pin_Library>
- 整理基准分支：`main`
- 整理基准提交：`cc3cec59f05caa365820f97e2efc7dc2046953d1`
- 主要工程：`Example/Coreboard_Demo/E05_pwm_demo`

新仓库的固件部分采用源码快照，不复制旧库中与 E05 无关的大量示例和软件安装包。上面的提交哈希用于追溯固件整理时的来源状态；后来加入的上级目录硬件与机械资料使用独立导入清单追溯。

## 基准提交之后的工作区修改

整理时，以下 21 个受版本控制的源文件相对基准提交存在未提交修改；新仓库收录的是这些文件的当前工作区版本。

应用层（18 个）：

- `firmware/E05_pwm_demo/user/adc.c`
- `firmware/E05_pwm_demo/user/adc.h`
- `firmware/E05_pwm_demo/user/algorithm.c`
- `firmware/E05_pwm_demo/user/eeprom.c`
- `firmware/E05_pwm_demo/user/eeprom.h`
- `firmware/E05_pwm_demo/user/encoder.c`
- `firmware/E05_pwm_demo/user/fsm_leg.c`
- `firmware/E05_pwm_demo/user/fsm_leg.h`
- `firmware/E05_pwm_demo/user/gpio.c`
- `firmware/E05_pwm_demo/user/hornshell.c`
- `firmware/E05_pwm_demo/user/imu.c`
- `firmware/E05_pwm_demo/user/isr_leg.c`
- `firmware/E05_pwm_demo/user/isr_leg.h`
- `firmware/E05_pwm_demo/user/main.c`
- `firmware/E05_pwm_demo/user/pit.c`
- `firmware/E05_pwm_demo/user/pt_headfile.c`
- `firmware/E05_pwm_demo/user/pwm.c`
- `firmware/E05_pwm_demo/user/pwm.h`

库层（3 个）：

- `firmware/libraries/zf_common/zf_common_function.c`
- `firmware/libraries/zf_common/zf_common_function.h`
- `firmware/libraries/zf_device/zf_device_imu660ra.c`

相对基准提交，这组修改合计约 `860` 行新增、`319` 行删除。基准提交本身也已经包含 Furandoru 项目的早期定制历史，因此不能将其视为逐飞官方原版。

## 整理规则

保留：

- `E05_pwm_demo/user` 中的实际应用源码
- Keil 工程文件及工程直接引用的 `Coreboard_Demo/libraries`
- 工程要求的二进制 `.LIB` 组件
- `tools/e05_pwm_virtual_env` 中的 PC 仿真脚本
- 上级工作目录中通过公开安全审计的 EDA 导出、制造文件和 3D/机械模型
- GPLv3 许可证和原文件中的版权声明

移除：

- `mdk/out_file` 编译产物、列表、日志和中间文件
- `.venv`、`__pycache__` 和仿真生成的 CSV
- `.uvgui.*`、`.uvopt*`、Keil Assistant 日志等个人状态
- 与 E05 无关的示例和上位机软件
- E05 根目录下未被工程引用且早于 `user/` 版本的 `main.c`、`fsm_leg.c` 备份
- 含本地凭据的 `.eprj*`、含 Keil 许可证码的构建日志/聚合包、锁文件和超大扫描参考图

## 许可证与署名

逐飞库源文件声明其按 GPLv3（或后续版本）授权，并要求保留成都逐飞科技有限公司的版权声明。本仓库保留相关源文件头和根目录 `LICENSE`；后续修改也应继续遵守兼容的 GPL 条款。

工程还包含授权尚未在源目录中明确的 Keil/STC 文件、两个预编译 `.LIB` 以及部分硬件/机械资产。这些文件为保持当前工程与维护者指定的公开快照而保留，但公开可见不等于授权已统一确认；具体路径和处理建议见根目录 `THIRD_PARTY_NOTICES.md`。

## 2026-08-24 硬件与机械资料导入

导入来源为同一项目上级目录的 `hw/` 与 `model/`。共盘点 320 个源文件；每个文件的原路径、修改时间、源 SHA-256、发布路径、发布 SHA-256、去重和排除原因均记录在 `docs/ASSET_IMPORT_MAP.csv`，统计摘要见 `docs/ASSET_IMPORT_SUMMARY.md`。

同名不同内容的独立工程/导出使用 `__YYYYMMDD-HHMMSS` 后缀；字节完全相同的副本通常只保留一份。N30 主板支架 DXF 是唯一跨上下文例外，以同时保持硬件接口入口和完整第三方快照。SolidWorks 装配体和其依赖零件不直接改名，并保持同目录。公开安全审计发现原始立创 EDA 本地数据库含凭据字段、MUX 构建日志含 Keil 许可证码，因此这些原件和夹带它们的聚合包未发布。
