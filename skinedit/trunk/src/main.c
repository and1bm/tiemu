/* Hey EMACS -*- linux-c -*- */
/* $Id$ */

/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <stdio.h>
#include <signal.h>
#include <string.h>

#include <gtk/gtk.h>

#ifdef __WIN32__
#include <windows.h>
#endif

#include "main_intf.h"
#include "support.h"
#include "utils.h"

#include "struct.h"
#include "skinops.h"
#include "main_cb.h"

GtkWidget *main_wnd;

static void help(void)
{
  fprintf(stdout, "\n");
  fprintf(stdout, _("Usage: skinedit [-options] [filename]\n"));
  fprintf(stdout, "\n");
  fprintf(stdout, _
	  ("-h, --help    display this information page and exit\n"));
  fprintf(stdout, _
	  ("-v, --version display the version information and exit\n"));
  fprintf(stdout, "\n");
  fprintf(stdout, _("filename      a skin file to load\n"));
  fprintf(stdout, "\n");
  fprintf(stdout, _("See the manpage for more informations...\n"));
  fprintf(stdout, "\n");
  exit(0);
}

static int strexact(char *p1, char *p2)
{
  return (strstr(p1, p2) && strstr(p2, p1));
}

void
signal_handler(int sig)
{
  fprintf(stderr, _("Caught SIGINT, exiting ...\n"));

  clear_skin_infos();

  gtk_main_quit();

  exit(0);
}

#undef main

int
main (int argc, char *argv[])
{
  int cnt;
  const char *p;
  char arg[128];
  
#ifdef __WIN32__
  HMODULE hModule;
  char *sBuffer;
  DWORD dWord;
  char *dirname;
  char *base_dir;
  char *pixmap_dir;
  char *locale_dir;
  
  // Init the path for the Windows version by getting the 
  // executable location.
  hModule = GetModuleHandle("skinedit.exe");
  sBuffer = (char *) malloc(4096 * sizeof(char));
  dWord = GetModuleFileName(hModule, sBuffer, 4096);
  dirname = g_dirname(sBuffer);
  base_dir = g_strconcat(dirname, "\\", NULL);
  g_free(dirname);
  free(sBuffer);
  
  pixmap_dir = g_strconcat(base_dir, "pixmaps\\", NULL);
  locale_dir = g_strconcat(base_dir, "locale\\", NULL);
#endif

#ifdef ENABLE_NLS
#ifndef __WIN32__
  printf("locale=<%s>\n", PACKAGE_LOCALE_DIR);
  bindtextdomain (PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (PACKAGE, "UTF-8");
  textdomain (PACKAGE);
#else
  bindtextdomain(PACKAGE, locale_dir);
  bind_textdomain_codeset(PACKAGE, "UTF-8");
  textdomain (PACKAGE);
#endif
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

#ifndef __WIN32__
  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");
#else
  add_pixmap_directory (pixmap_dir);
#endif

  signal(SIGINT, signal_handler);

  fprintf(stdout, _("SkinEdit v%s, (C) 2002-2003 Julien BLACHE <jb@tilp.info>\n"), VERSION);
  fprintf(stdout, _("                  2004-2007 Romain Lievin <roms@tilp.info>\n"));
  fprintf(stdout, "\n");
  fprintf(stdout, _("This program is free software; you can redistribute it and/or modify\n"));
  fprintf(stdout, _("it under the terms of the GNU General Public License as published by\n"));
  fprintf(stdout, _("the Free Software Foundation; version 2 of the License\n"));
  fprintf(stdout, _("This program is distributed in the hope that it will be useful,\n"));
  fprintf(stdout, _("but WITHOUT ANY WARRANTY; without even the implied warranty of\n"));
  fprintf(stdout, _("MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"));
  fprintf(stdout, _("GNU General Public License for more details.\n"));

  gtk_widget_show (main_wnd = create_main_window());

  sbar_print(_("Skinedit v%s -- Supported formats : TiEmu v2.00, VTiv2.1, VTiv2.5"), VERSION);

    // scan command line
    for (cnt = 1; cnt < argc; cnt++) {
      
      // get argument
      p = argv[cnt];
      if (*p == '-') {
	// argument
	p++;
      } else {
	// filename
	if(load_skin(p) == 0)
	  skin_infos.changed = 1;
      }
      
      strcpy(arg, p);
      
      if (strexact(arg, "-help") || strexact(arg, "h"))
	help();
      if (strexact(arg, "-version") || strexact(arg, "v"))
	exit(0);
    }
    
    gtk_main ();
    return 0;
}

/* 
   If TiEmu is compiled in console mode (_CONSOLE), 
   then we use the 'main' entry point.
   If TiEmu is compiled as a windowed application (_WINDOWS), 
   then we use the 'WinMain' entry point.
*/
#if defined(__WIN32__) && defined(_WINDOWS)	&& !defined(_CONSOLE)
int APIENTRY WinMain(HINSTANCE hInstance,
		     HINSTANCE hPrevInstance,
		     LPSTR lpCmdLine, int nCmdShow)
{
  return main(__argc, __argv);
}
#endif
