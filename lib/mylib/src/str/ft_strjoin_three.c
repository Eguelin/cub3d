/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:43:08 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/16 08:51:35 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

char	*ft_strjoin_three(char const *s1, char const *s2, char const *s3)
{
	char	*join;
	size_t	size;

	if (!s1 || !s2 || !s3)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1;
	join = malloc(size);
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, size);
	ft_strlcat(join, s2, size);
	ft_strlcat(join, s3, size);
	return (join);
}
