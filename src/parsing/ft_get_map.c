/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:07:55 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/15 15:00:09 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	ft_get_index(char **file, int flag);
static int		ft_fill_map(char **file, char **map);
static size_t	ft_map_len(char **file);
static int		ft_is_subset_of(char const *line, char const *set);

void	ft_get_map(t_cub3d *cub, char **file)
{
	size_t	size;

	cub->map = NULL;
	size = ft_get_index(file, 0);
	file = file + size;
	size = ft_get_index(file, 1);
	if (!size)
	{
		ft_free_tab(file);
		ft_exit(NULL, NULL, MAP_ERROR);
	}
	cub->map = ft_calloc((size + 1), sizeof(char *));
	if (!cub->map)
	{
		ft_free_tab(file);
		ft_exit(NULL, NULL, MALLOC_ERROR);
	}
	if (ft_fill_map(file, cub->map))
	{
		ft_free_tab(file);
		ft_exit(cub, NULL, MALLOC_ERROR);
	}
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
		return (0);
	if (flag && file[i])
		return (0);
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
			return (EXIT_FAILURE);
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
