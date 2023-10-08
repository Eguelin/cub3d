/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:18:34 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/18 18:17:07 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

static size_t	ft_start(char const *s1, char const *set);
static size_t	ft_end(char const *s1, char const *set);
static int		ft_test_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*s2;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (end < start)
		end = start - 1;
	s2 = malloc(end - start + 2);
	if (!s2)
		return (NULL);
	i = 0;
	while (start < end + 1)
	{
		s2[i] = s1[start];
		start++;
		i++;
	}
	s2[i] = 0;
	return (s2);
}

static size_t	ft_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_test_set(s1[i], set) && s1[i])
		i++;
	return (i);
}

static size_t	ft_end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (ft_test_set(s1[i], set) && i)
		i--;
	return (i);
}

static int	ft_test_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
