/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:00:43 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/18 18:15:56 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_src;

	len_src = ft_strlen(src);
	i = 0;
	j = 0;
	if (!dstsize)
		return (len_src);
	while (dst[i] && i <= dstsize - 1)
		i++;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (j)
		dst[i] = 0;
	if (dstsize < i - j)
		return (dstsize + len_src);
	else
		return (i - j + len_src);
}
