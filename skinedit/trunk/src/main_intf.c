/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "main_cb.h"
#include "main_intf.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_main_window (void)
{
  GtkWidget *main_window;
  GtkWidget *vbox1;
  GtkWidget *menubar1;
  GtkWidget *file;
  GtkWidget *file_menu;
  GtkWidget *new;
  GtkWidget *open;
  GtkWidget *save;
  GtkWidget *save_as;
  GtkWidget *separator3;
  GtkWidget *export1;
  GtkWidget *export1_menu;
  GtkWidget *vti_v21;
  GtkWidget *vti_v25;
  GtkWidget *separator1;
  GtkWidget *exit;
  GtkWidget *edit;
  GtkWidget *edit_menu;
  GtkWidget *properties;
  GtkWidget *separator2;
  GtkWidget *lcd_position;
  GtkWidget *key_positions;
  GtkWidget *help;
  GtkWidget *help_menu;
  GtkWidget *about;
  GtkWidget *hbox1;
  GtkWidget *handlebox1;
  GtkWidget *toolbar1;
  GtkWidget *tmp_toolbar_icon;
  GtkWidget *tb_properties;
  GtkWidget *tb_lcd_pos;
  GtkWidget *tb_key_pos;
  GtkWidget *scrolledwindow1;
  GtkWidget *viewport1;
  //  GtkWidget *drawingarea1;
  //  GtkWidget *statusbar;
  GtkAccelGroup *accel_group;

  accel_group = gtk_accel_group_new ();

  main_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (main_window), _("Skinedit"));
  gtk_window_set_default_size (GTK_WINDOW (main_window), 400, 300);

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (main_window), vbox1);

  menubar1 = gtk_menu_bar_new ();
  gtk_widget_show (menubar1);
  gtk_box_pack_start (GTK_BOX (vbox1), menubar1, FALSE, FALSE, 0);

  file = gtk_menu_item_new_with_mnemonic (_("_File"));
  gtk_widget_show (file);
  gtk_container_add (GTK_CONTAINER (menubar1), file);

  file_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (file), file_menu);

  new = gtk_image_menu_item_new_from_stock ("gtk-new", accel_group);
  gtk_widget_show (new);
  gtk_container_add (GTK_CONTAINER (file_menu), new);

  open = gtk_image_menu_item_new_from_stock ("gtk-open", accel_group);
  gtk_widget_show (open);
  gtk_container_add (GTK_CONTAINER (file_menu), open);

  save = gtk_image_menu_item_new_from_stock ("gtk-save", accel_group);
  gtk_widget_show (save);
  gtk_container_add (GTK_CONTAINER (file_menu), save);

  save_as = gtk_image_menu_item_new_from_stock ("gtk-save-as", accel_group);
  gtk_widget_show (save_as);
  gtk_container_add (GTK_CONTAINER (file_menu), save_as);

  separator3 = gtk_menu_item_new ();
  gtk_widget_show (separator3);
  gtk_container_add (GTK_CONTAINER (file_menu), separator3);
  gtk_widget_set_sensitive (separator3, FALSE);

  export1 = gtk_menu_item_new_with_mnemonic (_("Export"));
  gtk_widget_show (export1);
  gtk_container_add (GTK_CONTAINER (file_menu), export1);

  export1_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (export1), export1_menu);

  vti_v21 = gtk_menu_item_new_with_mnemonic (_("VTi v2.1"));
  gtk_widget_show (vti_v21);
  gtk_container_add (GTK_CONTAINER (export1_menu), vti_v21);

  vti_v25 = gtk_menu_item_new_with_mnemonic (_("VTi v2.5"));
  gtk_widget_show (vti_v25);
  gtk_container_add (GTK_CONTAINER (export1_menu), vti_v25);

  separator1 = gtk_menu_item_new ();
  gtk_widget_show (separator1);
  gtk_container_add (GTK_CONTAINER (file_menu), separator1);
  gtk_widget_set_sensitive (separator1, FALSE);

  exit = gtk_image_menu_item_new_from_stock ("gtk-quit", accel_group);
  gtk_widget_show (exit);
  gtk_container_add (GTK_CONTAINER (file_menu), exit);

  edit = gtk_menu_item_new_with_mnemonic (_("_Edit"));
  gtk_widget_show (edit);
  gtk_container_add (GTK_CONTAINER (menubar1), edit);

  edit_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (edit), edit_menu);

  properties = gtk_image_menu_item_new_from_stock ("gtk-properties", accel_group);
  gtk_widget_show (properties);
  gtk_container_add (GTK_CONTAINER (edit_menu), properties);

  separator2 = gtk_menu_item_new ();
  gtk_widget_show (separator2);
  gtk_container_add (GTK_CONTAINER (edit_menu), separator2);
  gtk_widget_set_sensitive (separator2, FALSE);

  lcd_position = gtk_menu_item_new_with_mnemonic (_("_LCD position"));
  gtk_widget_show (lcd_position);
  gtk_container_add (GTK_CONTAINER (edit_menu), lcd_position);

  key_positions = gtk_menu_item_new_with_mnemonic (_("_Key positions"));
  gtk_widget_show (key_positions);
  gtk_container_add (GTK_CONTAINER (edit_menu), key_positions);

  help = gtk_menu_item_new_with_mnemonic (_("_Help"));
  gtk_widget_show (help);
  gtk_container_add (GTK_CONTAINER (menubar1), help);

  help_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (help), help_menu);

  about = gtk_menu_item_new_with_mnemonic (_("About"));
  gtk_widget_show (about);
  gtk_container_add (GTK_CONTAINER (help_menu), about);

  hbox1 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox1);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox1, TRUE, TRUE, 0);

  handlebox1 = gtk_handle_box_new ();
  gtk_widget_show (handlebox1);
  gtk_box_pack_start (GTK_BOX (hbox1), handlebox1, FALSE, TRUE, 0);
  gtk_handle_box_set_handle_position (GTK_HANDLE_BOX (handlebox1), GTK_POS_TOP);

  toolbar1 = gtk_toolbar_new ();
  gtk_widget_show (toolbar1);
  gtk_container_add (GTK_CONTAINER (handlebox1), toolbar1);
  gtk_toolbar_set_style (GTK_TOOLBAR (toolbar1), GTK_TOOLBAR_BOTH);
  gtk_toolbar_set_orientation (GTK_TOOLBAR (toolbar1), GTK_ORIENTATION_VERTICAL);

  tmp_toolbar_icon = create_pixmap (main_window, "prop.xpm");
  tb_properties = gtk_toolbar_append_element (GTK_TOOLBAR (toolbar1),
                                GTK_TOOLBAR_CHILD_BUTTON,
                                NULL,
                                _("Properties"),
                                NULL, NULL,
                                tmp_toolbar_icon, NULL, NULL);
  gtk_label_set_use_underline (GTK_LABEL (((GtkToolbarChild*) (g_list_last (GTK_TOOLBAR (toolbar1)->children)->data))->label), TRUE);
  gtk_widget_show (tb_properties);

  gtk_toolbar_append_space (GTK_TOOLBAR (toolbar1));

  tmp_toolbar_icon = create_pixmap (main_window, "screen.xpm");
  tb_lcd_pos = gtk_toolbar_append_element (GTK_TOOLBAR (toolbar1),
                                GTK_TOOLBAR_CHILD_BUTTON,
                                NULL,
                                _("LCD"),
                                NULL, NULL,
                                tmp_toolbar_icon, NULL, NULL);
  gtk_label_set_use_underline (GTK_LABEL (((GtkToolbarChild*) (g_list_last (GTK_TOOLBAR (toolbar1)->children)->data))->label), TRUE);
  gtk_widget_show (tb_lcd_pos);

  gtk_toolbar_append_space (GTK_TOOLBAR (toolbar1));

  tmp_toolbar_icon = create_pixmap (main_window, "keyboard.xpm");
  tb_key_pos = gtk_toolbar_append_element (GTK_TOOLBAR (toolbar1),
                                GTK_TOOLBAR_CHILD_BUTTON,
                                NULL,
                                _("Keys"),
                                NULL, NULL,
                                tmp_toolbar_icon, NULL, NULL);
  gtk_label_set_use_underline (GTK_LABEL (((GtkToolbarChild*) (g_list_last (GTK_TOOLBAR (toolbar1)->children)->data))->label), TRUE);
  gtk_widget_show (tb_key_pos);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow1);
  gtk_box_pack_start (GTK_BOX (hbox1), scrolledwindow1, TRUE, TRUE, 0);
  GTK_WIDGET_UNSET_FLAGS (scrolledwindow1, GTK_CAN_FOCUS);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow1), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  viewport1 = gtk_viewport_new (NULL, NULL);
  gtk_widget_show (viewport1);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1), viewport1);

  drawingarea1 = gtk_drawing_area_new ();
  gtk_widget_show (drawingarea1);
  gtk_container_add (GTK_CONTAINER (viewport1), drawingarea1);
  gtk_widget_set_events (drawingarea1, GDK_POINTER_MOTION_HINT_MASK | GDK_BUTTON_MOTION_MASK | GDK_BUTTON_PRESS_MASK);

  statusbar = gtk_statusbar_new ();
  gtk_widget_show (statusbar);
  gtk_box_pack_start (GTK_BOX (vbox1), statusbar, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) main_window, "delete_event",
                    G_CALLBACK (on_main_window_delete_destroy_event),
                    NULL);
  g_signal_connect ((gpointer) main_window, "destroy_event",
                    G_CALLBACK (on_main_window_delete_destroy_event),
                    NULL);
  g_signal_connect ((gpointer) new, "activate",
                    G_CALLBACK (on_new_activate),
                    NULL);
  g_signal_connect ((gpointer) open, "activate",
                    G_CALLBACK (on_open_activate),
                    NULL);
  g_signal_connect ((gpointer) save, "activate",
                    G_CALLBACK (on_save_activate),
                    NULL);
  g_signal_connect ((gpointer) save_as, "activate",
                    G_CALLBACK (on_save_as_activate),
                    NULL);
  g_signal_connect ((gpointer) vti_v21, "activate",
                    G_CALLBACK (on_vti_v21_activate),
                    NULL);
  g_signal_connect ((gpointer) vti_v25, "activate",
                    G_CALLBACK (on_vti_v25_activate),
                    NULL);
  g_signal_connect ((gpointer) exit, "activate",
                    G_CALLBACK (on_exit_activate),
                    NULL);
  g_signal_connect ((gpointer) properties, "activate",
                    G_CALLBACK (on_properties_activate),
                    NULL);
  g_signal_connect ((gpointer) lcd_position, "activate",
                    G_CALLBACK (on_lcd_position_activate),
                    NULL);
  g_signal_connect ((gpointer) key_positions, "activate",
                    G_CALLBACK (on_key_positions_activate),
                    NULL);
  g_signal_connect ((gpointer) about, "activate",
                    G_CALLBACK (on_about_activate),
                    NULL);
  g_signal_connect ((gpointer) tb_properties, "clicked",
                    G_CALLBACK (on_tb_properties_clicked),
                    NULL);
  g_signal_connect ((gpointer) tb_lcd_pos, "clicked",
                    G_CALLBACK (on_tb_lcd_pos_clicked),
                    NULL);
  g_signal_connect ((gpointer) tb_key_pos, "clicked",
                    G_CALLBACK (on_tb_key_pos_clicked),
                    NULL);
  g_signal_connect ((gpointer) drawingarea1, "configure_event",
                    G_CALLBACK (on_drawingarea1_configure_event),
                    NULL);
  g_signal_connect ((gpointer) drawingarea1, "expose_event",
                    G_CALLBACK (on_drawingarea1_expose_event),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (main_window, main_window, "main_window");
  GLADE_HOOKUP_OBJECT (main_window, vbox1, "vbox1");
  GLADE_HOOKUP_OBJECT (main_window, menubar1, "menubar1");
  GLADE_HOOKUP_OBJECT (main_window, file, "file");
  GLADE_HOOKUP_OBJECT (main_window, file_menu, "file_menu");
  GLADE_HOOKUP_OBJECT (main_window, new, "new");
  GLADE_HOOKUP_OBJECT (main_window, open, "open");
  GLADE_HOOKUP_OBJECT (main_window, save, "save");
  GLADE_HOOKUP_OBJECT (main_window, save_as, "save_as");
  GLADE_HOOKUP_OBJECT (main_window, separator3, "separator3");
  GLADE_HOOKUP_OBJECT (main_window, export1, "export1");
  GLADE_HOOKUP_OBJECT (main_window, export1_menu, "export1_menu");
  GLADE_HOOKUP_OBJECT (main_window, vti_v21, "vti_v21");
  GLADE_HOOKUP_OBJECT (main_window, vti_v25, "vti_v25");
  GLADE_HOOKUP_OBJECT (main_window, separator1, "separator1");
  GLADE_HOOKUP_OBJECT (main_window, exit, "exit");
  GLADE_HOOKUP_OBJECT (main_window, edit, "edit");
  GLADE_HOOKUP_OBJECT (main_window, edit_menu, "edit_menu");
  GLADE_HOOKUP_OBJECT (main_window, properties, "properties");
  GLADE_HOOKUP_OBJECT (main_window, separator2, "separator2");
  GLADE_HOOKUP_OBJECT (main_window, lcd_position, "lcd_position");
  GLADE_HOOKUP_OBJECT (main_window, key_positions, "key_positions");
  GLADE_HOOKUP_OBJECT (main_window, help, "help");
  GLADE_HOOKUP_OBJECT (main_window, help_menu, "help_menu");
  GLADE_HOOKUP_OBJECT (main_window, about, "about");
  GLADE_HOOKUP_OBJECT (main_window, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (main_window, handlebox1, "handlebox1");
  GLADE_HOOKUP_OBJECT (main_window, toolbar1, "toolbar1");
  GLADE_HOOKUP_OBJECT (main_window, tb_properties, "tb_properties");
  GLADE_HOOKUP_OBJECT (main_window, tb_lcd_pos, "tb_lcd_pos");
  GLADE_HOOKUP_OBJECT (main_window, tb_key_pos, "tb_key_pos");
  GLADE_HOOKUP_OBJECT (main_window, scrolledwindow1, "scrolledwindow1");
  GLADE_HOOKUP_OBJECT (main_window, viewport1, "viewport1");
  GLADE_HOOKUP_OBJECT (main_window, drawingarea1, "drawingarea1");
  GLADE_HOOKUP_OBJECT (main_window, statusbar, "statusbar");

  gtk_window_add_accel_group (GTK_WINDOW (main_window), accel_group);

  return main_window;
}

GtkWidget*
create_filesel (void)
{
  GtkWidget *filesel;
  GtkWidget *filesel_ok;
  GtkWidget *filesel_cancel;

  filesel = gtk_file_selection_new (_("Select File"));
  gtk_container_set_border_width (GTK_CONTAINER (filesel), 10);
  gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);

  filesel_ok = GTK_FILE_SELECTION (filesel)->ok_button;
  gtk_widget_show (filesel_ok);
  GTK_WIDGET_SET_FLAGS (filesel_ok, GTK_CAN_DEFAULT);

  filesel_cancel = GTK_FILE_SELECTION (filesel)->cancel_button;
  gtk_widget_show (filesel_cancel);
  GTK_WIDGET_SET_FLAGS (filesel_cancel, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) filesel, "delete_event",
                    G_CALLBACK (on_filesel_delete_destroy_event),
                    NULL);
  g_signal_connect ((gpointer) filesel, "destroy_event",
                    G_CALLBACK (on_filesel_delete_destroy_event),
                    NULL);
  g_signal_connect ((gpointer) filesel_cancel, "clicked",
                    G_CALLBACK (on_filesel_cancel_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (filesel, filesel, "filesel");
  GLADE_HOOKUP_OBJECT_NO_REF (filesel, filesel_ok, "filesel_ok");
  GLADE_HOOKUP_OBJECT_NO_REF (filesel, filesel_cancel, "filesel_cancel");

  return filesel;
}

