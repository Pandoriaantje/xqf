/* XQF - Quake server browser and launcher
 * Copyright (C) 1998-2000 Roman Pozlevich <roma@botik.ru>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

#ifndef __XQF_UI_H__
#define __XQF_UI_H__

#include <gtk/gtk.h>


struct clist_column {
  const char *name;
  int	width;
  GtkJustification justify;
  GtkWidget *widget;
};


enum cwidget_type {
  CWIDGET_CLIST = 0,
  CWIDGET_CTREE
};


struct clist_def {
  enum cwidget_type type;
  char *name;

  struct clist_column *cols;

  int	columns;
  GtkSelectionMode mode;

  int	width;
  int	height;

  int   sort_column;
  GtkSortType sort_type;
};

extern	struct clist_def server_clist_def;
extern	struct clist_def player_clist_def;
extern	struct clist_def srvinf_clist_def;

extern	GtkWidget *pane1_widget;
extern  GtkWidget *pane2_widget;
extern  GtkWidget *pane3_widget;

extern	void print_status (GtkWidget *sbar, char *fmt, ...);

extern	int window_delete_event_callback (GtkWidget *widget, gpointer data);
extern	void register_window (GtkWidget *window);
extern	void unregister_window (GtkWidget *window);
extern	GtkWidget *top_window (void);

extern	GtkWidget *create_cwidget (GtkWidget *scrollwin, 
                                                     struct clist_def *cldef);

extern	int clist_change_sort_mode (struct clist_def *cldef, int col);

extern	void clist_set_sort_column (GtkCList *clist, int column, 
                                                     struct clist_def *cldef);

extern	void source_ctree_show_node_status (GtkWidget *ctree, 
                                                            struct master *m);

extern	void source_ctree_add_master (GtkWidget *ctree, struct master *m);
extern	void source_ctree_delete_master (GtkWidget *ctree, struct master *m);
extern	GtkWidget *create_source_ctree (GtkWidget *scrollwin);
extern	void source_ctree_select_source (struct master *m);

extern	int calculate_clist_row_height (GtkWidget *clist, GdkPixmap *pixmap);

extern	void set_toolbar_appearance (GtkToolbar *toolbar, int style, int tips);

extern	GtkWidget *create_progress_bar (void);
extern	void progress_bar_reset (GtkWidget *pbar);
extern	void progress_bar_start (GtkWidget *pbar, int activity_mode);
extern	void progress_bar_set_percentage (GtkWidget *pbar, float percentage);

extern	void ui_done (void);
extern	void restore_main_window_geometry ();


#endif /* __XQF_UI_H__ */