/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:04:52 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/30 20:01:06 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_get_player(t_player *player, char **map, size_t i, int n_player);
static int	ft_check_line(char const *line);

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
	if (start_map[0][j] == '1')
		start_map[0][j] = '*';
	while (ft_diffusion(start_map))
		;
	while (cub->map[i])
	{
		n_player = ft_get_player(&cub->player, cub->map, i, n_player);
		if (n_player > 1)
			return (EXIT_FAILURE);
		if (!ft_check_line(start_map[i]))
			return (EXIT_FAILURE);
		i++;
	}
	if (!n_player)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
				player->angle = M_PI + M_PI_2;
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

static int	ft_check_line(char const *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '*')
			return (0);
		i++;
	}
	return (1);
}
