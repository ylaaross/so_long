/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:24:54 by ylaaross          #+#    #+#             */
/*   Updated: 2023/05/03 19:58:02 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	affiche_return(int message, t_player *player)
{
	if (message == UP)
	{
		write(2, "Error\n", 6);
		write(2, "Problem first row\n", 18);
	}
	else if (message == DOWN)
	{
		write(2, "Error\n", 6);
		write(2, "Problem in the last row\n", 24);
	}
	else if (message == LEFT)
	{
		write(2, "Error\n", 6);
		write(2, "Problem left row\n", 17);
	}
	else
	{
		write(2, "Error\n", 6);
		write (2, "Problem right row\n", 18);
	}
	free_2d_map(player->map);
	return (0);
}

int	wall_check(t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while ((*player).map[i])
	{
		j = 0;
		while ((*player).map[i][j])
		{
			if (i == 0 && (*player).map[i][j] != '1')
				return (affiche_return(UP, player));
			else if ((*player).map[i][0] != '1')
				return (affiche_return(LEFT, player));
			else if ((*player).map[i][(*player).width - 1] != '1')
				return (affiche_return(RIGHT, player));
			else if ((*player).map[(*player).height - 1][j] != '1')
				return (affiche_return(DOWN, player));
			j++;
		}
		i++;
	}
	return (1);
}
