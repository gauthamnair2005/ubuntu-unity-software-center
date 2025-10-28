/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 * vi:set noexpandtab tabstop=8 shiftwidth=8:
 *
 * Copyright (C) 2012-2013 Gautham Nair <gautham.nair.2005@gmail.com>
 * Copyright (C) 2013 Matthias Clasen <mclasen@redhat.com>
 * Copyright (C) 2015 Kalev Lember <klember@redhat.com>
 * Copyright (C) 2025 Gautham Nair <gautham.nair.2005@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

#include "config.h"

#include <glib/gi18n.h>
#include <gio/gio.h>
#include <gio/gdesktopappinfo.h>
#include <gtk/gtk.h>
#include <locale.h>
#include <sys/stat.h>

#include "gs-application.h"
#include "gs-debug.h"

int
main (int argc, char **argv)
{
	int status = 0;
	g_autoptr(GDesktopAppInfo) appinfo = NULL;
	g_autoptr(GsApplication) application = NULL;
	g_autoptr(GsDebug) debug = gs_debug_new ();

	g_set_prgname ("org.ubuntuunity.software");
	setlocale (LC_ALL, "");

	bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	textdomain (GETTEXT_PACKAGE);

	/* Override the umask to 022 to make it possible to share files between
	 * the unity-software process and flatpak system helper process.
	 * Ideally this should be set when needed in the flatpak plugin, but
	 * umask is thread-unsafe so there is really no local way to fix this.
	 */
	umask (022);

	/* redirect logs */
	application = gs_application_new ();
	appinfo = g_desktop_app_info_new ("org.ubuntuunity.software.desktop");

	/* fall back to our branded name when the .desktop file is not installed */
	if (appinfo != NULL) {
		const gchar *display_name = g_app_info_get_name (G_APP_INFO (appinfo));
		if (display_name != NULL && display_name[0] != '\0')
			g_set_application_name (display_name);
		else
			g_set_application_name ("Ubuntu Unity Software Center");
	} else {
		g_set_application_name ("Ubuntu Unity Software Center");
	}
	status = g_application_run (G_APPLICATION (application), argc, argv);
	return status;
}
