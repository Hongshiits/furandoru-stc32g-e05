#!/usr/bin/env python3
"""Verify that the trimmed E05 repository is self-contained."""

from __future__ import annotations

import sys
import xml.etree.ElementTree as ET
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
PROJECT = ROOT / "firmware" / "E05_pwm_demo" / "mdk" / "seekfree.uvproj"


def windows_relative(base: Path, value: str) -> Path:
    """Resolve a Windows-style project path on any host OS."""
    return (base / Path(value.replace("\\", "/"))).resolve()


def project_references() -> tuple[list[Path], list[Path]]:
    tree = ET.parse(PROJECT)
    project_dir = PROJECT.parent

    files: list[Path] = []
    for node in tree.iter("FilePath"):
        if node.text and node.text.strip():
            files.append(windows_relative(project_dir, node.text.strip()))

    include_dirs: list[Path] = []
    for node in tree.iter("IncludePath"):
        if not node.text:
            continue
        for entry in node.text.split(";"):
            if entry.strip():
                include_dirs.append(windows_relative(project_dir, entry.strip()))

    return files, include_dirs


def repository_noise() -> list[Path]:
    forbidden_names = {"out_file", "Objects", "Listings", "__pycache__", ".venv"}
    noise: list[Path] = []

    for path in ROOT.rglob("*"):
        if path.is_dir() and path.name in forbidden_names:
            noise.append(path)
        elif path.is_file() and (
            path.name.startswith("seekfree.uvgui.")
            or path.suffix.lower() in {".crf", ".lst", ".pyc"}
            or path.name.endswith(".__i")
        ):
            noise.append(path)

    return noise


def main() -> int:
    errors: list[str] = []

    required_documents = [
        ROOT / "LICENSE",
        ROOT / "README.md",
        ROOT / "THIRD_PARTY_NOTICES.md",
        ROOT / "docs" / "UPSTREAM_AND_CHANGES.md",
    ]

    for document in required_documents:
        if not document.is_file():
            errors.append(f"missing release document: {document}")

    if not PROJECT.is_file():
        print(f"ERROR: missing Keil project: {PROJECT.relative_to(ROOT)}")
        return 1

    try:
        files, include_dirs = project_references()
    except ET.ParseError as exc:
        print(f"ERROR: invalid Keil project XML: {exc}")
        return 1

    missing_files = sorted({path for path in files if not path.is_file()})
    missing_dirs = sorted({path for path in include_dirs if not path.is_dir()})

    for path in missing_files:
        errors.append(f"missing project file: {path}")
    for path in missing_dirs:
        errors.append(f"missing include directory: {path}")
    for path in repository_noise():
        errors.append(f"generated or personal file present: {path}")

    print(f"Keil project file references: {len(files)} ({len(set(files))} unique)")
    print(f"Keil include directories: {len(include_dirs)} ({len(set(include_dirs))} unique)")

    if errors:
        for message in errors:
            print(f"ERROR: {message}")
        print(f"Verification failed with {len(errors)} error(s).")
        return 1

    print("Verification passed: the E05 project is self-contained and clean.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
