/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_ctl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:42:40 by ylaaross          #+#    #+#             */
/*   Updated: 2023/04/26 19:42:53 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_player *player)
{
	int		x;
	int		y;
	void	*mlx;
	char	*path;

	initialise_xy(&x, &y, &mlx, player);
	if ((*player).map[(*player).py - 1][(*player).px] == 'C')
	{
		(*player).map[(*player).py - 1][(*player).px] = '0';
		(*player).nbrcoins--;
	}
	if ((*player).map[(*player).py][(*player).px] != 'E')
	{
		path = (*player).paths.ground_img;
		mlx_put_image_to_window (mlx, (*player).vars.win, path, x * 32, y * 32);
	}
	if ((*player).map[(*player).py][(*player).px] == 'E')
	{
		path = (*player).paths.exitc_img;
		mlx_put_image_to_window(mlx, (*player).vars.win, path, x * 32, y * 32);
	}
	increment_decrement_value2(player, &y, &path, UP);
	mlx_put_image_to_window (mlx, (*player).vars.win, path, x * 32, y * 32);
	coins_check(player);
}

void	down(t_player *player)
{
	int		x;
	int		y;
	void	*mlx;
	char	*path;

	initialise_xy(&x, &y, &mlx, player);
	if ((*player).map[(*player).py + 1][(*player).px] == 'C')
	{
		(*player).map[(*player).py + 1][(*player).px] = '0';
		(*player).nbrcoins = (*player).nbrcoins - 1;
	}
	if ((*player).map[(*player).py][(*player).px] != 'E')
	{
		path = (*player).paths.ground_img;
		mlx_put_image_to_window (mlx, (*player).vars.win, path, x * 32, y * 32);
	}
	if ((*player).map[(*player).py][(*player).px] == 'E')
	{
		path = (*player).paths.exitc_img;
		mlx_put_image_to_window(mlx, (*player).vars.win, path, x * 32, y * 32);
	}
	increment_decrement_value2(player, &y, &path, DOWN);
	mlx_put_image_to_window (mlx, (*player).vars.win, path, x * 32, y * 32);
	coins_check(player);
}

void	left(t_player *player)
{
	int		x;
	int		y;
	void	*mlx;
	char	*path;

	initialise_xy(&x, &y, &mlx, player);
	if ((*player).map[(*player).py][(*player).px - 1] == 'C')
	{
		(*player).map[(*player).py][(*player).px - 1] = '0';
		(*player).nbrcoins = (*player).nbrcoins - 1;
	}
	if ((*player).map[(*player).py][(*player).px] != 'E')
	{
		path = (*player).paths.ground_img;
		mlx_put_image_to_window (mlx, (*player).vars.win, path, x * 32, y * 32);
	}
	if ((*player).map[(*player).py][(*player).px] == 'E')
	{
		path = (*player).paths.exitc_img;
		mlx_put_image_to_window(mlx, (*player).vars.win, path, x * 32, y * 32);
	}
	increment_decrement_value(player, &x, &path, LEFT);
	mlx_put_image_to_window (mlx, (*player).vars.win, path, x * 32, y * 32);
	coins_check(player);
}

void	right(t_player *player)
{
	int		x;
	int		y;
	void	*mlx;
	char	*path;

	initialise_xy(&x, &y, &mlx, player);
	if ((*player).map[(*player).py][(*player).px + 1] == 'C')
	{
		(*player).map[(*player).py][(*player).px + 1] = '0';
		(*player).nbrcoins--;
	}
	if ((*player).map[(*player).py][(*player).px] != 'E')
	{
		path = (*player).paths.ground_img;
		mlx_put_image_to_window (mlx, (*player).vars.win, path, x * 32, y * 32);
	}
	if ((*player).map[(*player).py][(*player).px] == 'E')
	{
		path = (*player).paths.exitc_img;
		mlx_put_image_to_window(mlx, (*player).vars.win, path, x * 32, y * 32);
	}	
	increment_decrement_value(player, &x, &path, RIGHT);
	mlx_put_image_to_window (mlx, (*player).vars.win, path, x * 32, y * 32);
	coins_check(player);
}
