# 第三方组件与公开仓库说明

本仓库当前为公开仓库。本文件记录整理时能从源文件直接确认的许可证，以及仍未在源目录中找到独立再分发条款的组件。公开可见不等于这些组件统一改授仓库根目录的 GPL，也不替代权利人的正式许可。

## 逐飞 STC32G144K 固件库

`firmware/libraries` 和 E05 示例的大部分源文件包含成都逐飞科技有限公司的版权声明，并声明按 GPLv3 或后续版本授权。仓库根目录 `LICENSE` 保留了源工作副本提供的 GPLv3 全文；原文件头不得删除。

源文件头提到的 `libraries/doc/GPL3_permission_statement.txt` 和 `libraries/LICENSE` 在被整理的源工作副本中并不存在，只有仓库根目录 `LICENSE`。这里记录该不一致，不伪造缺失的上游文件。

## SeekFree Lightweight Car Chassis

`mechanical/third-party/lightweight-car-chassis/` 对应 SeekFree 的 Lightweight Car Chassis 项目，保留了上游 `LICENSE`、`README.md`、`README.en.md` 和原目录结构。该快照随附 GNU GPL v3；本地新增或派生的 `电磁支架底座.*`、DWG/DXF/SLDDRW 等文件按兼容方式公开，并由导入清单记录原修改时间。

上游来源：<https://gitee.com/seekfree/Lightweight_Car_Chassis>

## Keil、STC 与预编译库

以下固件构建依赖随源工作副本没有附带可单独确认的再分发条款：

- `firmware/libraries/zf_common/START251.A51`（Keil 版权声明）
- `firmware/libraries/zf_common/stc32g144k246.h`
- `firmware/libraries/zf_common/ai_usb.h`
- `firmware/libraries/zf_components/stc32g_usb_lib/`
- `firmware/libraries/zf_device/zf_device_config.LIB`
- `firmware/libraries/zf_device/zf_device_mt9v03x_dma.LIB`

它们为保持当前 Keil/C251 工程完整性而保留。维护者将仓库设为公开并不构成对其授权状态的保证；下游应核实 Keil、STC 或对应权利人的许可，或在分发前以已安装工具链/许可明确实现替换。

## 电路硬件资料

`hardware/` 中的 EDA 导出、制造文件和机械接口来自项目工作目录。以下类别在源目录中没有找到独立许可证，不能推定均适用根目录 GPL：

- 部分参考板 PDF（原 Altium 库因嵌入绝对用户路径且许可未明而未发布）
- 芯片数据手册及厂商文档
- MiniFOC、MUX_EMF 参考设计/代码
- 其他带厂商或第三方来源标识的工程

文件名明确为“仿逐飞1比1”的工程因授权未确认而未发布。原始 `.eprj/.eprj2/.eprj_backup` 因嵌入本地用户凭据而全部排除；只发布已审计的 `.epro/.epro2` 导出。含 Keil `LIC` 的构建日志和聚合 ZIP 也未进入仓库。具体结果见 `docs/ASSET_IMPORT_MAP.csv`。

## 其他 SolidWorks 模型

下列目录的源工作副本没有随附独立许可证：

- `mechanical/solidworks/n30-zfcar/`
- `mechanical/solidworks/fan-motor-mount/`
- `mechanical/solidworks/custom-0429-130/` 中带“逐飞”名称的部分

它们按维护者要求隔离整理并保持工程依赖，但不能仅因 SeekFree 的另一个项目带 GPL 文件就推定获得相同授权。复用、修改或再分发前应确认原作者、来源和适用条款。电商商品图及来源未确认的参考图没有发布。

## 安全与隐私删减

公开导入明确排除了：本地 EDA 凭据数据库、Keil 许可证码、绝对用户构建路径、调试日志、构建产物、个人状态文件、SolidWorks/Office 锁文件和 Office 作者元数据；DXF 头中的绝对源路径也已清除。`scripts/verify_assets.py` 会检查导入清单、哈希、禁入格式和常见秘密标记。
