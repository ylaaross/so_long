/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:43:01 by ylaaross          #+#    #+#             */
/*   Updated: 2023/04/30 15:30:18 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid(char c)
{
	if (c == '0' || c == 'C' || c == 'E')
		return (1);
	return (0);
}

void	search(char **t, int *ii, int *jj)
{
	int		i;
	int		j;
	int		f;

	i = 0;
	f = 0;
	while (t[i])
	{
		j = 0;
		while (t[i][j])
		{
			if (t[i][j] == 'P')
			{
				*ii = i;
				*jj = j;
				f = 1;
				break ;
			}
			j++;
		}
		if (f)
			break ;
		i++;
	}
}

void	implement(int *p, int *i, int *pj, int *j)
{
	*p = *i;
	*pj = *j;
}

void	initialise_and_search(char **c, int *i, int *j)
{
	initialise_var_map(i, j);
	search(c, i, j);
}

int	test_map(t_player player)
{
	int		i;
	int		j;
	int		p;
	int		pj;
	char	**c ;

	cp_arr(player, &c);
	initialise_and_search(c, &i, &j);
	implement(&p, &i, &pj, &j);
	while (c[i][j])
	{
		if ((c[i][j - 1] && c[i][j - 1] == 'P') && valid(c[i][j]))
			c[i][j] = 'P';
		j++;
	}
	j = pj - 1;
	while (j >= 0)
	{
		if ((c[p + 1][j] == 'P' && c[p][j] != '1' && c[i][j] != 'E'))
			c[i][j] = 'P';
		j--;
	}
	i++;
	all_possibal_path(c, p, pj);
	return (check_c(c, player));
}
