/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:55:39 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/25 17:19:37 by eguelin          ###   ########lyon.fr   */
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

void	ft2(t_cub3d *cub, double a)
{
	t_point	impact;
	t_point	tmp;

	tmp.y = tan(cub->player.angle + a);
	impact.x = (int)cub->player.position.x + (cos(a) > 0);;
	impact.y = cub->player.position.y + (tmp.y * (1.0 - modf(cub->player.position.x, &tmp.x)));
	tmp.x = 1;
	while (cub->map[(int)impact.y][(int)impact.x] == '0')
	{
		impact.x += tmp.x;
		impact.y += tmp.y;
	}
	printf("x = %lf y = %lf d1 = %lf d2 = %lf\n", impact.x, impact.y,sqrt((cub->player.position.x - impact.x) * (cub->player.position.x - impact.x) + (cub->player.position.y - impact.y) * (cub->player.position.y - impact.y)), cos(a) * sqrt((cub->player.position.x - impact.x) * (cub->player.position.x - impact.x) + (cub->player.position.y - impact.y) *(cub->player.position.y - impact.y)));
}

void	ft(t_cub3d *cub, double a, double a2)
{
	t_point	impact;
	t_point	tmp;

	if (fabs(cos(a)) > fabs(sin(a)))
	{
		tmp.x = 1 * (cos(a) > 0) + -1 * (cos(a) < 0);
		tmp.y = tmp.x * tan(a);
		impact.x = (int)cub->player.position.x + (cos(a) > 0);
		impact.y = cub->player.position.y + tmp.y * fabs(impact.x - cub->player.position.x);
		impact.x -= (cos(a) < 0);
	}
	else
	{
		tmp.y = 1 * (sin(a) > 0) + -1 * (sin(a) < 0);
		tmp.x = tmp.y / tan(a);
		impact.y = (int)cub->player.position.y + (sin(a) > 0);
		impact.x = cub->player.position.x + tmp.x * fabs(impact.y - cub->player.position.y);
		impact.y -= (sin(a) < 0);
	}
	while (cub->map[(int)impact.y][(int)impact.x] == '0')
	{
		impact.x += tmp.x;
		impact.y += tmp.y;
	}
	if (fabs(cos(a)) > fabs(sin(a)))
		impact.x += (cos(a) < 0);
	else
		impact.y += (sin(a) < 0);
	printf("x = %lf y = %lf d1 = %lf d2 = %lf\n", impact.x, impact.y, sqrt((cub->player.position.x - impact.x) * (cub->player.position.x - impact.x) + (cub->player.position.y - impact.y) * (cub->player.position.y - impact.y)), cos(a2) * sqrt((cub->player.position.x - impact.x) * (cub->player.position.x - impact.x) + (cub->player.position.y - impact.y) * (cub->player.position.y - impact.y)));
}

int	main(int argc, char **argv, char **env)
{
	t_cub3d	cub;

	if (check_init(argc, env) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	ft_parser(&cub, argv);
	ft_calculate_angle_array(&cub);
	ft(&cub, cub.player.angle - cub.angle[0], -cub.angle[0]);
	// ft2(&cub, -cub.angle[0]);
	ft_exit(&cub, NULL, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
