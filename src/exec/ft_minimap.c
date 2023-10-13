/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:50:44 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/13 16:16:42 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	my_mlx_pixel_put(t_texture *txr, int x, int y, int color)
{
	char	*dst;

	dst = txr->addr + (y * txr->line_length + \
	x * (txr->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void	ft_put_square(t_cube *cub, int x, int y)
{
	int	i;
	int	j;
	int	start_y;

	i = -1;
	start_y = y;
	while (++i <= 15)
	{
		j = -1;
		y = start_y;
		while (++j <= 15)
		{
			my_mlx_pixel_put(&cub->Windows, x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}
}

static void	ft_mini_wall(t_cube *cub, char **map, int *x, int *y)
{
	int	i;
	int	j;
	int	len;
	int	width;
	int	x_start;
	int	y_start;

	y_start = *y;
	x_start = *x;
	len = ft_count_map_len(map);
	width = ft_count_map_line(map);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				ft_put_square(cub, *x, *y);
			else
				*x += 16;
			*x += 1;
		}
		*x = x_start;
		*y = (y_start + (17 * i));
	}
}

void	ft_minimap(t_cube *cub, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	cub->Windows.img = mlx_new_image(cub->mlx, 1920, 1080);
	cub->Windows.addr = mlx_get_data_addr(cub->Windows.img, \
	&cub->Windows.bits_per_pixel, &cub->Windows.line_length, \
	&cub->Windows.endian);
	ft_mini_wall(cub, map, &x, &y);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->Windows.img, 0, 0);
}
