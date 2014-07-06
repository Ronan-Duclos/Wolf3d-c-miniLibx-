/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 18:45:57 by rduclos           #+#    #+#             */
/*   Updated: 2014/01/15 19:18:50 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		my_key_hook_press(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(-1);
	if (keycode == 65361)
		e->mv->left = 1;
	if (keycode == 65363)
		e->mv->right = 1;
	if (keycode == 65362)
		e->mv->front = 1;
	if (keycode == 65364)
		e->mv->back = 1;
	return (0);
}

int		my_key_hook_release(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(-1);
	if (keycode == 65361)
		e->mv->left = 0;
	if (keycode == 65363)
		e->mv->right = 0;
	if (keycode == 65362)
		e->mv->front = 0;
	if (keycode == 65364)
		e->mv->back = 0;
	return (0);
}

int		my_mlx_hook_loop(t_env *e)
{
	if (e->mv->left == 1)
		e = move_to_left(e);
	if (e->mv->right == 1)
		e = move_to_right(e);
	if (e->mv->front == 1)
		e = move_to_front(e);
	if (e->mv->back == 1)
		e = move_to_back(e);
	my_expose_hook(e);
	return (0);
}
