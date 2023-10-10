/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:39:02 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/11 01:34:40 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_colors_range(t_pars *pars, char *str, int value, int view)
{
	char	*range;
	int		len;

	len = 0;
	while (str[len] && str[len++] != ',')
		len++;
	if (!str[len])
		return (FALSE);
	range = ft_strndup(str, len);
	if (!range)
		ft_free_exit(pars, ERROR_MALLOC);
	len = ft_atoi(range);
	free(range);
	if (len >= 0 && len <= 255)
		return (FALSE);
	if (view == FLOOR)
		pars->F_colors[value] = len;
	else
		pars->C_colors[value] = len;
	return (TRUE);
}

static int	*get_colors(t_pars *pars, char *str, int i, int view)
{
	int		value;
	char	*colors;
	
	value = 0;
	while (str[++i] && ft_isdigit(str[i]))
		if (ft_isalpha(str[i]))
			return (ft_printf_fd(2, "Error, wrong format colors\n"), ERR_COLOR);
	if (!str[i])
		return (NULL);
	while(str[i] && value != 3)
	{
		if (str[i] == ',' && str[i + 1] && ft_isdigit(str[i + 1]))
		{
			if (check_colors_range(pars, str, value, view) == FALSE)
				return (ft_printf_fd(2, "Error, wrong range colors\n"), ERR_COLOR);
			value++;
		}
		i++;
	}
	if (value != 3)
		return (ft_printf_fd(2, "Error, wrong format colors\n"), ERR_COLOR);
	return (colors);
}

static char	*get_texture(char *str, int start)
{
	int		fd;
	char	*texture_path;
	
	while (str[start] && str[start] != '.')
		start++;
	if (!str[start])
		return (NULL);
	texture_path = ft_strdup(&str[start]);
	if (!texture_path)
		return (ft_printf_fd(2, "Malloc error\n"), NULL);
	fd = open(texture_path, 0);
	if (fd == -1)
		return (ft_printf_fd(2, "Error, texture file can't be opened\n"), NULL);
	close(fd);
	return (texture_path);
}

static char *check_texture(t_pars *pars, char **file, char *to_find, char c)
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
					return (get_colors(pars, &file[i][j], j, FLOOR), "error");
				if (ft_strlen(to_find) == 1 && c == 'C')
					return (get_colors(pars, &file[i][j], j, CEILING), "error");
				if (ft_strncmp(&file[i][j], to_find, ft_strlen(to_find)))
					return (get_texture(file[i], j));
			}
		}
	}
	ft_printf_fd(2, "Error, Missing texture files\n");
	return (NULL);
} 

int	init_texture(t_pars *pars, char **file)
{
	int	i;

	i = 0;
	while(i < 3)
	{
		pars->F_colors[i] = -1;
		pars->C_colors[i++] = -1;
	}
	pars->NO_texture = check_texture(pars, file, "NO", 'N');
	if (!pars->NO_texture)
		return (FALSE);
	pars->SO_texture = check_texture(pars, file, "SO", 'S');
	if (!pars->SO_texture)
		return (FALSE);
	pars->WE_texture = check_texture(pars, file, "WE", 'W');
	if (!pars->WE_texture)
		return (FALSE);
	pars->EA_texture = check_texture(pars, file, "EA", 'E');
	if (!pars->EA_texture)
		return (FALSE);
	if (ft_strcmp(check_texture(pars, file, "F", 'F'), "error"));
		return (FALSE);
	if (ft_strcmp(check_texture(pars, file, "C", 'C'), "error"));
		return (FALSE);
	return (TRUE);
}
