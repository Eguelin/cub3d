/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:07:55 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/14 18:16:34 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	ft_get_index(char **file, int flag);
static int		ft_fill_map(char **file, char **map);
static size_t	ft_map_len(char **file);
static int		ft_is_subset_of(char const *line, char const *set);

char	**ft_get_map(char **file)
{
	size_t	size;
	char	**map;

	size = ft_get_index(file, 0);
	if (!size)
		return (NULL);
	file = file + size;
	size = ft_get_index(file, 1);
	if (!size)
		return (NULL);
	map = ft_calloc((size + 1), sizeof(char *));
	if (!map)
	{
		ft_perror(NULL, MALLOC_ERROR);
		return (NULL);
	}
	if (ft_fill_map(file, map))
		return (NULL);
	return (map);
}

static size_t	ft_get_index(char **file, int flag)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (file && file[i] && \
	(file[i][0] == '\n' || flag == ft_is_subset_of(file[i], " 10NSWE")))
	{
		if (!flag && file[i][0] != '\n')
			count++;
		i++;
	}
	if (!flag && count != 6)
	{
		ft_perror(NULL, MAP_ERROR);
		return (0);
	}
	if (flag && file[i])
	{
		ft_perror(NULL, MAP_ERROR);
		return (0);
	}
	return (i);
}

static int	ft_fill_map(char **file, char **map)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = ft_map_len(file);
	while (file[i])
	{
		map[i] = ft_calloc(len + 1, sizeof(char));
		if (!map[i])
		{
			ft_free_split(map);
			ft_perror(NULL, MALLOC_ERROR);
			return (EXIT_FAILURE);
		}
		j = 0;
		while (file[i][j] != '\n' && j < len)
		{
			map[i][j] = file[i][j];
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static size_t	ft_map_len(char **file)
{
	size_t	i;
	size_t	len;
	size_t	len_max;

	i = 0;
	len_max = 0;
	while (file[i])
	{
		len = ft_strlen(file[i]) - 1;
		while (file[i][len] == ' ')
			len--;
		if (len > len_max)
			len_max = len;
		i++;
	}
	return (len_max);
}

static int	ft_is_subset_of(char const *line, char const *set)
{
	char	set_map[256];

	ft_memset(set_map, 0, 256);
	while (*set)
	{
		set_map[(unsigned char)(*set)] = 1;
		set++;
	}
	while (*line && *line != '\n')
	{
		if (!set_map[(unsigned char)(*line)])
			return (0);
		line++;
	}
	return (1);
}
