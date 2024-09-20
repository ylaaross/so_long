/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:03:37 by ylaaross          #+#    #+#             */
/*   Updated: 2023/04/30 10:44:45 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	p = 0;
	i = 0;
	if (size == SIZE_MAX)
		return (0);
	p = (char *)malloc(count * size);
	if (p == 0)
		return (0);
	else
	{
		while (i < count * size)
			p[i++] = 0;
	}
	return (p);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;
	size_t		i;
	size_t		ls;	

	p = 0;
	i = 0;
	ls = ft_strlen(s);
	if (start > ls)
		return ((char *)ft_calloc(1, 1));
	if (len > ls)
		len = ls - start;
	p = (char *)malloc(len + 1);
	if (!p)
		return (0);
	while (s [start + i] && i < len)
	{
		p[i] = s [start + i];
		i++;
	}
		p[i] = '\0';
	return (p);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
	dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lend;
	size_t	lens;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	lens = ft_strlen(src);
	lend = ft_strlen(dst);
	if (lend > dstsize)
		return (lens + dstsize);
	if (lend < dstsize)
	{
		while (src[i] && ((lend + i) < (dstsize - 1)))
		{
		dst[lend + i] = src[i];
		i++;
		}
		dst [lend + i] = '\0';
	}
	return (lend + lens);
}
