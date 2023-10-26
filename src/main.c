/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:55:39 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/26 20:01:22 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_init(int argc, char **env)
{
	if (!env)
		return (ft_printf_fd(STDERR_FILENO, "empty env !\n"), ENV_ERROR);
	if (argc != 2)
	{
		if (argc > 2)
			return (ft_perror(NULL, WRONG_FORMAT));
		else
			return (ft_perror(NULL, WRONG_FORMAT_BIS));
		return (WRONG_FORMAT);
	}
	return (EXIT_SUCCESS);
}

// void	ft_visual_field(t_cub3d *cub)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (i < LENGTH)
// 	{
// 		if (i < LENGTH >> 1)
// 			cub->player.angle - cub->angle[j++];
// 		else if (i == LENGTH >> 1 && LENGTH & 1)
// 			cub->player.angle - cub->angle[j];
// 		else
// 			cub->player.angle + cub->angle[j--];
// 		i++;
// 	}
// }

void	ft_impact_x(t_cub3d *cub, t_point *impact, double angle)
{
	t_point	delta;
	double	cos_a;

	cos_a = cos(angle);
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

void	ft_impact_y(t_cub3d *cub, t_point *impact, double angle)
{
	t_point	delta;
	double	sin_a;

	sin_a = sin(angle);
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

double	ft_get_distance(t_point point_1, t_point point_2)
{
	t_point	delta;

	delta.x = point_1.x - point_2.x;
	delta.y = point_1.y - point_2.y;
	return (sqrt(delta.x * delta.x + delta.y * delta.y));
}

void	ft(t_cub3d *cub, double angle)
{
	t_point	impact_x;
	t_point	impact_y;
	double	distance_x;
	double	distance_y;

	impact_x.x = -1;
	impact_x.y = -1;
	impact_y.x = -1;
	impact_y.y = -1;
	if (cos(cub->player.angle - angle))
		ft_impact_x(cub, &impact_x, cub->player.angle - angle);
	if (sin(cub->player.angle - angle))
		ft_impact_y(cub, &impact_y, cub->player.angle - angle);
	distance_x = ft_get_distance(cub->player.position, impact_x);
	distance_y = ft_get_distance(cub->player.position, impact_y);
	printf("x = %lf y = %lf d1 = %lf d2 = %lf\n", \
	impact_x.x, impact_x.y, distance_x, cos(angle) * distance_x);
	printf("x = %lf y = %lf d1 = %lf d2 = %lf\n", \
	impact_y.x, impact_y.y, distance_y, cos(angle) * distance_y);
}

int	main(int argc, char **argv, char **env)
{
	t_cub3d	cub;

	if (check_init(argc, env) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	ft_parser(&cub, argv);
	ft_calculate_angle_array(&cub);
	ft(&cub, -cub.angle[0]);
	ft_exit(&cub, NULL, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
