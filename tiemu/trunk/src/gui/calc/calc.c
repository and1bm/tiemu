/* Hey EMACS -*- linux-c -*- */
/* $Id: dbg_cause.c 446 2004-06-13 09:11:07Z roms $ */

/*  TiEmu - an TI emulator
 *
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
#  include <config.h>
#endif				/*  */

#ifdef GTK_DISABLE_DEPRECATED
#undef GTK_DISABLE_DEPRECATED
#include <gtk/gtk.h>
#define GTK_DISABLE_DEPRECATED
#endif
#include <glade/glade.h>

#include "intl.h"
#include "paths.h"
#include "skinops.h"
#include "support.h"
#include "ti68k_int.h"
#include "struct.h"
#include "tie_error.h"
#include "calc.h"
#include "dbg_all.h"
#include "screenshot.h"
#include "kbd_mapper.h"

GtkWidget *main_wnd = NULL;
GtkWidget *area = NULL;

gint w, h;

extern GdkPixbuf*	lcd;
extern GdkPixbuf*	skn;
extern GdkPixmap*	pixmap;

extern Pc2TiKey*    kbd_keymap;
extern const char*	skn_keymap;
extern const char	sknKey92[];
extern const char	sknKey89[];

extern uint32_t*	lcd_bytmap;
extern LCD_INFOS	li;
extern SCALE_INFOS	sc;

gint display_main_wnd(void)
{
	GladeXML *xml;

	xml = glade_xml_new
		(tilp_paths_build_glade("calc-2.glade"), "calc_wnd",
		 PACKAGE);
	if (!xml)
		g_error(_("%s: GUI loading failed !\n"), __FILE__);
	glade_xml_signal_autoconnect(xml);
	
	main_wnd = glade_xml_get_widget(xml, "calc_wnd");
	area = glade_xml_get_widget(xml, "drawingarea1");

	gtk_window_set_policy (GTK_WINDOW (main_wnd), TRUE, TRUE, FALSE);

    gtk_widget_show(area);
	gtk_widget_show(main_wnd);

	return 0;
}

GLADE_CB void
on_calc_wnd_destroy                    (GtkObject       *object,
                                        gpointer         user_data)
{
	return;
}

GLADE_CB gboolean
on_calc_wnd_delete_event           (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
    return TRUE;	// block destroy
}

void redraw_skin(void);
static void resize(void)
{
	// Get window size depending on windowed/fullscreen
	if(params.background)
	{
		w = skin_infos.width;
		h = skin_infos.height;
	}
	else
	{
		w = tihw.lcd_w;
		h = tihw.lcd_h;
	}
		
	gtk_drawing_area_size(GTK_DRAWING_AREA(area), w, h);
	gtk_window_resize(GTK_WINDOW(main_wnd), w, h);

	if(params.background)
		redraw_skin();
}

typedef void (*VCB) (void);

GLADE_CB gboolean
on_calc_wnd_expose_event           (GtkWidget       *widget,
                                    GdkEventExpose  *event,
                                    gpointer         user_data)
{
	SKIN_INFOS *si = & skin_infos;
	guint width, height;

	width = event->area.width;
	height = event->area.height;
	//if(width < si->width || height < si->height)
	//	return;

	sc.w = width;
	sc.h = (int)(sc.w / sc.r);
	sc.s = (float)sc.w / si->width;
	printf("expose: scaling w/ %ix%i %1.2f %1.2f\n", sc.w, sc.h, sc.r, sc.s);

	//w = width;
	//h = height;

	g_signal_handlers_block_by_func(GTK_OBJECT(widget), (VCB)on_calc_wnd_expose_event, NULL);
	//resize();
	g_signal_handlers_unblock_by_func(GTK_OBJECT(widget), (VCB)on_calc_wnd_expose_event, NULL);

	return TRUE;
}

GLADE_CB gboolean
on_drawingarea1_configure_event        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data)
{
    return FALSE;
}

