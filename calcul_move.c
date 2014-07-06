/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 13:13:27 by rduclos           #+#    #+#             */
/*   Updated: 2014/01/15 19:17:20 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_env	*move_to_left(t_env *e)
{
	double	old_dir_x;
	double	old_plane_x;
	double	tmp1;
	double	tmp2;

	old_dir_x = e->in->dir_x;
	tmp1 = e->in->dir_x * cos(rotspeed);
	tmp2 = e->in->dir_y * sin(rotspeed);
	e->in->dir_x = tmp1 - tmp2;
	tmp1 = old_dir_x * sin(rotspeed);
	tmp2 = e->in->dir_y * cos(rotspeed);
	e->in->dir_y = tmp1 + tmp2;
	old_plane_x = e->in->plane_x;
	tmp1 = e->in->plane_x * cos(rotspeed);
	tmp2 = e->in->plane_y * sin(rotspeed);
	e->in->plane_x = tmp1 - tmp2;
	tmp1 = old_plane_x * sin(rotspeed);
	tmp2 = e->in->plane_y * cos(rotspeed);
	e->in->plane_y = tmp1 + tmp2;
	return (e);
}

t_env	*move_to_right(t_env *e)
{
	double	old_dir_x;
	double	old_plane_x;
	double	tmp1;
	double	tmp2;

	old_dir_x = e->in->dir_x;
	tmp1 = e->in->dir_x * cos(-rotspeed);
	tmp2 = e->in->dir_y * sin(-rotspeed);
	e->in->dir_x = tmp1 - tmp2;
	tmp1 = old_dir_x * sin(-rotspeed);
	tmp2 = e->in->dir_y * cos(-rotspeed);
	e->in->dir_y = tmp1 + tmp2;
	old_plane_x = e->in->plane_x;
	tmp1 = e->in->plane_x * cos(-rotspeed);
	tmp2 = e->in->plane_y * sin(-rotspeed);
	e->in->plane_x = tmp1 - tmp2;
	tmp1 = old_plane_x * sin(-rotspeed);
	tmp2 = e->in->plane_y * cos(-rotspeed);
	e->in->plane_y = tmp1 + tmp2;
	return (e);
}

t_env	*move_to_front(t_env *e)
{
	double		i;
	double		j;

	i = e->in->pos_x + e->in->dir_x * speed;
	if (e->map[(int)(i)][(int)(e->in->pos_y)] == 0)
		e->in->pos_x += e->in->dir_x * speed;
	j = e->in->pos_y + e->in->dir_y * speed;
	if (e->map[(int)(e->in->pos_x)][(int)(j)] == 0)
		e->in->pos_y += e->in->dir_y * speed;
	return (e);
}

t_env	*move_to_back(t_env *e)
{
	double		i;
	double		j;

	i = e->in->pos_x - e->in->dir_x * speed;
	j = e->in->pos_y;
	if (e->map[(int)(i)] != NULL && e->map[(int)(i)][(int)(j)] == 0)
		e->in->pos_x -= e->in->dir_x * speed;
	i = e->in->pos_x;
	j = e->in->pos_y - e->in->dir_y * speed;
	if (e->map[(int)(i)] != NULL && e->map[(int)(i)][(int)(j)] == 0)
		e->in->pos_y -= e->in->dir_y * speed;
	return (e);
}
