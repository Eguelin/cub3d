/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:36:33 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/11 15:39:47 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_colors_range(t_cube *cub, char *str)
{
	char	*range;
	int		len;

	len = 0;
	while (str[len] && str[len++] != ',')
		len++;
	if (!str[len])
		return (-1);
	range = ft_strndup(str, len);
	if (!range)
		ft_free_exit(cub, ERROR_MALLOC);
	len = ft_atoi(range);
	free(range);
	if (len >= 0 && len <= 255)
		return (-1);
	return (len);
}

static int	create_rgb(int rgb, int value)
{
	if (value == 0)
		return ((rgb >> 16) & 0xFF);
	else if (value == 1)
		return ((rgb >> 8) & 0xFF);
	else if (value == 2)
		return (rgb & 0xFF);
	else
		return (rgb);
}

static int	set_colors(t_cube *cub, char *str, int *val, int view)
{
	if (view == FLOOR)
	{
		cub->f_colors += check_colors_range(cub, str);
		if (cub->f_colors == EXIT_FAILURE)
			return (ft_printf_fd(2, "Error, wrong range colors\n"), ERR_COLOR);
		cub->f_colors += create_rgb(cub->f_colors, *val);
	}
	else
	{
		cub->c_colors += check_colors_range(cub, str);
		if (cub->c_colors == EXIT_FAILURE)
			return (ft_printf_fd(2, "Error, wrong range colors\n"), ERR_COLOR);
		cub->c_colors += create_rgb(cub->c_colors, *val);
	}
	*val += 1;
	return (EXIT_SUCCESS);
}

int	get_colors(t_cube *cub, char *str, int i, int view)
{
	int		value;

	value = 0;
	cub->f_colors = 0;
	cub->c_colors = 0;
	while (str[++i] && ft_isdigit(str[i]))
		if (ft_isalpha(str[i]))
			return (ft_printf_fd(2, "Error, wrong format colors\n"), ERR_COLOR);
	if (!str[i])
		return (EXIT_FAILURE);
	while (str[i] && value != 3)
	{
		if (str[i] == ',' && str[i + 1] && ft_isdigit(str[i + 1]))
			set_colors(cub, &str[i], &value, view);
		i++;
	}
	if (value != 3)
		return (ft_printf_fd(2, "Error, wrong format colors\n"), ERR_COLOR);
	return (EXIT_SUCCESS);
}
