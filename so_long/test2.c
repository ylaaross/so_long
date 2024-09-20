/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 22:12:31 by ylaaross          #+#    #+#             */
/*   Updated: 2023/05/03 20:35:40 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_m_wasd(t_player *player, int action)
{
	if (action == UP)
	{
		up(player);
		(*player).movement = (*player).movement + 1;
		ft_putnbr((*player).movement);
	}
	else if (action == DOWN)
	{
		down(player);
		(*player).movement = (*player).movement + 1;
		ft_putnbr((*player).movement);
	}
	else if (action == LEFT)
	{
		left(player);
		(*player).movement = (*player).movement + 1;
		ft_putnbr((*player).movement);
	}
	else
	{
		right(player);
		(*player).movement = (*player).movement + 1;
		ft_putnbr((*player).movement);
	}
}

void	free_all_images(t_player *player)
{
	mlx_destroy_image((*player).vars.mlx, (*player).paths.coins_img);
	mlx_destroy_image((*player).vars.mlx, (*player).paths.exit_img);
	mlx_destroy_image((*player).vars.mlx, (*player).paths.exitc_img);
	mlx_destroy_image((*player).vars.mlx, (*player).paths.ground_img);
	mlx_destroy_image((*player).vars.mlx, (*player).paths.player_img);
	mlx_destroy_image((*player).vars.mlx, (*player).paths.wall_img);
	free_2d_map((*player).map);
}

int	key_hook(int keycode, t_player *player)
{
	void	*mlx;

	mlx = (*player).vars.mlx;
	if (keycode == UP && (*player).map[(*player).py - 1][(*player).px] != '1')
		print_m_wasd(player, UP);
	else if (keycode == DOWN && \
	(*player).map[(*player).py + 1][(*player).px] != '1')
		print_m_wasd(player, DOWN);
	else if (keycode == LEFT && \
	(*player).map[(*player).py][(*player).px - 1] != '1')
		print_m_wasd(player, LEFT);
	else if (keycode == RIGHT && \
	(*player).map[(*player).py][(*player).px + 1] != '1')
		print_m_wasd(player, RIGHT);
	else if (keycode == ESC)
	{
		free_all_images(player);
		exit(0);
	}
	return (0);
}

int	size(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	file_check(char *path)
{
	int		i;
	char	*s;

	s = 0;
	i = 0;
	s = ft_strchr(path, '.');
	if (!s)
		return (0);
	if (ft_strcmp(s, ".ber") == 0)
	{
		if (size(path) == 4)
			return (0);
		return (1);
	}
	return (0);
}
