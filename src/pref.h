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

#ifndef __PREF_H__
#define __PREF_H__


#include <gtk/gtk.h>


#ifndef PATH_MAX
# ifdef MAXPATHLEN
#  define PATH_MAX MAXPATHLEN
# else
#  define PATH_MAX 8192
# endif
#endif

enum {
  PREF_PAGE_PLAYER = 0,
  PREF_PAGE_GAMES,
  PREF_PAGE_APPEARANCE,
  PREF_PAGE_QSTAT,
  PREF_PAGE_QWQ2
};

extern	char *user_rcdir;

extern  char 	*default_name;
extern  char 	*default_team;
extern  char 	*default_qw_skin;
extern  char 	*default_q2_skin;
extern  int 	default_q1_top_color;
extern  int 	default_q1_bottom_color;
extern  int 	default_qw_top_color;
extern  int 	default_qw_bottom_color;

extern  int 	default_rate;
extern  int 	default_cl_nodelta;
extern  int 	default_cl_predict;
extern  int 	default_noaim;
extern  int 	default_noskins;
extern  int 	default_b_switch;
extern  int 	default_w_switch;

extern	int 	pushlatency_mode;
extern	int 	pushlatency_value;

extern  int 	default_nosound;
extern  int 	default_nocdaudio;

extern	int	show_hostnames;
extern	int	show_default_port;

extern	int	default_terminate;
extern	int	default_iconify;
extern	int	default_launchinfo;
extern	int	default_prelaunchexec;
extern  int 	default_save_lists;
extern	int 	default_save_srvinfo;
extern	int 	default_save_plrinfo;
extern	int	default_auto_favorites;
extern	int	default_always_resolve;
extern	int	default_toolbar_style;
extern	int	default_toolbar_tips;
extern	int	default_refresh_sorts;
extern	int	default_refresh_on_update;

extern	int	maxretries;
extern	int	maxsimultaneous;

extern	int set_working_dir (char *dir);
extern  void preferences_dialog (int page_num);
extern	int fix_qw_player_color (int color);

extern	int init_user_info (void);
extern	void free_user_info (void);

extern	int prefs_load (void);


#endif /* __PREF_H__ */

