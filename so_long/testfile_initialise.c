/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfile_initialise.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:57:10 by ylaaross          #+#    #+#             */
/*   Updated: 2023/05/03 22:09:11 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_d(char *path)
{
	int	fd;

	fd = open (path, O_RDONLY);
	if (fd < 0)
		return (0);
	else
		return (fd);
}

int	ft_close(t_player *player)
{
	(void) player;
	free_all_images(player);
	exit(0);
}

void	map_initialise(t_player *player)
{
	(*player).movement = 0;
	(*player).vars.mlx = mlx_init();
	(*player).vars.win = mlx_new_window((*player).vars.mlx, \
	(*player).width * 32, (*player).height * 32, "warrior of fate");
	paths_imgs_initialise(player);
	print_map(player);
	mlx_key_hook((*player).vars.win, key_hook, player);
	mlx_hook((*player).vars.win, 17, 0, ft_close, player);
	mlx_loop((*player).vars.mlx);
}
