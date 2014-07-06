/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 16:58:59 by rduclos           #+#    #+#             */
/*   Updated: 2014/01/15 19:13:34 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_env	*calcul1(t_env *e)
{
	double		i;

	if (e->pl->rdir_x < 0)
	{
		e->pl->stape_x = -1;
		i = e->pl->rpos_x - (double)e->pl->map_x;
		e->pl->dwall_x = i * e->pl->d2wall_x;
	}
	else
	{
		e->pl->stape_x = 1;
		i = (double)e->pl->map_x + 1.0 - e->pl->rpos_x;
		e->pl->dwall_x = i * e->pl->d2wall_x;
	}
		return (e);
}

t_env	*calcul2(t_env *e)
{
	double		i;

	if (e->pl->rdir_y < 0)
	{
		e->pl->stape_y = -1;
		i = e->pl->rpos_y - (double)e->pl->map_y;
		e->pl->dwall_y = i * e->pl->d2wall_y;
	}
	else
	{
		e->pl->stape_y = 1;
		i = e->pl->map_y + 1.0 - e->pl->rpos_y;
		e->pl->dwall_y = i * e->pl->d2wall_y;
	}
	return (e);
}

t_env	*calcul3(t_env *e)
{
	while (e->pl->touche == 0)
	{
		if (e->pl->dwall_x < e->pl->dwall_y)
		{
			e->pl->dwall_x += e->pl->d2wall_x;
			e->pl->map_x += e->pl->stape_x;
			e->pl->v_or_h = 0;
		}
		else
		{
			e->pl->dwall_y += e->pl->d2wall_y;
			e->pl->map_y += e->pl->stape_y;
			e->pl->v_or_h = 1;
		}
		if (e->map[e->pl->map_x][e->pl->map_y] > 0)
			e->pl->touche = 1;
	}
	return (e);
}

t_env	*calcul4(t_env *e)
{
	double		i;
	double		j;

	if (e->pl->v_or_h == 0)
	{
		i = e->pl->map_x - e->pl->rpos_x;
		j = i + (1 - e->pl->stape_x) / 2;
		e->wl->size_wall = fabs(j / e->pl->rdir_x);
	}
	else
	{
		i = e->pl->map_y - e->pl->rpos_y;
		j = i + (1 - e->pl->stape_y) / 2;
		e->wl->size_wall = fabs(j / e->pl->rdir_y);
	}
	e->wl->h_wall = fabs((int)(e->in->heigt / e->wl->size_wall));
	e->wl->draw_start = -e->wl->h_wall / 2 + e->in->heigt / 2;
	if (e->wl->draw_start < 0)
		e->wl->draw_start = 0;
	e->wl->draw_end = e->wl->h_wall / 2 + e->in->heigt / 2;
	if (e->wl->draw_end >= e->in->heigt)
		e->wl->draw_end = e->in->heigt - 1;
	return (e);
}
