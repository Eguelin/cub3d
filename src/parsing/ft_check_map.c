/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:04:52 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/17 19:05:46 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_diffusion(char **map, size_t x, size_t y);
static int	ft_get_player(t_player *player, char **map, size_t i, int n_player);
static int	ft_is_solely_of(char const *str, int c);
static int	ft_is_closs(char const *line, char const *next);

int	ft_check_map(t_cub3d *cub, char **start_map)
{
	size_t	i;
	size_t	j;
	int		n_player;

	i = 0;
	j = 0;
	n_player = 0;
	while (start_map[1][j] == ' ')
		j++;
	ft_diffusion(start_map, j, i);
	while (cub->map[i])
	{
		n_player = ft_get_player(&cub->player, cub->map, i, n_player);
		if (n_player > 1)
			return (EXIT_FAILURE);
		if (!ft_is_solely_of(start_map[i], ' '))
			return (EXIT_FAILURE);
		if (!ft_is_closs(cub->map[i], cub->map[i + 1]))
			return (EXIT_FAILURE);
		i++;
	}
	if (!n_player)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	ft_diffusion(char **map, size_t x, size_t y)
{
	if (y < 0 || !map[y] || x < 0 || x >= ft_strlen(map[y]))
		return ;
	if (map[y][x] != ' ')
		map[y][x] = ' ';
	else
		return ;
	ft_diffusion(map, x + 1, y);
	ft_diffusion(map, x, y + 1);
	ft_diffusion(map, x - 1, y);
	ft_diffusion(map, x, y - 1);
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

static int	ft_is_solely_of(char const *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_closs(char const *line, char const *next)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == ' ' && \
		(line[i + 1] == '0' || (next && next[i] == '0'))) || (line[i] == '0' \
		&& (!i || !line[i + 1] || !next || !next[i] || next[i] == ' ')))
			return (0);
		i++;
	}
	return (1);
}
