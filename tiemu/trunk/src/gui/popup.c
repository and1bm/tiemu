/* Hey EMACS -*- linux-c -*- */
/* $Id: popup.c 153 2004-05-12 13:20:41Z roms $ */

/*  TiEmu - a TI emulator
 *  loader.c: loader for TiEmu skins
 *  Copyright (c) 2000, Thomas Corvazier, Romain Lievin
 *  Copyright (c) 2001-2002, Romain Lievin, Julien Blache
 *  Copyright (c) 2003-2004, Romain Li�vin
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

extern int halt(void);

/* 
   Display a popup menu: entry point used by hid.c (SDL)
*/
void gui_popup_menu(void)
{
	guint32 time;
	GtkWidget *menu;

	// don't have time event due to SDL
	time = gtk_get_current_event_time();

	// halt emulation engine
	halt();

	// display popup menu
	menu = GTK_MENU(display_popup_menu());
	gtk_menu_popup(menu,
		 NULL, NULL, NULL, NULL,
		 GDK_3BUTTON_PRESS, time);

	gtk_widget_show(menu);
}
