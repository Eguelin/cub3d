/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:50:44 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/13 23:12:01 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_put_square(t_cube *cub, int x, int y, int size)
{
	int	i;
	int	j;
	int	start_y;

	i = -1;
	start_y = y;
	while (++i <= size)
	{
		j = -1;
		y = start_y;
		while (++j <= size)
		{
			my_mlx_pixel_put(&cub->windows, x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}
}

static void	ft_put_player(t_cube *cub, int x, int y, int size)
{
	int	i;
	int	j;
	int	offset;

	offset = (15 - size) / 2;;
	i = -1;
	cub->player.y_start = y + (offset + 1.4);
	cub->player.x_start = x + (offset + 1.4);
	x = cub->player.x_start;
	while (++i <= size)
	{
		j = -1;
		y = cub->player.y_start;
		while (++j <= size)
		{
			my_mlx_pixel_put(&cub->windows, x, y, 0xFFF000);
			y++;
		}
		x++;
	}
	cub->player.y_end = y;
	cub->player.x_end = x;
}

static void	ft_mini_wall(t_cube *cub, char **map, int *x, int *y)
{
	int	i;
	int	j;
	int	x_start;

	i = -1;
	x_start = *x;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				ft_put_square(cub, *x, *y, 15);
			else if (map[i][j] == 'N' || map[i][j] == 'S' \
			|| map[i][j] == 'E' || map[i][j] == 'W')
				ft_put_player(cub, *x, *y, 6);
			*x += 17;
		}
		*x = x_start;
		*y += 17;
	}
}

void	ft_minimap(t_cube *cub, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	cub->windows.img = mlx_new_image(cub->mlx, 1920, 1080);
	cub->windows.addr = mlx_get_data_addr(cub->windows.img, \
	&cub->windows.bits_per_pixel, &cub->windows.line_length, \
	&cub->windows.endian);
	ft_mini_wall(cub, map, &x, &y);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->windows.img, 0, 0);
}
