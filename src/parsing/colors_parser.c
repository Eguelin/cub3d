/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:36:33 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/18 15:54:36 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_colors_range(char **tab)
{
	int	i;
	int	j;
	int rgb[3];

	i = 0;
	while (tab[i] && i <= 2)
	{
		j = 0;
		if (i == 0)
			while (tab[i][++j] == ' ')
				;
		rgb[i] = ft_atouch(&tab[i][j]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (-1);
		i++;
	}
	if (i != 3 || tab[i])
		return (-2);
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

static int	set_colors(t_cub3d *cub, char **tab, int view)
{
	if (view == FLOOR)
	{
		cub->f_colors = check_colors_range(tab);
		if (cub->f_colors == -1)
			return (ft_perror("range", COLORS_ERROR));
		else if (cub->f_colors == -2)
			return (ft_perror("format", COLORS_ERROR));
	}
	else
	{
		cub->c_colors = check_colors_range(tab);
		if (cub->c_colors == -1)
			return (ft_perror("range", COLORS_ERROR));
		else if (cub->c_colors == -2)
			return (ft_perror("format", COLORS_ERROR));
	}
	return (EXIT_SUCCESS);
}

int	get_colors(t_cub3d *cub, char *str, int view)
{
	int	i;
	char	**tab;

	i = 1;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\n' && !str[i + 1])
		return (ft_perror("empty colors", COLORS_ERROR));
	while (str[i] && str[i + 1])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',')
			return (ft_perror("format", COLORS_ERROR));
		i++;
	}
	tab = ft_split(str, ',');
	if (!tab)
		return (MALLOC_ERROR);
	if (set_colors(cub, tab, view) == EXIT_FAILURE)
		return (ft_free_tab(tab), EXIT_FAILURE);
	ft_free_tab(tab);
	return (EXIT_SUCCESS);
}
