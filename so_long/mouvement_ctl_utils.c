/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_ctl_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:53:51 by ylaaross          #+#    #+#             */
/*   Updated: 2023/04/26 19:06:25 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	increment_decrement_value(t_player *player, int *x, \
char **path, int action)
{
	if (action == LEFT)
	{
		(*player).px = (*player).px - 1;
		*x = (*player).px;
	}
	else
	{
		(*player).px = (*player).px + 1;
		*x = (*player).px;
	}
	*path = (*player).paths.player_img;
}

void	increment_decrement_value2(t_player *player, int *y, \
char **path, int action)
{
	if (action == UP)
	{
		(*player).py = (*player).py - 1;
		*y = (*player).py;
	}
	else
	{
		(*player).py = (*player).py + 1;
		*y = (*player).py;
	}
	*path = (*player).paths.player_img;
}

void	initialise_xy(int *x, int *y, void **mlx, t_player *player)
{
	*x = (*player).px;
	*y = (*player).py;
	*mlx = (*player).vars.mlx;
}