GLADE_CB gboolean
on_drawingarea1_expose_event           (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data)
{
	if(pixmap == NULL)
	    return FALSE;

    gdk_draw_pixmap(
        widget->window,
		widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		pixmap,
		event->area.x, event->area.y,
		event->area.x, event->area.y,
		event->area.width, event->area.height);

	return FALSE;
}


GLADE_CB void
on_calc_wnd_size_request           (GtkWidget       *widget,
                                    GtkRequisition  *requisition,
                                    gpointer         user_data)
{
	// to remove !
}

static int match_skin(int calc_type)
{
	SKIN_INFOS si;
	int ok;
	gchar *skin_name, *s;

	s = g_strdup(ti68k_calctype_to_string(calc_type));
	skin_name = g_ascii_strdown(s, strlen(s));

	// filename is "", load default skin
	if(!strcmp(g_basename(options.skin_file), ""))
	{
		g_free(options.skin_file);
		options.skin_file = g_strdup_printf("%s%s.skn", 
					    inst_paths.skin_dir, skin_name);
		g_free(skin_name);
		return -1;
	}

	// load skin header
	if(skin_read_header(options.skin_file, &si) == -1)
	{
		g_free(options.skin_file);
      	options.skin_file = g_strdup_printf("%s%s.skn", 
					    inst_paths.skin_dir, skin_name);
	    g_free(skin_name);
	    return -1;
	}

	// is skin compatible
	switch(tihw.calc_type)
	{
	    case TI92:
		case TI92p:
            ok = !strcmp(si.calc, SKIN_TI92) || !strcmp(si.calc, SKIN_TI92P);
		break;
	    case TI89:
        case TI89t:
            ok = !strcmp(si.calc, SKIN_TI89) || !strcmp(si.calc, SKIN_TI89T);
		break;
		case V200:
			ok = !strcmp(si.calc, SKIN_V200);
		break;
	    default: 
            ok = 0;
		break;
	}

	if(!ok)
	{
		g_free(options.skin_file);
      	options.skin_file = g_strdup_printf("%s%s.skn", 
			inst_paths.skin_dir, skin_name);

	    //tiemu_error(0, _("skin incompatible with the current calc model. Falling back to default skin."));
	    g_free(skin_name);
		return -1;
	}

    g_free(skin_name);
	return 0;
}

static int match_keymap(int calc_type)
{
	gchar *keys_name, *s;
    int ct, ok;

	s = g_strdup(ti68k_calctype_to_string(calc_type));
	keys_name = g_ascii_strdown(s, strlen(s));

	// filename is "", load default keymap
	if(!strcmp(g_basename(options.keys_file), ""))
	{
		g_free(options.keys_file);
		options.keys_file = g_strdup_printf("%s%s.map", 
					    inst_paths.skin_dir, keys_name);
	}

	// load keymap header
    ct = keymap_read_header(options.keys_file);
	if(ct == -1)
	{
		g_free(options.keys_file);
      	options.keys_file = g_strdup_printf("%s%s.map", 
					    inst_paths.skin_dir, keys_name);
	    g_free(keys_name);
	    return -1;
	}

    // is keymap compatible
	switch(tihw.calc_type)
	{
	    case TI92:
		case TI92p:
        case V200:
            ok = (ct == TI92) || (ct == TI92p) || (ct == V200);
		break;
	    case TI89:
        case TI89t:
            ok = (ct == TI89) || (ct == TI89t);
		break;
	    default: 
            ok = 0;
		break;
	}

	if(!ok)
	{
		g_free(options.keys_file);
      	options.keys_file = g_strdup_printf("%s%s.map", 
			inst_paths.skin_dir, keys_name);

	    //tiemu_error(0, _("keymap incompatible with the current calc model. Falling back to default keymap."));
	    g_free(keys_name);
		return -1;
	}

    g_free(keys_name);
	return 0;
}

G_LOCK_EXTERN(lcd_flag);
extern volatile int lcd_flag;
extern volatile int debugger;
static gint tid = -1;

