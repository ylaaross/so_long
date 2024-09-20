/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:07:09 by ylaaross          #+#    #+#             */
/*   Updated: 2023/04/16 16:11:25 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		sl;
	int			i;
	int			indice;

	i = 0;
	indice = -1;
	sl = ft_strlen(s) - 1;
	if ((unsigned char)c == '\0')
		return ((char *)(s + sl + 1));
	if (s == 0)
		return (0);
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			indice = i;
			i++;
	}
	if (indice != -1)
		return ((char *)s + indice);
	return (0);
}
