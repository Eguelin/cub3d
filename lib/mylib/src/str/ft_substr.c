/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:24:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/18 18:17:16 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	if (start > len_s)
		s2 = malloc(1);
	else if (len_s - start < len)
		s2 = malloc(len_s - start + 1);
	else
		s2 = malloc(len + 1);
	if (!s2)
		return (NULL);
	while (i < len && i < len_s - start && !(start >= len_s))
	{
		s2[i] = (s + start)[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
