#!/bin/bash

set -e

git clone https://gitlab.gnome.org/GNOME/unity-software.git
meson subprojects download --sourcedir unity-software
rm unity-software/subprojects/*.wrap
mv unity-software/subprojects/ .
rm -rf unity-software
