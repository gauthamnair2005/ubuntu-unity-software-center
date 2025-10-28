/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 * vi:set noexpandtab tabstop=8 shiftwidth=8:
 *
 * Copyright (C) 2013 Gautham Nair <gautham.nair.2005@gmail.com>
 * Copyright (C) 2014-2018 Kalev Lember <klember@redhat.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

#pragma once

#include <gtk/gtk.h>

#include "unity-software-private.h"

G_BEGIN_DECLS

#define GS_TYPE_REPOS_DIALOG (gs_repos_dialog_get_type ())

G_DECLARE_FINAL_TYPE (GsReposDialog, gs_repos_dialog, GS, REPOS_DIALOG, GtkDialog)

GtkWidget	*gs_repos_dialog_new		(GtkWindow	*parent,
						 GsPluginLoader	*plugin_loader);

G_END_DECLS
