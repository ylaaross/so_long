/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:14:19 by ylaaross          #+#    #+#             */
/*   Updated: 2023/05/03 19:59:31 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

int	valid_dimention(int tall, int width)
{
	if (tall > width)
	{
		if (tall >= 5 && width >= 3)
			return (1);
		return (0);
	}
	else
		if (tall >= 3 && width >= 5)
			return (1);
	return (0);
}

void	free_2d_map(char **table)
{
	int		i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

void	test_malloc(char **c, int end, int cas, t_player player)
{
	int	i;

	i = 0;
	if (cas == 2)
	{
		if (!c)
		{
			free_2d_map (player.map);
			exit(1);
		}
	}
	else if (cas == 1)
	{
		if (!c)
		{
			while (i < end)
			{
				free (c[i]);
				i++;
			}
			free_2d_map (player.map);
			exit(1);
		}
	}	
}

void	cp_arr(t_player p, char ***c)
{
	int		i;
	int		j;

	initialise_v(&i, &j);
	*c = malloc(sizeof(char *) * (p.height + 1));
	test_malloc(*c, 0, 2, p);
	while (i < p.height)
	{
		(*c)[i] = malloc(sizeof(char) * (p.width + 1));
		test_malloc(*c, 0, 1, p);
		i++;
	}
	i = 0;
	while (p.map[i])
	{
		j = 0;
		while (p.map[i][j])
		{
			(*c)[i][j] = p.map[i][j];
			j++;
		}
			(*c)[i][j] = 0;
		i++;
	}
	(*c)[i] = 0;
}
