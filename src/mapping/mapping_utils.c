/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:49:34 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/18 12:49:36 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_texture *txr, int x, int y, int color)
{
	char	*dst;

	dst = txr->addr + (y * txr->line_length + \
	x * (txr->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_count_map_len(char **map)
{
	int	i;
	int	j;
	int	max;

	max = ft_strlen(map[0]);
	i = 0;
	while (map[i] && map[i][0] != '\0' && map[i + 1])
	{
		ft_printf_fd(2, "len === %s\n", map[i]);
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		if (max < j)
			max = j;
		i++;
	}
	return (max);
}

int	ft_count_map_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
