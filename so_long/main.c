/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:47:59 by ylaaross          #+#    #+#             */
/*   Updated: 2023/05/03 20:27:01 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(int errorn)
{
	if (errorn == 1)
	{
		write(2, "Error\n", 6);
		write(2, "Wrong path\n", 11);
	}
	else if (errorn == 2)
	{
		write(2, "Error\n", 6);
		write(2, "Wrong extention or wrong path name\n", 35);
	}
	else
	{
		write(2, "Error\n", 6);
		write(2, "Wrong path or no arg or more args than necessary\n", 49);
	}


	
}

int	main(int argc, char **argv)
{
	int				fd;
	t_player		player;

	if (argc == 2)
	{
		if (file_check(argv[1]))
		{
			fd = file_d(argv[1]);
			if (fd > 0)
			{
				concat_and_store(&player, fd);
				if (equal_lent(&player) && \
				valid_dimention(player.height, player.width) \
				&& wall_check(&player) && \
				check_assets(&player) && test_map(player))
					map_initialise(&player);
			}
			else
				error_message(1);
		}
		else
			error_message(2);
	}
	else
		error_message(3);
}
