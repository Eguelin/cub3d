/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:39:02 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/15 15:42:27 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	set_texture_to_img(t_cub3d *cub, char *str, int i)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len -1] = '\0';
	cub->texture[i].img = mlx_xpm_file_to_image(cub->mlx, str, \
	&cub->texture[i].w, &cub->texture[i].h);
	if (!cub->texture[i].img)
		return (EXIT_FAILURE);
	ft_printf_fd(2, "%s successfully added !\n", str);
	return (EXIT_SUCCESS);
}

static int	get_texture(t_cub3d *cub, char *str, char *to_find)
{
	int		i;

	i = ft_strlen(str);
	if (i > 0 && str[i - 1] == '\n')
		str[i -1] = '\0';
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return (ft_perror("Is empty !", SORT_ERROR), EXIT_SUCCESS);
	if (!ft_strncmp(to_find, "NO", 2))
		if (set_texture_to_img(cub, &str[i], 0) == EXIT_FAILURE)
			return (ft_perror("texture not found", SORT_ERROR), EXIT_SUCCESS);
	if (!ft_strncmp(to_find, "SO", 2))
		if (set_texture_to_img(cub, &str[i], 1) == EXIT_FAILURE)
			return (ft_perror("texture not found", SORT_ERROR), EXIT_SUCCESS);
	if (!ft_strncmp(to_find, "WE", 2))
		if (set_texture_to_img(cub, &str[i], 2) == EXIT_FAILURE)
			return (ft_perror("texture not found", SORT_ERROR), EXIT_SUCCESS);
	if (!ft_strncmp(to_find, "EA", 2))
		if (set_texture_to_img(cub, &str[i], 3) == EXIT_FAILURE)
			return (ft_perror("texture not found", SORT_ERROR), EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

static int	check_texture(t_cub3d *cub, char **file, char *to_find, char c)
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
					return (get_colors(cub, &file[i][j + 1], FLOOR));
				if (!ft_strncmp(file[i], to_find, 2) && c == 'C')
					return (get_colors(cub, &file[i][j + 1], CEILING));
				if (!ft_strncmp(file[i], to_find, 2))
					return (get_texture(cub, &file[i][j + 2], to_find));
				count++;
			}
		}
	}
	return (EXIT_FAILURE);
}

int	init_texture(t_cub3d *cub, char **file)
{
	if (check_texture(cub, file, "NO", 'N') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_texture(cub, file, "SO", 'S') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_texture(cub, file, "WE", 'W') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_texture(cub, file, "EA", 'E') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_texture(cub, file, "F ", 'F') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_texture(cub, file, "C ", 'C') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
