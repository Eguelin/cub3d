/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:04:52 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/14 18:36:25 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_line(char *line, char *next);

int	ft_check_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (ft_check_line(map[i], map[i + 1]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	ft_check_line(char *line, char *next)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == ' ' && \
		(line[i + 1] == '0' || (next && next[i] == '0'))) || (line[i] == '0' \
		&& (!i || !line[i + 1] || !next || !next[i] || next[i] == ' ')))
		{
			ft_perror(NULL, MAP_ERROR);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
