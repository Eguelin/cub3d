/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:46:13 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/30 13:36:52 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void		ft_impact_x(t_cub3d *cub, t_point *impact, double angle);
static void		ft_impact_y(t_cub3d *cub, t_point *impact, double angle);
static double	ft_get_distance(t_point point_1, t_point point_2);

void	ft_ray_casting(t_cub3d *cub, double angle, t_display *display)
{
	t_point	impact_x;
	t_point	impact_y;
	double	distance_x;
	double	distance_y;

	impact_x.x = -1;
	impact_x.y = -1;
	impact_y.x = -1;
	impact_y.y = -1;
	ft_impact_x(cub, &impact_x, cub->player.angle + angle);
	ft_impact_y(cub, &impact_y, cub->player.angle + angle);
	distance_x = ft_get_distance(cub->player.position, impact_x);
	distance_y = ft_get_distance(cub->player.position, impact_y);
	if (distance_x < distance_y)
	{
		display->impact.x = impact_x.x;
		display->impact.y = impact_x.y;
		display->distance = cos(angle) * distance_x;
	}
	else
	{
		display->impact.x = impact_y.x;
		display->impact.y = impact_y.y;
		display->distance = cos(angle) * distance_y;
	}
}

static void	ft_impact_x(t_cub3d *cub, t_point *impact, double angle)
{
	t_point	delta;
	double	cos_a;

	cos_a = cos(angle);
	if (!cos_a)
		return ;
	delta.x = 1;
	impact->x = (int)cub->player.position.x + 1;
	if (cos_a < 0)
	{
		delta.x = -1;
		impact->x--;
	}
	delta.y = delta.x * tan(angle);
	impact->y = cub->player.position.y + delta.y * \
	fabs(impact->x - cub->player.position.x);
	while (impact->y > 0 && (size_t)impact->y < cub->map_height && \
	cub->map[(size_t)impact->y][(size_t)impact->x - (cos_a < 0)] == '0')
	{
		impact->x += delta.x;
		impact->y += delta.y;
	}
}

static void	ft_impact_y(t_cub3d *cub, t_point *impact, double angle)
{
	t_point	delta;
	double	sin_a;

	sin_a = sin(angle);
	if (!sin_a)
		return ;
	delta.y = 1;
	impact->y = (int)cub->player.position.y + 1;
	if (sin_a < 0)
	{
		delta.y = -1;
		impact->y--;
	}
	delta.x = delta.y / tan(angle);
	impact->x = cub->player.position.x + delta.x * \
	fabs(impact->y - cub->player.position.y);
	while (impact->x > 0 && (size_t)impact->x < cub->map_width && \
	cub->map[(size_t)impact->y - (sin_a < 0)][(size_t)impact->x] == '0')
	{
		impact->x += delta.x;
		impact->y += delta.y;
	}
}

static double	ft_get_distance(t_point point_1, t_point point_2)
{
	t_point	delta;

	delta.x = point_1.x - point_2.x;
	delta.y = point_1.y - point_2.y;
	return (sqrt(delta.x * delta.x + delta.y * delta.y));
}
