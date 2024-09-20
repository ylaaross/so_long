/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:54 by ylaaross          #+#    #+#             */
/*   Updated: 2023/05/03 19:59:24 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	store_xy_exit(t_player *player, int i, int j, int *e)
{
	(*player).ex = j;
	(*player).ey = i;
	*e = *e + 1;
}

void	invalid_letter(t_player *player)
{
	write(2, "Error\n", 6);
	write(2, "invalid letter in the map", 25);
	free_2d_map(player->map);
	exit(1);
}

int	test(char character)
{
	if (character == '1' || character == '0')
		return (1);
	return (0);
}

int	check_assets(t_player *player)
{
	int		i;
	int		j;
	int		p;
	int		e;

	initialise_assets_variable(player, &i, &j, &e);
	p = 0;
	while ((*player).map[i])
	{
		j = 0;
		while ((*player).map[i][j])
		{
			if ((*player).map[i][j] == 'P')
				store_xy_player(player, i, j, &p);
			else if ((*player).map[i][j] == 'C')
				(*player).nbrcoins = (*player).nbrcoins + 1;
			else if ((*player).map[i][j] == 'E')
				store_xy_exit(player, i, j, &e);
			else if (!(test((*player).map[i][j])))
				invalid_letter(player);
			j++;
		}
		i++;
	}
	return (test_assets(p, e, player));
}
