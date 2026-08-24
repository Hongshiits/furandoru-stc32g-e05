# 第三方组件与公开发布门禁

本文件记录整理时能够从源代码树直接确认的许可证信息，以及仍待核实的第三方组件。它不是对第三方许可证的替代，也不是法律意见。

## 逐飞科技 STC32G144K 开源库

`firmware/libraries` 和 E05 示例的大部分源文件包含成都逐飞科技有限公司的版权声明，并声明按 GPLv3 或后续版本授权。仓库根目录 `LICENSE` 保留了源工作副本提供的 GPLv3 全文；原文件头不得删除。

源文件头提到的 `libraries/doc/GPL3_permission_statement.txt` 和 `libraries/LICENSE` 在被整理的源工作副本中实际并不存在，只有仓库根目录 `LICENSE`。因此本仓库没有伪造或补写缺失的上游授权文件，而是在这里明确记录该不一致。

## Keil 启动文件

- `firmware/libraries/zf_common/START251.A51`

该文件带有 Keil 版权声明，但源工作副本中没有附带明确的独立再分发许可。它是当前 Keil 工程直接引用的启动文件，所以暂时保留在私有快照中。公开发布前应确认 Keil/C251 工具链许可是否允许分发，或改为构建时从已安装工具链取得兼容启动文件。

## STC 头文件与 USB 示例

以下文件或目录带有 STC/厂商来源标识，但源工作副本中没有找到单独的开源许可证：

- `firmware/libraries/zf_common/stc32g144k246.h`
- `firmware/libraries/zf_common/ai_usb.h`
- `firmware/libraries/zf_components/stc32g_usb_lib/`

公开发布前应向权利人或正式 SDK 的授权条款确认其再分发范围。

## 预编译二进制库

- `firmware/libraries/zf_device/zf_device_config.LIB`
- `firmware/libraries/zf_device/zf_device_mt9v03x_dma.LIB`

源工作副本没有为这两个二进制库提供独立许可证或可对应的完整源码。它们是当前 Keil 工程直接引用的构建依赖，因此暂时保留在私有快照中。若要公开发布，应取得明确的再分发授权及必要的对应源码，或从工程中移除/替换这些依赖。

## 公开发布门禁

只有在完成下列任一方案后，才建议将 GitHub 仓库由私有改为公开：

1. 为上述 Keil、STC 和 `.LIB` 文件取得并记录明确的公开再分发许可；或
2. 从仓库删除这些文件，并提供合法来源、安装步骤以及不会破坏工程的构建接入方式；或
3. 使用许可明确且兼容的实现替换它们。
