/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:39:02 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/10 17:42:14 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_texture(t_cube *cube, char *file, int start)
{
	int		fd;
	char	*texture_path;
	
	while (file[start] != '.')
		start++;
	texture_path = ft_strdup(file[start]);
	if (!texture_path)
		return (NULL, ft_printf_fd(2, "Malloc error\n"));
	fd = open(texture_path, 0);
	if (fd == -1)
		return (NULL, ft_printf_fd(2, "Error, texture file can't be opened\n"));
	close(texture_path);
	return (texture_path);
}

static char *check_texture(t_cube *cube, char **file, char *to_find, char c)
{
	int	i;
	int	j;
	int	flag;
	
	i = -1;
	flag = FALSE;
	while (file[++i])
	{
		j = -1;
		while (file[i][++j])
		{
			if (file[i][j] == c)
			{
				if (ft_strncmp(file[i][j], to_find, ft_strlen(to_find)))
					return (get_texture(cube, file[i], j));
			}
		}
	}
	ft_printf_fd(2, "Error, Missing texture files\n");
	return (NULL);
}

int	init_texture(t_cube *cube, char **file)
{
	cube->NO_texture = check_texture(cube, file, "NO", 'N');
	if (!cube->NO_texture)
		return (FALSE);
	cube->SO_texture = check_texture(cube, file, "SO", 'S');
	if (!cube->SO_texture)
		return (FALSE);
	cube->WE_texture = check_texture(cube, file, "WE", 'W');
	if (!cube->WE_texture)
		return (FALSE);
	cube->EA_texture = check_texture(cube, file, "EA", 'E');
	if (!cube->EA_texture)
		return (FALSE);
	return (TRUE);
}
