/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_assets_utls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:29:28 by ylaaross          #+#    #+#             */
/*   Updated: 2023/05/03 19:59:19 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialise_assets_variable(t_player	*player, int *i, int *j, int *e)
{
	*i = 0;
	*j = 0;
	*e = 0;
	(*player).px = 0;
	(*player).py = 0;
	(*player).ex = 0;
	(*player).ey = 0;
	(*player).nbrcoins = 0;
}

int	test_assets(int p, int e, t_player *player)
{
	if (p != 1)
	{
		write(2, "Error\n", 6);
		write (1, "no player in the map or more than one player", 44);
		free_2d_map((*player).map);
		exit(1);
		return (0);
	}
	if (e != 1)
	{
		write(2, "Error\n", 6);
		write(2, "no exit or more than one exit", 29);
		free_2d_map((*player).map);
		exit(1);
		return (0);
	}
	if ((*player).nbrcoins == 0)
	{
		write(2, "Error\n", 6);
		write(2, "no coins", 8);
		free_2d_map((*player).map);
		exit(1);
		return (0);
	}
	return (1);
}

void	store_xy_player(t_player *player, int i, int j, int *p)
{
	(*player).px = j;
	(*player).py = i;
	*p = *p + 1;
}

void	destroy_if_exist(t_player *player)
{
	if ((*player).paths.wall_img)
		mlx_destroy_image((*player).vars.mlx, (*player).paths.wall_img);
	if ((*player).paths.ground_img)
		mlx_destroy_image((*player).vars.mlx, (*player).paths.ground_img);
	if ((*player).paths.player_img)
		mlx_destroy_image((*player).vars.mlx, (*player).paths.player_img);
	if ((*player).paths.coins_img)
		mlx_destroy_image((*player).vars.mlx, ((*player).paths.coins_img));
	if ((*player).paths.exitc_img)
		mlx_destroy_image((*player).vars.mlx, (*player).paths.exitc_img);
	if ((*player).paths.exit_img)
		mlx_destroy_image((*player).vars.mlx, (*player).paths.exit_img);
}