static gint hid_refresh (gpointer data)
{
    if(lcd_flag || (tihw.calc_type >= HW2))
    {
		// TI92+: jackycar, TI89: baballe
        hid_update_lcd();
        G_LOCK(lcd_flag);
        lcd_flag = 0;
		//printf("<");
        G_UNLOCK(lcd_flag);

        // Toggles every FS (every time the LCD restarts at line 0)
        tihw.io2[0x1d] |= (1 << 7);
    }

    return TRUE;
}

void compute_convtable(void);
void compute_grayscale(void);

int  hid_init(void)
{
    SKIN_INFOS *si = &skin_infos;

    // Found a PC keyboard keymap
    match_keymap(tihw.calc_type);

    // Load kbd keymap
    if(keymap_load(options.keys_file) == -1)
    {
	    gchar *s = g_strdup_printf("unable to load this keymap: <%s>\n", options.keys_file);
	    tiemu_error(0, s);
	    g_free(s);
	    return -1;
    }

    // Found a skin
	match_skin(tihw.calc_type);

    // Load skin
    if(skin_load(options.skin_file) == -1) 
    {
	    gchar *s = g_strdup_printf("unable to load this skin: <%s>\n", options.skin_file);
	    tiemu_error(0, s);
	    g_free(s);
	    return -1;
    }
    skn = skin_infos.image;
  
	// Set skin keymap depending on calculator type
    switch(tihw.calc_type)
    {
    case TI92:
    case TI92p:
    case V200:
        skn_keymap = sknKey92;
        break;
    case TI89:
    case TI89t:
      	skn_keymap = sknKey89;
        break;
    default:
        {
	  	gchar *s = g_strdup_printf("no skin found for this calc\n");
	  	tiemu_error(0, s);
	  	g_free(s);
	  	return -1;
        }
	}

    // Allocate the TI screen buffer
	lcd_bytmap = (uint32_t *)malloc(LCDMEM_W * LCDMEM_H);

    // Allocate the lcd pixbuf
    lcd = gdk_pixbuf_new(GDK_COLORSPACE_RGB, FALSE, 8, LCDMEM_W, LCDMEM_H);
    if(lcd == NULL)
    {
        gchar *s = g_strdup_printf("unable to create LCD pixbuf.\n");
	    tiemu_error(0, s);
	    g_free(s);
	    return -1;
    }
    
	// Constants for LCD update (speed-up)
    li.n_channels = gdk_pixbuf_get_n_channels (lcd);
	li.width = gdk_pixbuf_get_width (lcd);
	li.height = gdk_pixbuf_get_height (lcd);
	li.rowstride = gdk_pixbuf_get_rowstride (lcd);
	li.pixels = gdk_pixbuf_get_pixels (lcd);

	// Create main window
	display_main_wnd();

    // Allocate the backing pixmap
    pixmap = gdk_pixmap_new(main_wnd->window, si->width, si->height, -1);
    if(pixmap == NULL)
    {
        gchar *s = g_strdup_printf("unable to create backing pixbuf.\n");
	    tiemu_error(0, s);
	    g_free(s);
	    return -1;
    }
    
    // Draw the skin and compute grayscale palette
  	compute_grayscale();
  	resize();

    // Init the planar/chunky conversion table for LCD
  	compute_convtable();

    // Install LCD refresh: 100 FPS (10 ms)
    tid = g_timeout_add((params.lcd_rate == -1) ? 10 : params.lcd_rate, 
		(GtkFunction)hid_refresh, NULL);

	hid_lcd_on_off(1);

	// Set scale infos
	sc.w = si->width;
	sc.h = si->height;
	sc.r = (float)sc.w / sc.h;
	sc.s = (float)1.0;

    //test
    //kbd_read_keymap("C:\\sources\\roms\\tiemu\\skins\\ti92+_fr.map", tihw.calc_type);

    return 0;
}

