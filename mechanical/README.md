# 3D 模型与机械资料

本目录整理 SolidWorks 原生文件、制造/交换格式和一个带明确 GPL-3.0 许可证的逐飞轻量化车模快照。原始路径、修改时间、去重与排除记录见 [`docs/ASSET_IMPORT_MAP.csv`](../docs/ASSET_IMPORT_MAP.csv)。

## 目录

```text
mechanical/
├── solidworks/
│   ├── n30-zfcar/          # 原生装配/零件与 STL、DXF、3MF 导出
│   ├── custom-0429-130/    # Furandoru 自制零件、工程图与导出
│   └── fan-motor-mount/    # 负压风扇及电机支架
└── third-party/
    └── lightweight-car-chassis/ # SeekFree 项目及原 LICENSE/README
```

## SolidWorks 依赖保护

`solidworks/n30-zfcar/native/` 中所有 `.SLDASM` 和 `.SLDPRT` 保持原始文件名并置于同一目录，避免直接改名破坏装配引用：

| 装配体 | 依赖零件 |
| --- | --- |
| `Assem1.SLDASM` | `电磁支架固定2.SLDPRT`、`Mirror电磁支架固定2.SLDPRT` |
| `Assem2.SLDASM` | `电磁支架固定2.SLDPRT`、`Mirror电磁支架固定21.SLDPRT` |
| `Assem3.SLDASM` | `电磁支架固定2.SLDPRT`、`Mirror电磁支架固定2.SLDPRT` |

两个镜像零件还带有对原零件或装配上下文的外部引用。后续若要改名，请使用 SolidWorks **Pack and Go** 或“替换引用”，不要在资源管理器中直接改名。

`custom-0429-130/native/` 内的 `furan-fan-frame.SLDDRW`、`一体板板框_兼容逐飞_V1.1.SLDDRW` 和 `furan_top_support_rightMirror.SLDPRT` 保存过失效的旧绝对路径；其目标零件仍与它们同目录，SolidWorks 通常可通过同目录搜索恢复。首次打开后应人工确认所有引用，再另存或 Pack and Go。

## 版本与删减

- STL 和独立零件的同名不同内容版本使用 `__YYYYMMDD-HHMMSS` 后缀；字节完全相同的副本只保留一份。
- 原生装配依赖文件不参与文件系统重命名。
- 已排除 5 个 `~$` 锁文件、12 个 `.bak`、两个与解压内容完全相同的 ZIP、5 张许可未确认的商品参考图，以及一份二进制属性嵌入本地用户名且无法无损清理的 DWG。
- 发布的 DXF 已清除 `$LASTSAVEDBY` 和绝对源文件路径字段，几何实体保持不变。
- 已排除 `Scan2026-03-13_234830.png`（147,900,842 bytes，9637×13747）：它不是 3D 工程文件且超过 GitHub 普通 Git 的 100 MiB 单文件限制。

## 来源与许可

`third-party/lightweight-car-chassis/` 对应 SeekFree 的 Lightweight Car Chassis 项目，完整保留上游 `LICENSE`、中英文 README 和目录结构；其中后续加入的本地派生文件也按 GPL-3.0 兼容方式发布。

`n30-zfcar`、`fan-motor-mount` 以及 `custom-0429-130` 中带“逐飞”名称的部分在源目录中没有随附独立许可证，不能仅凭另一个目录含 GPL 文件就推定授权。它们按维护者的公开发布要求隔离整理，但公开可见本身不授予额外权利；复用或再分发前请核实来源和许可。详见 [`THIRD_PARTY_NOTICES.md`](../THIRD_PARTY_NOTICES.md)。
