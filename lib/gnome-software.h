/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 * vi:set noexpandtab tabstop=8 shiftwidth=8:
 *
 * Public umbrella header exposing the project API (types like GsPlugin,
 * GsApp, etc.). This file was accidentally replaced by a wrapper during
 * the rebranding; restore it to include the real public headers so
 * sources that include <gnome-software.h> build correctly.
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

#pragma once

#include <glib-object.h>
#include <gio/gio.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <appstream-glib.h>

/* Core public headers from this project */
#include "gs-app.h"
#include "gs-app-list.h"
#include "gs-app-collation.h"
#include "gs-category.h"
#include "gs-plugin.h"
#include "gs-plugin-event.h"
#include "gs-plugin-types.h"
#include "gs-utils.h"
#include "gs-debug.h"
#include "gs-os-release.h"

G_BEGIN_DECLS

/* Nothing else needed here; the public types and declarations are in the
 * included headers above. Keep this umbrella header stable so external
 * consumers don't need to change their includes. */

G_END_DECLS
