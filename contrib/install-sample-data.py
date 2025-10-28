#!/usr/bin/env python3
"""Copy sample AppStream data into the build tree.

This reproduces the old "make install-sample-data" helper so that uninstalled
builds have enough metadata to render example content.
"""

from __future__ import annotations

import argparse
import os
from pathlib import Path
import shutil
import sys

def copy_tree(source: Path, destination: Path) -> None:
    """Recursively copy *source* into *destination* with merge semantics."""
    for root, dirs, files in os.walk(source):
        src_root = Path(root)
        rel_root = src_root.relative_to(source)
        dest_root = destination / rel_root
        dest_root.mkdir(parents=True, exist_ok=True)

        for filename in files:
            if filename == 'meson.build':
                continue
            src_path = src_root / filename
            dest_path = dest_root / filename
            shutil.copy2(src_path, dest_path)

def install_sample_data(sample_root: Path, build_root: Path, stamp: Path) -> None:
    data_dest = build_root / 'data'
    data_dest.mkdir(parents=True, exist_ok=True)

    # Copy bundled sample metadata.
    copy_tree(sample_root, data_dest)

    # Reuse the real icons provided by the project so the sample entry renders.
    project_icons = sample_root.parent / 'icons'
    if project_icons.exists():
        copy_tree(project_icons, data_dest / 'icons')

    # Touch the stamp file for Meson.
    stamp.parent.mkdir(parents=True, exist_ok=True)
    stamp.write_text('Sample data installed\n')


def parse_args(argv: list[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('sample_root', type=Path, help='Path to data/sample-data')
    parser.add_argument('build_root', type=Path, help='Meson build root')
    parser.add_argument('stamp_path', type=Path, help='Output stamp path')
    return parser.parse_args(argv)


def main(argv: list[str]) -> None:
    args = parse_args(argv)
    install_sample_data(args.sample_root, args.build_root, args.stamp_path)


if __name__ == '__main__':
    main(sys.argv[1:])
