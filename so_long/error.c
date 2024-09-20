/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:04:16 by ylaaross          #+#    #+#             */
/*   Updated: 2023/05/04 12:10:38 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	empty_last(char *res, char *line)
{
	int	i;

	i = 0;
	while (res[i])
		i++;
	if (res[i - 1] == '\n')
	{
		error_line(2, line);
		exit(1);
	}
}

void	error_line(int nbr, char *line)
{
	if (nbr == 1)
	{
		write(2, "Error\n", 6);
		write(2, "empty map or floder instead of file", 35);
		exit(1);
	}
	else if (nbr == 2)
	{
		free(line);
		write(2, "Error\n", 6);
		write(2, "Ligne vide\n", 11);
		exit(1);
	}
}
