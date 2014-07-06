/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 16:05:38 by rduclos           #+#    #+#             */
/*   Updated: 2014/01/23 21:08:13 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	make_my_line(t_env *e, int ligne)
{
	int		i;

	i = 0;
	while (i < e->in->heigt)
	{
		if (i < e->wl->draw_start)
			mlx_pixel_put(e->mlx, e->win, ligne, i, 0x333333);
		else if (i >= e->wl->draw_start && i <= e->wl->draw_end)
		{
			if (e->pl->v_or_h == 1 && e->pl->rdir_y < 0)
				mlx_pixel_put(e->mlx, e->win, ligne, i, 0xBC8F8F);
			else if (e->pl->v_or_h == 0 && e->pl->rdir_x < 0)
				mlx_pixel_put(e->mlx, e->win, ligne, i, 0xC0C0C0);
			else if (e->pl->v_or_h == 0)
				mlx_pixel_put(e->mlx, e->win, ligne, i, 0xF08080);
			else if (e->pl->v_or_h == 1)
					mlx_pixel_put(e->mlx, e->win, ligne, i, 0x778899);
		}
		else if (i > e->wl->draw_end)
			mlx_pixel_put(e->mlx, e->win, ligne, i, 0x663300);
		i++;
	}
}

t_env	*make_my_vue(t_env *e)
{
	e = calcul1(e);
	e = calcul2(e);
	e = calcul3(e);
	e = calcul4(e);
	return (e);
}

t_env	*initiate_map(t_env *e)
{
	t_move		*mv;

	mv = (t_move *)malloc(sizeof(t_move));
	e->mv = mv;
	e->mv->left = 0;
	e->mv->right = 0;
	e->mv->front = 0;
	e->mv->back = 0;
	e->in->pos_x = 2;
	e->in->pos_y = 2;
	e->in->dir_x = -1;
	e->in->dir_y = 0;
	e->in->plane_x = 0;
	e->in->plane_y = 0.66;
	e->in->time = 0;
	e->in->old_time = 0;
	return (e);
}

int		**tab_end_of_int(int **tab, int size_str, int size_tab)
{
	int		i;
	int		j;

	j = 0;
	i = size_tab;
	tab[i] = (int *)malloc(sizeof(int) * size_str);
	while (j < size_str)
	{
		tab[i][j] = -1;
		j++;
	}
	i++;
	tab[i] = NULL;
	return (tab);
}

int		**tab_str_to_int(char **tab, int size_tab, int size_str)
{
	int		i;
	int		j;
	int		k;
	int		**tabint;

	tabint = (int **)malloc(sizeof(int *) * (size_tab + 1));
	i = 0;
	while (tab[i] != NULL)
	{
		tabint[i] = (int *)malloc(sizeof(int) * size_str);
		j = 0;
		k = 0;
		while(tab[i][j] != '\0')
		{
			if (ft_isdigit(tab[i][j]) == 1)
				tabint[i][k++] = (tab[i][j] - 48);
			j++;
		}
		tabint[i][k] = -1;
		i++;
	}
	tabint = tab_end_of_int(tabint, size_str, i);
	return (tabint);
}
