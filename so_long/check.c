/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:44:45 by ylaaross          #+#    #+#             */
/*   Updated: 2023/05/04 12:10:22 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ligne_vide(char *line, char *res, int nbr_error)
{
	if (nbr_error == 1)
	{
		if (!line)
		{
			if (res)
				free(res);
			error_line(1, line);
		}
		if (line && ft_strcmp(line, "\n") == 0)
		{
			if (res)
				free(res);
			error_line(2, line);
		}
	}
	else
	{
		if (line && ft_strcmp(line, "\n") == 0)
		{
			if (res)
				free(res);
			error_line(2, line);
		}
	}
}

void	concat_and_store(t_player *player, int fd)
{
	char	*res;
	char	*line;

	res = calloc(1, 1);
	line = get_next_line(fd);
	ligne_vide(line, res, 1);
	if (line)
	{
		res = ft_strjoin(res, line);
		free(line);
	}
	while (line)
	{
		line = get_next_line(fd);
		ligne_vide(line, res, 2);
		if (line)
		{
			res = ft_strjoin (res, line);
			free(line);
		}
	}
	empty_last(res, line);
	(*player).map = ft_split(res, '\n');
	close(fd);
	free(res);
}

int	strlen_w_n(char *t)
{
	int		i;

	i = 0;
	while (t[i] && t[i] != '\n')
		i++;
	return (i);
}

void	initialise_v(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

int	equal_lent(t_player *player)
{
	int		i;
	int		j;
	int		oldlent;

	initialise_v(&i, &j);
	(*player).height = 0;
	(*player).width = 0;
	while ((*player).map[i])
	{
		if (i != 0)
		{
			if (oldlent != strlen_w_n((*player).map[i]))
			{
				write(2, "Error\n", 6);
				write(2, "Not equal lenghts\n", 18);
				free_2d_map(player->map);
				return (0);
			}
		}
		oldlent = strlen_w_n((*player).map[i]);
		i++;
	}
	(*player).height = i;
	(*player).width = oldlent;
	return (1);
}
