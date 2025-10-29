# Ubuntu Unity Software Center

This application was modified from  gnome-software 3.38.2

Ubuntu Unity Software Center lets you install and update applications and
system extensions from multiple backends. The plugin loader enables the
traditional PackageKit stack alongside Flatpak, firmware, ratings and reviews
via ODRS, and other feature plugins.

The UI consumes [AppStream](https://www.freedesktop.org/wiki/Distributions/AppStream/)
metadata and follows the familiar GNOME Software workflow.

## Build and run

This project uses Meson. The overview page now features a "Recommended by Unity Developers"
carousel that surfaces highlighted applications with their first screenshot, icon, and
summary directly on the hero slide, helping users recognise the software at a glance.

```
meson setup build
meson compile -C build
meson compile -C build install-sample-data   # optional, populates build/data
./unity-software
```

### Build dependencies (Ubuntu / Debian)

Install the core toolchain and headers needed to compile the project and its default plugins.

```
sudo apt install build-essential meson ninja-build pkg-config \
	gettext glib2.0-dev libgtk-3-dev libappstream-glib-dev \
	libxmlb-dev libsoup2.4-dev libgdk-pixbuf2.0-dev libjson-glib-dev \
	libpolkit-gobject-1-dev libpackagekit-glib2-dev libflatpak-dev \
	libostree-dev libmalcontent-0-dev libgudev-1.0-dev valgrind \
	sysprof-capture-dev libgnome-desktop-3-dev libgspell-1-dev \
	libgoa-1.0-dev
```

### Optional components

- Firmware updates (`fwupd` plugin): install `libfwupd-dev` (or the equivalent
	development package for your distribution). The build enables the plugin
	automatically when the headers are present.
- Snap support (`snap` plugin): install `libsnapd-glib-dev`.
- RPM-OStree / Fedora tooling plugins: install `libdnf-dev`, `rpm-ostree-dev`, and
  enable the relevant Meson options if you plan to ship those integrations.

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
