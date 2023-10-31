/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:50:11 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/01 00:34:48 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_calculate_angle_array(t_cub3d *cub);
static void	ft_init_struct(t_cub3d	*cub);

void	ft_init(t_cub3d	*cub, char **argv)
{
	ft_init_struct(cub);
	cub->mlx = mlx_init();
	if (!cub->mlx)
		ft_exit(cub, NULL, MALLOC_ERROR);
	ft_parser(cub, argv);
	cub->mlx_win = mlx_new_window(cub->mlx, LENGTH, HEIGHT, "cub3D");
	if (!cub->mlx_win)
		ft_exit(cub, NULL, MALLOC_ERROR);
	cub->windows = mlx_new_image(cub->mlx, LENGTH, HEIGHT);
	if (!cub->windows)
		ft_exit(cub, NULL, MALLOC_ERROR);
}

static void	ft_init_struct(t_cub3d	*cub)
{
	int	i;

	i = 0;
	cub->mlx = NULL;
	cub->mlx_win = NULL;
	cub->windows = NULL;
	while (i < 4)
	{
		cub->texture[i] = NULL;
		cub->minimap[i] = NULL;
		cub->hook[i] = 0;
		i++;
	}
	while (i < 6)
	{
		cub->hook[i] = 0;
		i++;
	}
	cub->f_colors = -1;
	cub->c_colors = -1;
	cub->map = NULL;
	cub->infile = NULL;
	cub->init_wall = LENGTH_2 / tan(FOV_2);
	ft_calculate_angle_array(cub);
}

static void	ft_calculate_angle_array(t_cub3d *cub)
{
	double	opposite;
	double	adjacent;
	int		i;
	int		size;

	i = 0;
	size = (LENGTH >> 1) + 1;
	adjacent = (double)LENGTH / (2 * tan(FOV_2));
	opposite = (double)LENGTH / 2;
	while (i < size)
	{
		cub->angle[i] = atan(opposite / adjacent);
		opposite--;
		i++;
	}
}
