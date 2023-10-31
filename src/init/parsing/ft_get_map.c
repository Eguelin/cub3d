/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:07:55 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/31 16:05:40 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static size_t	ft_get_index(char **file, int flag);
static int		ft_fill_map(char **start_map, t_cub3d *cub);
static size_t	ft_map_len(char **start_map);
static int		ft_is_subset_of(char const *line, char const *set);

void	ft_get_map(t_cub3d *cub, char **file)
{
	char	**start_map;

	cub->map_height = ft_get_index(file, 0);
	start_map = file + cub->map_height;
	cub->map_height = ft_get_index(start_map, 1);
	if (!cub->map_height)
		ft_exit(cub, NULL, MAP_ERROR);
	cub->map = ft_calloc((cub->map_height + 1), sizeof(char *));
	if (!cub->map || ft_fill_map(start_map, cub))
		ft_exit(cub, NULL, MALLOC_ERROR);
	if (ft_check_map(cub, start_map))
		ft_exit(cub, NULL, MAP_ERROR);
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
		if (!flag && file[i][0])
			count++;
		i++;
	}
	if (!flag && count != 6)
		return (0);
	j = i;
	while (flag && file[j])
	{
		if (ft_is_subset_of(file[j], " 10NSWE"))
			return (0);
		j++;
	}
	return (i);
}

static int	ft_fill_map(char **start_map, t_cub3d *cub)
{
	size_t	i;
	size_t	j;

	i = 0;
	cub->map_width = ft_map_len(start_map);
	while (i < cub->map_height)
	{
		cub->map[i] = ft_calloc(cub->map_width + 1, sizeof(char));
		if (!cub->map[i])
			return (EXIT_FAILURE);
		j = 0;
		while (start_map[i][j] && j < cub->map_width)
		{
			cub->map[i][j] = start_map[i][j];
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static size_t	ft_map_len(char **start_map)
{
	size_t	i;
	size_t	len;
	size_t	len_max;

	i = 0;
	len_max = 0;
	while (start_map[i])
	{
		len = ft_strlen(start_map[i]);
		if (len > len_max)
			len_max = len;
		i++;
	}
	return (len_max);
}

static int	ft_is_subset_of(char const *line, char const *set)
{
	char	set_map[256];

	if (!*line)
		return (0);
	ft_memset(set_map, 0, 256);
	while (*set)
	{
		set_map[(unsigned char)(*set)] = 1;
		set++;
	}
	while (*line)
	{
		if (!set_map[(unsigned char)(*line)])
			return (0);
		line++;
	}
	return (1);
}
