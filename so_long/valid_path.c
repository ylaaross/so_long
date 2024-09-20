/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 23:27:03 by ylaaross          #+#    #+#             */
/*   Updated: 2023/05/03 20:00:14 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	possibble_path_p1(char **t, int i, int *j)
{
	while (t[i][*j])
	{
		if ((valid(t[i][*j])) && (t[i + 1][*j] && t[i + 1][*j] == 'P'))
			t[i][*j] = 'P';
		else if (valid(t[i][*j]) && (t[i - 1][*j] && t[i - 1][*j] == 'P'))
			t[i][*j] = 'P';
		else if (valid(t[i][*j]) && (t[i][*j - 1] && t[i][*j - 1] == 'P'))
			t[i][*j] = 'P';
		*j = *j + 1;
	}
}

void	possibble_path_p2(char **t, int i, int j)
{
	while (j)
	{
		if (valid(t[i][j]) && (t[i + 1][j] && t[i + 1][j] == 'P'))
			t[i][j] = 'P';
		else if (valid(t[i][j]) && (t[i - 1][j] && t[i - 1][j] == 'P'))
			t[i][j] = 'P';
		else if (valid(t[i][j]) && (t[i][j + 1] && t[i][j + 1] == 'P'))
			t[i][j] = 'P';
		j--;
	}
}

void	all_possibal_path(char **t, int p, int pj)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	while (k < p * pj)
	{
		i = 0;
		while (t[i])
		{
			j = 0;
			possibble_path_p1(t, i, &j);
			possibble_path_p2(t, i, j);
			i++;
		}
		k++;
	}
}

void	initialise_var_map(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

int	check_c(char **c, t_player player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c[i])
	{
		j = 0;
		while (c[i][j])
		{
			if (c[i][j] == 'E' || c[i][j] == 'C')
			{
				write(2, "Error\n", 6);
				write(2, "Invalid path\n", 13);
				free_2d_map(player.map);
				free_2d_map(c);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_2d_map(c);
	return (1);
}
