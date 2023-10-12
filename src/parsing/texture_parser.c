/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:39:02 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/12 00:27:17 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_path(char *str)
{
	int	fd;

	fd = open(str, 0);
	if (fd == -1)
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}

static int	set_texture_to_img(t_cube *cub, char *str, t_texture *texture)
{
	if (is_valid_path(str) == EXIT_SUCCESS)
	{
		cub->mlx = mlx_init();
		ft_printf_fd(2, "%s\n", str);
		texture->img = mlx_xpm_file_to_image(cub->mlx, str, \
			&texture->w, &texture->h);
		if (texture->img == NULL)
		{
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
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
	if (!ft_strncmp(to_find, "NO", 2))
		if (set_texture_to_img(cub, str, cub->texture[0]) == EXIT_FAILURE)
			return (ft_printf_fd(2, "Wrong texture path\n"), EXIT_SUCCESS);
	if (!ft_strncmp(to_find, "SO", 2))
		if (set_texture_to_img(cub, str, cub->texture[1]) == EXIT_FAILURE)
			return (ft_printf_fd(2, "Wrong texture path\n"), EXIT_SUCCESS);
	if (!ft_strncmp(to_find, "WE", 2))
		if (set_texture_to_img(cub, str, cub->texture[2]) == EXIT_FAILURE)
			return (ft_printf_fd(2, "Wrong texture path\n"), EXIT_SUCCESS);
	if (!ft_strncmp(to_find, "EA", 2))
		if (set_texture_to_img(cub, str, cub->texture[3]) == EXIT_FAILURE)
			return (ft_printf_fd(2, "Wrong texture path\n"), EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

static int	check_texture(t_cube *cub, char **file, char *to_find, char c)
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
				if (ft_strlen(to_find) == 1 && c == 'F')
					return (get_colors(cub, &file[i][j], j, FLOOR));
				if (ft_strlen(to_find) == 1 && c == 'C')
					return (get_colors(cub, &file[i][j], j, CEILING));
				if (!ft_strncmp(file[i], to_find, 2))
					return (get_texture(cub, &file[i][j], to_find));
				count++;
			}
		}
	}
	return (EXIT_FAILURE);
}

int	init_texture(t_cube *cub, char **file)
{
	int	check;

	if (check_texture(cub, file, "NO", 'N') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_texture(cub, file, "SO", 'S') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_texture(cub, file, "WE", 'W') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_texture(cub, file, "EA", 'E') == EXIT_FAILURE)
		return (EXIT_FAILURE);
	check = check_texture(cub, file, "F", 'F');
	if (check == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (check == MALLOC_ERROR)
		return (MALLOC_ERROR);
	check = check_texture(cub, file, "C", 'C');
	if (check == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (check == MALLOC_ERROR)
		return (MALLOC_ERROR);
	return (EXIT_SUCCESS);
}
