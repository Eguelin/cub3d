/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:20:54 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/30 15:13:52 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_get_texture_ratio(t_cub3d *cub, t_display *display);
static void	ft_get_column(t_cub3d *cub, t_display display, int x_win);
static void	ft_get_ceiling_floor(\
t_cub3d *cub, int wall_size, int wall_sart, int x_win);

void	ft_visual_field(t_cub3d *cub)
{
	int			i;
	int			j;
	t_display	display;

	i = 0;
	j = 0;
	while (i < LENGTH)
	{
		if (i < LENGTH_2)
			ft_ray_casting(cub, -cub->angle[j++], &display);
		else if (i == LENGTH_2 && LENGTH & 1)
			ft_ray_casting(cub, -cub->angle[j], &display);
		else
			ft_ray_casting(cub, cub->angle[j--], &display);
		ft_get_texture_ratio(cub, &display);
		ft_get_column(cub, display, i);
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->windows, 0, 0);
}

static void	ft_get_texture_ratio(t_cub3d *cub, t_display *display)
{
	display->wall_size = ((size_t)WALL_SIZE * 10000) / \
	(size_t)(display->distance * 10000);
	display->texture = cub->texture[0];
	display->ratio_x = display->impact.x - (size_t)display->impact.x;
	if (!display->ratio_x)
	{
		display->texture = cub->texture[3];
		display->ratio_x = display->impact.y - (size_t)display->impact.y;
		if (cub->player.position.x > display->impact.x)
		{
			display->texture = cub->texture[2];
			display->ratio_x = 1 - display->ratio_x;
		}
	}
	else if (cub->player.position.y < display->impact.y)
	{
		display->texture = cub->texture[1];
		display->ratio_x = 1 - display->ratio_x;
	}
	display->ratio_y = (double)display->texture->height / \
	(double)display->wall_size;
}

static void	ft_get_column(t_cub3d *cub, t_display display, int x_win)
{
	int		i;
	int		j;
	int		index_1;

	i = 0;
	j = 0;
	if (HEIGHT > display.wall_size)
		i = (HEIGHT - display.wall_size) >> 1;
	else
		j = (display.wall_size - HEIGHT) >> 1;
	ft_get_ceiling_floor(cub, display.wall_size, i, x_win);
	index_1 = cub->windows->width * i + x_win;
	while (i < HEIGHT && j < display.wall_size)
	{
		((int *)cub->windows->data)[index_1] = \
		((int *)display.texture->data)[(display.texture->width * (int)(j * \
		display.ratio_y)) + (int)(display.texture->width * display.ratio_x)];
		index_1 += cub->windows->width;
		i++;
		j++;
	}
}

static void	ft_get_ceiling_floor(\
t_cub3d *cub, int wall_size, int wall_sart, int x_win)
{
	int		i;
	int		index_1;

	i = 0;
	index_1 = x_win;
	while (i < wall_sart)
	{
		((int *)cub->windows->data)[index_1] = cub->c_colors;
		index_1 += cub->windows->width;
		i++;
	}
	index_1 += wall_size * cub->windows->width;
	i += wall_size;
	while (i < HEIGHT)
	{
		((int *)cub->windows->data)[index_1] = cub->f_colors;
		index_1 += cub->windows->width;
		i++;
	}
}
