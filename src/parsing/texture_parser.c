/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:39:02 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/11 00:40:40 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_colors_range(t_pars *pars, char *file, int start)
{
	char	*range;
	int		len;

	len = 0;
	while (file[start] && file[start++] != ',')
		len++;
	if (!file[start])
		return (FALSE);
	range = ft_strndup(&file[start], len);
	if (!range)
		ft_free_exit(pars, ERROR_MALLOC);
	len = ft_atoi(range);
	free(range);
	if (len >= 0 && len <= 255)
		return (FALSE);
	return (TRUE);
}

static char	*get_colors(t_pars *pars, char *str, int i)
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
			if (check_colors_range(pars, str, i) == FALSE)
				return (ft_printf_fd(2, "Error, wrong range colors\n"), NULL);
			value++;
		}
		i++;
	}
	if (value != 3)
		return (ft_printf_fd(2, "Error, wrong format colors\n"), NULL);
	colors = ft_strdup(&str[i]);
	if (!colors)
		ft_free_exit(pars, ERROR_MALLOC);
	return (colors);
}

static char	*get_texture(char *file, int start)
{
	int		fd;
	char	*texture_path;
	
	while (file[start] && file[start] != '.')
		start++;
	if (!file[start])
		return (NULL);
	texture_path = ft_strdup(&file[start]);
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
				if (ft_strlen(to_find) == 1)
					return (get_colors(pars, file[i], j));
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
	pars->F_colors = check_texture(pars, file, "F", 'F');
	if (!pars->F_colors)
		return (FALSE);
	pars->C_colors = check_texture(pars, file, "C", 'C');
	if (!pars->C_colors)
		return (FALSE);
	return (TRUE);
}
