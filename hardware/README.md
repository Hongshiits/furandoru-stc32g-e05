# 电路硬件资料

本目录整理自 Furandoru 上级工作目录中的电路工程、制造文件、封装库和机械接口。源文件共用的原始修改时间采用 `Asia/Hong_Kong`（UTC+08:00）；Git 不保存修改时间，因此版本时间、原路径和 SHA-256 统一记录在 [`docs/ASSET_IMPORT_MAP.csv`](../docs/ASSET_IMPORT_MAP.csv)。

## 目录

```text
hardware/
├── projects/               # 可公开的 .epro/.epro2 工程及 MUX_EMF 源码
├── history/easyeda/        # 已审计的 EDA 导出/备份版本
├── manufacturing/         # BOM、Gerber、投板 PDF
├── libraries/             # 已审计的立创 EDA 元件库
├── mechanical-interfaces/ # 主板二维板框与接口图
└── docs/                   # 需求、原理图和参考文档
```

`.epro`/`.epro2` 用立创 EDA 专业版导入。原 Altium `.PcbLib/.SCHLIB` 因二进制内嵌本地绝对用户路径且未附独立再分发许可而没有发布。MUX_EMF 子工程保留了 Keil 工程与 `Sources`，未保留 `Objects`、`Listings`、用户状态及构建日志。

## 公开发布安全处理

源目录中的 22 个 `.eprj/.eprj2/.eprj_backup` 不是普通交换文件，而是带本地 `users` 数据的 SQLite 数据库，其中存在非空凭据字段。因此这些文件全部未发布；仓库只收录经审计未命中用户凭据或 Keil 许可证码的 `.epro/.epro2` 导出和备份包。

这会造成两个有意的版本缺口：

- `AI8052U-64-furan-0322` 的原始本地工程更新到 2026-06-10，但当前可公开的最新 `.epro2` 导出是 2026-05-26 03:35:40。
- 五路运放的四个原始本地数据库版本未发布；安全历史目录中保留了 2026-05-05 和 2026-07-16 的导出版本。

如需补齐，应在立创 EDA 中打开本地工程并重新导出 `.epro2`，审计后再提交；不要直接提交 `.eprj2`。

同时排除了：含 Keil `LIC` 的聚合压缩包和构建日志、`debug.log`、`.aic`、Keil 编译产物、来源不明参考图片，以及文件名明确为第三方 1:1 仿制但未附再分发许可的工程。Office BOM/文档副本已清除作者、最后修改者、公司等 OOXML 元数据，DXF 的 `$FILENAME` 绝对源路径也已改为中性名称。

## 版本与去重规则

- 同名但内容不同：`<原名>__YYYYMMDD-HHMMSS.<扩展名>`。
- 修改时间也相同且内容不同：再追加 SHA-256 前 8 位。
- 内容完全相同：通常只保留修改时间较新的语义路径，所有原路径仍写入导入清单。唯一例外是 N30 主板支架 DXF，同时保留硬件接口副本与完整第三方快照中的原位置。
- `n30主板支架.step.dxf` 实际为 ASCII DXF，发布时纠正为 `.dxf` 并附加修改时间；未将它误标为 STEP/3D 模型。

## 许可说明

这些资料来自同一项目工作目录，但并非都自动适用仓库根目录的 GPL。厂商 PDF、MiniFOC、MUX 参考代码等随源目录未附独立许可证。公开可见不代表获得额外使用或再分发授权；使用前请查看 [`THIRD_PARTY_NOTICES.md`](../THIRD_PARTY_NOTICES.md) 并核实相应权利人的条款。
