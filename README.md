# Ubuntu Unity Software Center

Ubuntu Unity Software Center lets you install and update applications and
system extensions from multiple backends. The plugin loader enables the
traditional PackageKit stack alongside Flatpak, firmware, ratings and reviews
via ODRS, and other feature plugins.

The UI consumes [AppStream](https://www.freedesktop.org/wiki/Distributions/AppStream/)
metadata and follows the familiar GNOME Software workflow.

## Build and run

This project uses Meson.

```
meson setup build
meson compile -C build
meson compile -C build install-sample-data   # optional, populates build/data
./unity-software
```

The `install-sample-data` helper reproduces the historical
`make install-sample-data` target. It copies the small test catalog from
`data/sample-data` into `build/data` so the uninstalled binary has a populated
software list, complete with icons.

To install into a prefix instead, run:

```
meson setup --prefix /opt/unity-software build
meson compile -C build
meson install -C build
```

## Debugging

Pass `--verbose` or set `G_MESSAGES_DEBUG=Gs` when running the binary (either
via `./unity-software` or `build/src/unity-software`) to get detailed logging
from the plugin stack.
