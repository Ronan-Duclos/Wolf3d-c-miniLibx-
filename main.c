/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:12:58 by rduclos           #+#    #+#             */
/*   Updated: 2014/01/17 15:11:47 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	make_my_mlx(int **map)
{
	t_env		*wolf;
	t_ini		*in;
	t_player	*pl;
	t_wall		*wl;

	wolf = (t_env *)malloc(sizeof(t_env));
	in = (t_ini *)malloc(sizeof(t_ini));
	pl = (t_player *)malloc(sizeof(t_player));
	wl = (t_wall *)malloc(sizeof(t_wall));
	wolf->in = in;
	wolf->pl = pl;
	wolf->wl = wl;
	wolf->mlx = mlx_init();
	wolf->in->width = 1024;
	wolf->in->heigt = 768;
	wolf->win = mlx_new_window(wolf->mlx, 1024, 768, "Wolf3D");
	wolf->map = map;
	wolf = initiate_map(wolf);
	mlx_expose_hook(wolf->win, my_expose_hook, wolf);
	mlx_hook(wolf->win, KeyPress, KeyPressMask, my_key_hook_press, wolf);
	mlx_hook(wolf->win, KeyRelease, KeyReleaseMask, my_key_hook_release, wolf);
	mlx_loop_hook(wolf->mlx, my_mlx_hook_loop, wolf);
	mlx_loop(wolf->mlx);
}

int		my_expose_hook(t_env *e)
{
	int		i;
	double	j;
	double	k;

	i = 0;
	while (i < e->in->width)
	{
		e->pl->cam_x = 2 * i / (double)e->in->width - 1;
		e->pl->rpos_x = e->in->pos_x;
		e->pl->rpos_y = e->in->pos_y;
		e->pl->rdir_x = e->in->dir_x + e->in->plane_x * e->pl->cam_x;
		e->pl->rdir_y = e->in->dir_y + e->in->plane_y * e->pl->cam_x;
		e->pl->map_x = (int)e->pl->rpos_x;
		e->pl->map_y = (int)e->pl->rpos_y;
		j = (e->pl->rdir_y * e->pl->rdir_y) / (e->pl->rdir_x * e->pl->rdir_x);
		k = (e->pl->rdir_x * e->pl->rdir_x) / (e->pl->rdir_y * e->pl->rdir_y);
		e->pl->d2wall_x = sqrt(1 + j);
		e->pl->d2wall_y = sqrt(1 + k);
		e->pl->touche = 0;
		e = make_my_vue(e);
		make_my_line(e, i);
		i++;
	}
	return (0);
}

void	make_my_map(char **map)
{
	int		**mapint;
	int		i;
	int		j;

	i = ft_count_str_of_tab(map) + 1;
	j = verify_nb_line(map) + 1;
	mapint = tab_str_to_int(map, i, j);
	free_tab(map);
	make_my_mlx(mapint);
}

void	test_map(char **map, int fd)
{
	if ((map = verify_my_map(fd)) == NULL)
		ft_putendl_fd("Wolf3d: the file in entrance isn't a map", 2);
	else
		make_my_map(map);
}

int		main(int ac, char **av)
{
	char	**map;
	int		i;
	int		fd;

	map = NULL;
	if (ac < 2)
	{
		if ((map = verify_my_map(0)) == NULL)
			ft_putendl_fd("Wolf3d: the file in entrance isn't a map", 2);
		else
			make_my_map(map);
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			if ((fd = open(av[i++], O_RDONLY)) != -1)
			{
				test_map(map, fd);
				close(fd);
			}
		}
	}
	return (0);
}
