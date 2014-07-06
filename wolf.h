/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:13:18 by rduclos           #+#    #+#             */
/*   Updated: 2014/01/19 13:22:28 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include </opt/X11/include/X11/X.h>
# include "libft.h"

# define speed 0.05
# define rotspeed 0.03

typedef struct		s_ini
{
	double		width;
	double		heigt;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		time;
	double		old_time;
}					t_ini;

typedef struct		s_player
{
	double		cam_x;
	double		rpos_x;
	double		rpos_y;
	double		rdir_x;
	double		rdir_y;
	int			map_x;
	int			map_y;
	double		dwall_x;
	double		dwall_y;
	double		d2wall_x;
	double		d2wall_y;
	double		size_wall;
	int			stape_x;
	int			stape_y;
	int			touche;
	int			v_or_h;
}					t_player;

typedef struct		s_wall
{
	double	size_wall;
	double	h_wall;
	int		draw_start;
	int		draw_end;
}					t_wall;

typedef struct		s_move
{
	int		left;
	int		right;
	int		front;
	int		back;
}					t_move;

typedef struct		s_env
{
	void		*mlx;
	void		*win;
	int			**map;
	t_ini		*in;
	t_player	*pl;
	t_wall		*wl;
	t_move		*mv;
}					t_env;

/*
main.c
*/
void	make_my_map(char **map);
int		my_expose_hook(t_env *e);
void	make_my_mlx(int **map);
void	test_map(char **map, int fd);
/*
verify1.c
*/
int		verify_nb_line(char **tab);
char	**verify_my_map(int fd);
/*
ft_tools1.c
*/
int		ft_count_nb_in_str(char *str);
int		ft_count_str_of_tab(char **tab);
char	**ft_realloc_char_tab(char **tab, char *line);
void	free_tab(char **tab);
/*
ft_tools2.c
*/
void	make_my_line(t_env *e, int ligne);
t_env	*make_my_vue(t_env *e);
t_env	*initiate_map(t_env *e);
int		**tab_end_of_int(int **tab, int size_str, int size_tab);
int		**tab_str_to_int(char **tab, int size_tab, int size_str);
/*
ft_calcul.c
*/
t_env	*calcul1(t_env *e);
t_env	*calcul2(t_env *e);
t_env	*calcul3(t_env *e);
t_env	*calcul4(t_env *e);
/*
calcul_move.c
*/
t_env	*move_to_front(t_env *e);
t_env	*move_to_back(t_env *e);
t_env	*move_to_right(t_env *e);
t_env	*move_to_left(t_env *e);
/*
make_move.c
*/
int		my_key_hook_press(int keycode, t_env *e);
int		my_key_hook_release(int keycode, t_env *e);
int		my_mlx_hook_loop(t_env *e);

#endif
