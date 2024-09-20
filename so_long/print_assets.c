/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:55:29 by ylaaross          #+#    #+#             */
/*   Updated: 2023/05/03 19:59:02 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	print_assets(t_player *player, int assets, int i, int j)
{
	if (assets == PLAYER)
	{
		mlx_put_image_to_window((*player).vars.mlx, (*player).vars.win, \
		(*player).paths.ground_img, j * 32, i * 32);
		mlx_put_image_to_window((*player).vars.mlx, (*player).vars.win, \
		(*player).paths.player_img, j * 32, i * 32);
	}
	else if (assets == COINS)
	{
		mlx_put_image_to_window((*player).vars.mlx, (*player).vars.win, \
		(*player).paths.ground_img, j * 32, i * 32);
		mlx_put_image_to_window((*player).vars.mlx, (*player).vars.win, \
		(*player).paths.coins_img, j * 32, i * 32);
	}
	else if (assets == EXITC)
	{
		mlx_put_image_to_window((*player).vars.mlx, (*player).vars.win, \
		(*player).paths.ground_img, j * 32, i * 32);
		mlx_put_image_to_window((*player).vars.mlx, (*player).vars.win, \
		(*player).paths.exitc_img, j * 32, i * 32);
	}
}

void	print_map(t_player *player)
{
	int		i;
	int		j;

	i = 0;
	while ((*player).map[i])
	{
		j = 0;
		while ((*player).map[i][j])
		{
			if ((*player).map[i][j] == '1')
				mlx_put_image_to_window((*player).vars.mlx, (*player).vars.win, \
				(*player).paths.wall_img, j * 32, i * 32);
			else if ((*player).map[i][j] == 'P')
				print_assets(player, PLAYER, i, j);
			else if ((*player).map[i][j] == 'C')
				print_assets(player, COINS, i, j);
			else if ((*player).map[i][j] == '0')
				mlx_put_image_to_window((*player).vars.mlx, (*player).vars.win, \
				(*player).paths.ground_img, j * 32, i * 32);
			else
				print_assets(player, EXITC, i, j);
			j++;
		}
		i++;
	}
}

void	testpaths(t_player *player)
{
	if (!(*player).paths.wall_img || !(*player).paths.ground_img || \
	!(*player).paths.player_img || !(*player).paths.coins_img \
	||! (*player).paths.exitc_img || !(*player).paths.exit_img)
	{
		write(2, "Error\n", 6);
		write(2, "wrong path images\n", 18);
		free_2d_map(player->map);
		destroy_if_exist(player);
		exit(1);
	}
}

void	paths_imgs_initialise(t_player *player)
{
	int		width;
	int		height;
	void	*mlx;

	mlx = (*player).vars.mlx;
	(*player).paths.wall_path = "textures/AnyConv.com__beehives2.xpm";
	(*player).paths.coins_path = "textures/AnyConv.com__broad_axe3.xpm";
	(*player).paths.ground_path = "textures/demonic_red8.xpm";
	(*player).paths.player_path = "textures/daeva.xpm";
	(*player).paths.exitc_path = "textures/AnyConv.com__closed_door_crypt.xpm";
	(*player).paths.exit_path = "textures/AnyConv.com__open_door_crypt.xpm";
	(*player).paths.wall_img = \
	mlx_xpm_file_to_image(mlx, (*player).paths.wall_path, &width, &height);
	(*player).paths.ground_img = \
	mlx_xpm_file_to_image(mlx, (*player).paths.ground_path, &width, &height);
	(*player).paths.player_img = \
	mlx_xpm_file_to_image(mlx, (*player).paths.player_path, &width, &height);
	(*player).paths.coins_img = \
	mlx_xpm_file_to_image(mlx, (*player).paths.coins_path, &width, &height);
	(*player).paths.exitc_img = \
	mlx_xpm_file_to_image(mlx, (*player).paths.exitc_path, &width, &height);
	(*player).paths.exit_img = \
	mlx_xpm_file_to_image(mlx, (*player).paths.exit_path, &width, &height);
	testpaths(player);
}

void	coins_check(t_player *player)
{
	int		x;
	int		y;
	void	*mlx;
	char	*path;

	x = (*player).ex;
	y = (*player).ey;
	mlx = (*player).vars.mlx;
	if ((*player).nbrcoins == 0)
	{
		path = (*player).paths.ground_img;
		mlx_put_image_to_window (mlx, (*player).vars.win, path, x * 32, y * 32);
		path = (*player).paths.exit_img;
		mlx_put_image_to_window (mlx, (*player).vars.win, path, x * 32, y * 32);
	}
	if ((*player).nbrcoins == 0 && (*player).px == x && (*player).py == y)
	{
		write(1, "congratulations\n", 16);
		free_all_images(player);
		exit(0);
	}
}
