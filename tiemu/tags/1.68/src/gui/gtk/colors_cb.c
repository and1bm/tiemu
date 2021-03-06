#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "colors_cb.h"
#include "colors_dbox.h"
#include "support.h"

#include "platform.h"
#include "struct.h"
#include "ticalc.h"
#include "main.h"

/***************************/
/* 'Number of colors' dbox */
/***************************/

gint tmp_gray_scales;

gint display_ncolors_dbox()
{
  GtkWidget *dbox;
  gpointer user_data;

  dbox = create_ncolors_dbox();
  tmp_gray_scales = (options.params)->n_grayplanes;
  
  user_data = gtk_object_get_data(GTK_OBJECT(dbox), "radiobutton24");
  if(tmp_gray_scales == 0)
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (user_data), TRUE);

  user_data = gtk_object_get_data(GTK_OBJECT(dbox), "radiobutton25");
  if(tmp_gray_scales == 2)
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (user_data), TRUE);

  user_data = gtk_object_get_data(GTK_OBJECT(dbox), "radiobutton26");
  if(tmp_gray_scales == 5)
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (user_data), TRUE);

  user_data = gtk_object_get_data(GTK_OBJECT(dbox), "radiobutton27");
  if(tmp_gray_scales == 11)
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (user_data), TRUE);

  gtk_widget_show_all(dbox);
  return 0;
}

void
on_radiobutton24_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  tmp_gray_scales = 0;
}


void
on_radiobutton25_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  tmp_gray_scales = 2;
}


void
on_radiobutton26_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  tmp_gray_scales = 5;
}


void
on_radiobutton27_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  tmp_gray_scales = 11;
}


void
on_button29_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  (options.params)->n_grayplanes = tmp_gray_scales;
  gtk_widget_destroy(user_data);
}


void
on_button30_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_widget_destroy(user_data);
}


void
on_ncolors_dbox_destroy                (GtkObject       *object,
                                        gpointer         user_data)
{
  unhalt();
}

/* */
