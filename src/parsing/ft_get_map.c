/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:07:55 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/13 16:07:46 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	ft_get_index(char **file, int flag);
static size_t	ft_map_len(char **file, size_t size);
static int		ft_fill_map(char **file, char **map, size_t size);
static int		ft_is_subset_of(char const *line, char const *set);

char	**ft_get_map(char **file)
{
	size_t	size;
	char	**map;

	size = ft_get_index(file, 0);
	ft_printf("%d\n", size);
	if (size < 6)
		return (NULL);
	file = file + size;
	size = ft_get_index(file, 1);
	ft_printf("%d\n", size);
	if (size < 3)
		return (NULL);
	map = ft_calloc((size + 1), sizeof(char *));
	if (!map)
		return (NULL);
	if (ft_fill_map(file, map, size))
		return (NULL);
	return (map);
}

static size_t	ft_get_index(char **file, int flag)
{
	size_t	i;
	size_t	j;
	int		count;

	i = 0;
	count = 0;
	while (file && file[i] && flag == ft_is_subset_of(file[i], " 10NSWE"))
	{
		if (!flag && file[i][0] != '\n')
			count++;
		i++;
	}
	if (!flag && count != 6)
		return (0);
	j = i;
	while (flag && file[j])
	{
		if (file[j][0] != '\n')
			return (0);
		j++;
	}
	return (i);
}

static size_t	ft_map_len(char **file, size_t size)
{
	size_t	len;
	size_t	len_max;

	len_max = 0;
	while (size)
	{
		size--;
		len = ft_strlen(file[size]) - 1;
		while (file[size][len] == ' ')
			len--;
		if (file[size][len - 1] != '1')
			return (0);
		if (len > len_max)
			len_max = len;
	}
	return (len_max);
}

static int	ft_fill_map(char **file, char **map, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = ft_map_len(file, size);
	ft_printf("%d\n", len);
	while (i < size)
	{
		map[i] = ft_calloc(len + 1, sizeof(char));
		if (!map[i])
		{
			ft_free_split(map);
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

static int	ft_is_subset_of(char const *line, char const *set)
{
	char	set_map[256];

	if (!line || *line == '\n')
		return (0);
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
