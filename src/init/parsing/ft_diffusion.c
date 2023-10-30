/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diffusion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:28:55 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/30 19:43:10 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_is_fillable(char **map, size_t i, size_t j, int *n);
static int	ft_fill(char **map, size_t i, size_t j);

int	ft_diffusion(char **map)
{
	size_t	i;
	size_t	j;
	int		n;

	i = 0;
	n = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			ft_is_fillable(map, i, j++, &n);
		i++;
	}
	while (i)
	{
		j = ft_strlen(map[--i]);
		while (j)
			ft_is_fillable(map, i, --j, &n);
	}
	return (n);
}

static void	ft_is_fillable(char **map, size_t i, size_t j, int *n)
{
	if (map[i][j] == '*')
	{
		if (map[i][j + 1] && ft_fill(map, i, j + 1))
			*n = 1;
		if (j != 0 && ft_fill(map, i, j - 1))
			*n = 1;
		if (map[i + 1] && j < ft_strlen(map[i + 1]) && ft_fill(map, i + 1, j))
			*n = 1;
		if (i != 0 && j < ft_strlen(map[i - 1]) && ft_fill(map, i - 1, j))
			*n = 1;
	}
}

static int	ft_fill(char **map, size_t i, size_t j)
{
	if (!map[i][j] || map[i][j] == ' ' || map[i][j] == '*')
		return (0);
	else if (map[i][j] == '1')
		map[i][j] = '*';
	else if (!map[i][j + 1] || map[i][j + 1] == ' ' \
	|| !j || map[i][j - 1] == ' ' \
	|| j > ft_strlen(map[i + 1]) || map[i + 1][j] == ' ' \
	|| !i || j > ft_strlen(map[i - 1]) || map[i - 1][j] == ' ')
		return (0);
	else
		map[i][j] = '*';
	return (1);
}
