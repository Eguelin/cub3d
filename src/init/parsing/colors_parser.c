/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:36:33 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/01 14:03:26 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_colors_range(char **tab)
{
	int	i;
	int	j;
	int	rgb[3];

	i = 0;
	while (tab[i] && i < 3)
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
			return (EXIT_FAILURE);
		else if (cub->f_colors == -2)
			return (EXIT_FAILURE);
	}
	else
	{
		cub->c_colors = check_colors_range(tab);
		if (cub->c_colors == -1)
			return (EXIT_FAILURE);
		else if (cub->c_colors == -2)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static void	check_colors_format(t_cub3d *cub, char *str)
{
	int		j;
	int		i;

	j = 0;
	i = 1;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\n' && !str[i + 1])
		ft_exit(cub, "empty colors", COLORS_ERROR);
	while (str[i])
	{
		if (str[i] == ',')
			j++;
		if (!ft_isdigit(str[i]) && str[i] != ',')
			ft_exit(cub, "format", COLORS_ERROR);
		i++;
	}
	if (j != 2)
		ft_exit(cub, "format", COLORS_ERROR);
}

void	get_colors(t_cub3d *cub, char *str, int view)
{
	char	**tab;

	check_colors_format(cub, str);
	tab = ft_split(str, ',');
	if (!tab)
		ft_exit(cub, NULL, MALLOC_ERROR);
	if (set_colors(cub, tab, view) == EXIT_FAILURE)
	{
		ft_free_tab(tab);
		ft_exit(cub, "format", COLORS_ERROR);
	}
	ft_free_tab(tab);
}
