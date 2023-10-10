/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:39:02 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/10 23:49:29 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_colors_range(t_cube *cube, char *file, int start)
{
	char	*range;
	int		len;

	len = 0;
	while (file[start] && file[start++] != ',')
		len++;
	if (!file[start])
		return (NULL);
	range = ft_strndup(&file[start], len);
	if (!range)
		ft_free_exit(cube, ERROR_MALLOC);
	len = ft_atoi(range);
	free(range);
	if (len < 0 && len > 255)
		return (FALSE);
	return (TRUE);
}

static char	*get_colors(t_cube *cube, char *str, int i)
{
	int		value;
	char	*colors;
	
	while (str[++i] && ft_isdigit(str[i]))
		if (ft_isalpha(str[i]))
			return (ft_printf_fd(2, "Error, wrong format colors\n"), NULL);
	if (!str[i])
		return (NULL);
	while(str[i] && value != 3)
	{
		if (str[i] == ',' && str[i + 1] && ft_isdigit(str[i + 1]))
		{
			if (check_colors_range(cube, str, i) == FALSE)
				return (ft_printf_fd(2, "Error, wrong range colors\n"), NULL);
			value++;
		}
		i++;
	}
	if (value != 3)
		return (ft_printf_fd(2, "Error, wrong format colors\n"), NULL);
	colors = ft_strdup(str[i]);
	if (!colors)
		ft_free_exit(cube, ERROR_MALLOC);
	return (colors);
}

static char	*get_texture(t_cube *cube, char *file, int start)
{
	int		fd;
	char	*texture_path;
	
	while (file[start] && file[start] != '.')
		start++;
	if (!file[start])
		return (NULL);
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
				if (ft_strlen(to_find) == 1)
					return (get_colors(cube, file[i], j));
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
	cube->F_colors = check_texture(cube, file, "F", 'F');
	if (!cube->F_colors)
		return (FALSE);
	cube->C_colors = check_texture(cube, file, "C", 'C');
	if (!cube->C_colors)
		return (FALSE);
	return (TRUE);
}
