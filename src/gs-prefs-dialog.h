/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 * vi:set noexpandtab tabstop=8 shiftwidth=8:
 *
 * Copyright (C) 2018 Gautham Nair <gautham.nair.2005@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

#pragma once

#include <gtk/gtk.h>

#include "unity-software-private.h"

G_BEGIN_DECLS

#define GS_TYPE_PREFS_DIALOG (gs_prefs_dialog_get_type ())

G_DECLARE_FINAL_TYPE (GsPrefsDialog, gs_prefs_dialog, GS, PREFS_DIALOG, GtkDialog)

GtkWidget	*gs_prefs_dialog_new		(GtkWindow	*parent,
						 GsPluginLoader	*plugin_loader);

G_END_DECLS