int  hid_exit(void)
{

    // Uninstall LCD refresh
    g_source_remove(tid);

	// Release resources
    if(lcd != NULL)
    {
        g_object_unref(lcd);
        lcd = NULL;
    }

    if(pixmap != NULL)
    {
        g_object_unref(pixmap);
        pixmap = NULL;
    }

    // Destroy window
    gtk_widget_destroy(main_wnd);

    return 0;
}

int hid_switch_with_skin(void)
{
    params.background = 1;
	resize();

    return 0;
}

int hid_switch_without_skin(void)
{
    params.background = 0;
	resize();

    return 0;
}

int hid_change_skin(const char *filename)
{
    int ret1, ret2;
	
	ret1 = hid_exit();
	ret2 = hid_init();
	
	return ret1 | ret2;
}

static gint fullscreen = 0;

int hid_switch_fullscreen(void)
{
	gdk_window_fullscreen(main_wnd->window);
    fullscreen = !0;

	return 0;
}

int hid_switch_windowed(void)
{
	gdk_window_unfullscreen(main_wnd->window);
    fullscreen = 0;

	return 0;
}

int hid_switch_normal_view(void)
{
    if(fullscreen)
        hid_switch_windowed();

    return 0;
}

int hid_switch_large_view(void)
{
    return 0;
}

int  hid_screenshot(char *filename)
{
	gchar *outfile;
	gchar *ext = "???";
	gchar *type = "???";

	GdkPixbuf *pixbuf = { 0 };
	gboolean result = FALSE;
	GError *error = NULL;

	if(filename == NULL) 
	{
		switch(options2.format) 
		{
			case IMG_JPG: ext = "jpg"; type = "jpeg"; break;
			case IMG_PNG: ext = "png"; type = "png";  break;
			case IMG_ICO: ext = "ico"; type = "ico";  break;
			default: type = "???"; break;
		}
      
		outfile = g_strdup_printf("%s%03i.%s", options2.file, options2.counter, ext);
	} 
	else 
	{
		outfile = g_strdup(filename);
	}

	DISPLAY("Screenshot to %s... ", outfile);

	if((options2.size == IMG_LCD) && (options2.type == IMG_BW)) 
	{
		// get pixbuf from buffer	
        return 0;
	} 
	else if((options2.size == IMG_LCD) && (options2.type == IMG_COL)) 
	{
        // get pixbuf from grayscale lcd
		pixbuf = gdk_pixbuf_copy(lcd);
	} 
	else if(options2.size == IMG_SKIN) 
	{
		// get pixbuf from backing pixmap
		pixbuf = gdk_pixbuf_get_from_drawable(
					NULL, main_wnd->window, NULL,
					0, 0, 0, 0, skin_infos.width, skin_infos.height);
	}

	//result = gdk_pixbuf_save(pixbuf, outfile, type, &error, "quality", "100", NULL);
	result = gdk_pixbuf_save(pixbuf, outfile, type, &error, NULL);
	if (result == FALSE) 
	{
		DISPLAY("Failed to save pixbuf file: %s: %s\n", outfile, error->message);
		g_error_free(error);
	}
    g_object_unref(pixbuf);

	DISPLAY("Done !\n");
	options2.counter++;
	g_free(filename);

	return 0;
}


GLADE_CB gboolean
on_calc_wnd_window_state_event         (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
    GdkEventWindowState *wstate = (GdkEventWindowState *)event;
    GdkWindowState state = wstate->new_window_state;
    GdkWindowState mask = wstate->changed_mask;

    //printf("%04X %04X\n", wstate->new_window_state, wstate->changed_mask);

    if((mask & GDK_WINDOW_STATE_ICONIFIED) && (state & GDK_WINDOW_STATE_ICONIFIED))
        gtk_debugger_hide_all();    //gtk_debugger_minimize_all();
        
    else if((mask & GDK_WINDOW_STATE_ICONIFIED) && !(state & GDK_WINDOW_STATE_ICONIFIED))
        gtk_debugger_show_all();    //gtk_debugger_deminimize_all();

    return FALSE;
}
