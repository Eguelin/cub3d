/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:39:02 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/01 11:41:04 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	set_texture_to_img(t_cub3d *cub, char *str, int i)
{
	int	len;
	int	w;
	int	h;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len -1] = '\0';
	cub->texture[i] = mlx_xpm_file_to_image(cub->mlx, str, \
	&w, &h);
	if (!cub->texture[i])
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	get_texture(t_cub3d *cub, char *str, char *to_find)
{
	int		i;

	i = ft_strlen(str);
	if (i > 0 && str[i - 1] == '\n')
		str[i -1] = '\0';
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		ft_exit(cub, "Is empty !", SORT_ERROR);
	if (!ft_strncmp(to_find, "NO", 2))
		if (set_texture_to_img(cub, &str[i], 0) == EXIT_FAILURE)
			ft_exit(cub, "texture not found", SORT_ERROR);
	if (!ft_strncmp(to_find, "SO", 2))
		if (set_texture_to_img(cub, &str[i], 1) == EXIT_FAILURE)
			ft_exit(cub, "texture not found", SORT_ERROR);
	if (!ft_strncmp(to_find, "WE", 2))
		if (set_texture_to_img(cub, &str[i], 2) == EXIT_FAILURE)
			ft_exit(cub, "texture not found", SORT_ERROR);
	if (!ft_strncmp(to_find, "EA", 2))
		if (set_texture_to_img(cub, &str[i], 3) == EXIT_FAILURE)
			ft_exit(cub, "texture not found", SORT_ERROR);
}

static void	check_texture(t_cub3d *cub, char **file, char *to_find, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (file[++i] && count != 5)
	{
		j = -1;
		while (file[i][++j])
		{
			if (file[i][j] == c)
			{
				if (!ft_strncmp(file[i], to_find, 2) && c == 'F')
					get_colors(cub, &file[i][j + 1], FLOOR);
				if (!ft_strncmp(file[i], to_find, 2) && c == 'C')
					get_colors(cub, &file[i][j + 1], CEILING);
				if (!ft_strncmp(file[i], to_find, 2))
					get_texture(cub, &file[i][j + 2], to_find);
				count++;
			}
		}
	}
}

void	init_texture(t_cub3d *cub, char **file)
{
	check_texture(cub, file, "NO", 'N');
	check_texture(cub, file, "SO", 'S');
	check_texture(cub, file, "WE", 'W');
	check_texture(cub, file, "EA", 'E');
	check_texture(cub, file, "F ", 'F');
	check_texture(cub, file, "C ", 'C');
}
