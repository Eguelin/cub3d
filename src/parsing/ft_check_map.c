/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:04:52 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/21 16:28:54 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_diffusion(char **map);
static int	ft_get_player(t_player *player, char **map, size_t i, int n_player);
static int	ft_check_line(char const *dif_line, \
char const *map_line, char const *map_next);
static void	ft_replace(char **map, size_t i, size_t j, int *n);

int	ft_check_map(t_cub3d *cub, char **start_map)
{
	size_t	i;
	size_t	j;
	int		n_player;

	i = 0;
	j = 0;
	n_player = 0;
	while (start_map[0][j] == ' ')
		j++;
	start_map[0][j] = '*';
	while (ft_diffusion(start_map))
		;
	while (cub->map[i])
	{
		n_player = ft_get_player(&cub->player, cub->map, i, n_player);
		if (n_player > 1)
			return (EXIT_FAILURE);
		if (!ft_check_line(start_map[i], cub->map[i], cub->map[i + 1]))
			return (EXIT_FAILURE);
		i++;
	}
	if (!n_player)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_diffusion(char **map)
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
			ft_replace(map, i, j++, &n);
		i++;
	}
	while (i)
	{
		j = ft_strlen(map[--i]);
		while (j)
			ft_replace(map, i, --j, &n);
	}
	return (n);
}

static void	ft_replace(char **map, size_t i, size_t j, int *n)
{
	if (map[i][j] == '*')
	{
		if (map[i][j + 1] && map[i][j + 1] != '*' && map[i][j + 1] != ' ')
		{
			map[i][j + 1] = '*';
			*n = 1;
		}
		if (j != 0 && map[i][j - 1] != '*' && map[i][j - 1] != ' ')
		{
			map[i][j - 1] = '*';
			*n = 1;
		}
		if (map[i + 1] && j < ft_strlen(map[i + 1]) && map[i + 1][j] != ' ' \
		&& map[i + 1][j] != '*')
		{
			map[i + 1][j] = '*';
			*n = 1;
		}
		if (i != 0 && j < ft_strlen(map[i - 1]) && map[i - 1][j] != ' ' \
		&& map[i - 1][j] != '*')
		{
			map[i - 1][j] = '*';
			*n = 1;
		}
	}
}

static int	ft_get_player(t_player *player, char **map, size_t i, int n_player)
{
	size_t		j;

	j = 0;
	while (map[i][j])
	{
		if (ft_strchr("NSWE", map[i][j]))
		{
			player->position.x = j + 0.5;
			player->position.y = i + 0.5;
			if (map[i][j] == 'N')
				player->angle = -M_PI_2;
			else if (map[i][j] == 'S')
				player->angle = M_PI_2;
			else if (map[i][j] == 'W')
				player->angle = M_PI;
			else
				player->angle = 0;
			map[i][j] = '0';
			n_player++;
		}
		if (n_player > 1)
			return (n_player);
		j++;
	}
	return (n_player);
}

static int	ft_check_line(char const *dif_line, \
char const *map_line, char const *map_next)
{
	size_t	i;

	i = 0;
	while (map_line[i])
	{
		if ((map_line[i] == ' ' && \
		(map_line[i + 1] == '0' || (map_next && map_next[i] == '0'))) \
		|| (map_line[i] == '0' && (!i || !map_line[i + 1] || !map_next || \
		!map_next[i] || map_next[i] == ' ')))
			return (0);
		i++;
	}
	i = 0;
	while (dif_line[i])
	{
		if (dif_line[i] != ' ' && dif_line[i] != '*')
			return (0);
		i++;
	}
	return (1);
}
