#!/usr/bin/env python3
"""Verify the curated hardware/mechanical import and screen common secrets."""

from __future__ import annotations

import csv
import hashlib
import re
import sys
import zipfile
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
MANIFEST = ROOT / "docs" / "ASSET_IMPORT_MAP.csv"
ASSET_ROOTS = (ROOT / "hardware", ROOT / "mechanical")
FORBIDDEN_SUFFIXES = {".eprj", ".eprj2", ".eprj_backup", ".bak", ".aic"}
FORBIDDEN_PARTS = {"objects", "listings"}
MAX_REGULAR_GIT_FILE = 100_000_000

PATTERNS = {
    "private-key": re.compile(rb"-----BEGIN [A-Z ]*PRIVATE KEY-----", re.I),
    "keil-license": re.compile(rb"\bLIC\s*=", re.I),
    "github-token": re.compile(rb"\b(?:ghp_|github_pat_)[A-Za-z0-9_]+", re.I),
    "aws-key": re.compile(rb"\bAKIA[0-9A-Z]{16}\b"),
    "windows-user-path": re.compile(rb"[A-Za-z]:\\Users\\", re.I),
    "local-profile-name": re.compile(rb"\bptcu_\b", re.I),
    "password-assignment": re.compile(rb"\b(?:password|passwd)\s*[=:]", re.I),
}


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest().upper()


def scan_payload(label: str, payload: bytes, findings: list[str]) -> None:
    for name, pattern in PATTERNS.items():
        if pattern.search(payload):
            findings.append(f"{label}: sensitive marker {name}")


def scan_file(path: Path, findings: list[str]) -> None:
    relative = path.relative_to(ROOT).as_posix()
    try:
        payload = path.read_bytes()
    except OSError as error:
        findings.append(f"{relative}: cannot read ({error})")
        return
    scan_payload(relative, payload, findings)
    if path.suffix.casefold() == ".dxf" and re.search(rb"[A-Za-z]:\\", payload):
        findings.append(f"{relative}: DXF contains an absolute Windows path")
    if path.suffix.casefold() in {".zip", ".epro", ".epro2", ".xlsx", ".docx"} and zipfile.is_zipfile(path):
        try:
            with zipfile.ZipFile(path) as archive:
                for member in archive.infolist():
                    if member.is_dir() or member.file_size > 50_000_000:
                        continue
                    scan_payload(f"{relative}!{member.filename}", archive.read(member), findings)
        except (OSError, zipfile.BadZipFile, RuntimeError) as error:
            findings.append(f"{relative}: cannot inspect archive ({error})")


def main() -> int:
    errors: list[str] = []
    findings: list[str] = []
    if not MANIFEST.is_file():
        errors.append("missing docs/ASSET_IMPORT_MAP.csv")
        rows: list[dict[str, str]] = []
    else:
        with MANIFEST.open(encoding="utf-8-sig", newline="") as stream:
            rows = list(csv.DictReader(stream))

    for row in rows:
        action = row.get("action", "")
        repository_path = row.get("repository_path", "")
        if action not in {"included", "renamed", "deduplicated"} or not repository_path:
            continue
        path = ROOT / repository_path
        if not path.is_file():
            errors.append(f"manifest target missing: {repository_path}")
            continue
        expected = row.get("published_sha256", "")
        if action in {"included", "renamed"} and expected and sha256(path) != expected:
            errors.append(f"published SHA-256 mismatch: {repository_path}")

    files = sorted(path for root in ASSET_ROOTS for path in root.rglob("*") if path.is_file())
    listed = {
        row.get("repository_path", "")
        for row in rows
        if row.get("action") in {"included", "renamed"} and row.get("repository_path")
    }
    allowed_unlisted = {"hardware/README.md", "mechanical/README.md"}
    for path in files:
        relative_string = path.relative_to(ROOT).as_posix()
        if relative_string not in listed and relative_string not in allowed_unlisted:
            errors.append(f"asset file is not represented by an included manifest row: {relative_string}")
    for path in files:
        relative = path.relative_to(ROOT)
        lowered_parts = {part.casefold() for part in relative.parts}
        if path.suffix.casefold() in FORBIDDEN_SUFFIXES:
            errors.append(f"forbidden local/backup format: {relative.as_posix()}")
        if FORBIDDEN_PARTS & lowered_parts:
            errors.append(f"forbidden generated directory: {relative.as_posix()}")
        if path.name.startswith("~$") or path.name.casefold() == "debug.log":
            errors.append(f"forbidden temporary/log file: {relative.as_posix()}")
        if path.stat().st_size >= MAX_REGULAR_GIT_FILE:
            errors.append(f"file reaches GitHub regular-Git limit: {relative.as_posix()}")
        scan_file(path, findings)

    if findings:
        errors.extend(findings)
    if errors:
        print("Asset verification failed:")
        for error in errors:
            print(f"- {error}")
        return 1
    print(f"Asset verification passed: {len(files)} asset files, {len(rows)} source-manifest rows, no blocked markers.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
