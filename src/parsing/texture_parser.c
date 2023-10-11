/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:39:02 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/11 16:46:17 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	set_texture_to_img(t_cube *cub, char *str, t_texture *texture)
{
	texture->img = mlx_xpm_file_to_image(cub->mlx, str, \
		&texture->w, &texture->h);
	if (texture->img == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	get_texture(t_cube *cub, char *str, char *to_find)
{
	int		i;
	char	*texture_path;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (!str[i])
		return (EXIT_FAILURE);
	texture_path = ft_strdup(&str[i]);
	if (!texture_path)
		ft_free_exit(cub, MALLOC_ERROR);
	if (ft_strncmp(to_find, "NO", 2))
		if (set_texture_to_img(cub, str, cub->texture[0]) == EXIT_FAILURE)
			return (ft_printf_fd(2, "Wrong texture path\n"), EXIT_FAILURE);
	if (ft_strncmp(to_find, "SO", 2))
		if (set_texture_to_img(cub, str, cub->texture[1]) == EXIT_FAILURE)
			return (ft_printf_fd(2, "Wrong texture path\n"), EXIT_FAILURE);
	if (ft_strncmp(to_find, "WE", 2))
		if (set_texture_to_img(cub, str, cub->texture[2]) == EXIT_FAILURE)
			return (ft_printf_fd(2, "Wrong texture path\n"), EXIT_FAILURE);
	if (ft_strncmp(to_find, "EA", 2))
		if (set_texture_to_img(cub, str, cub->texture[3]) == EXIT_FAILURE)
			return (ft_printf_fd(2, "Wrong texture path\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	check_texture(t_cube *cub, char **file, char *to_find, char c)
{
	int	i;
	int	j;

	i = -1;
	while (file[++i])
	{
		j = -1;
		while (file[i][++j])
		{
			if (file[i][j] == c)
			{
				if (ft_strlen(to_find) == 1 && c == 'F')
					return (get_colors(cub, &file[i][j], j, FLOOR));
				if (ft_strlen(to_find) == 1 && c == 'C')
					return (get_colors(cub, &file[i][j], j, CEILING));
				if (ft_strncmp(&file[i][j], to_find, ft_strlen(to_find)))
					return (get_texture(cub, &file[i][j], to_find));
			}
		}
	}
	return (EXIT_FAILURE);
}

int	init_texture(t_cube *cub, char **file)
{
	if (check_texture(cub, file, "NO", 'N') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_texture(cub, file, "SO", 'S') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_texture(cub, file, "WE", 'W') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_texture(cub, file, "EA", 'E') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_texture(cub, file, "F", 'F') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_texture(cub, file, "C", 'C') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
