/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:04:52 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/15 14:53:54 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_get_player(t_cub3d *cub, size_t index, size_t *buf_player);
static int	ft_check_line(char const *line, char const *next);

void	ft_check_map(t_cub3d *cub)
{
	size_t	i;
	size_t	buf_player;

	i = 0;
	buf_player = 0;
	while (cub->map[i])
	{
		ft_get_player(cub, i, &buf_player);
		if (buf_player > 1)
			ft_exit(cub, NULL, MAP_ERROR);
		if (ft_check_line(cub->map[i], cub->map[i + 1]))
			ft_exit(cub, NULL, MAP_ERROR);
		i++;
	}
	if (!buf_player)
		ft_exit(cub, NULL, MAP_ERROR);
}

static void	ft_get_player(t_cub3d *cub, size_t index, size_t *buf_player)
{
	char const	*set = "NSEW";
	char		set_map[256];
	size_t		i;

	ft_memset(set_map, 0, 256);
	while (*set)
	{
		set_map[(unsigned char)(*set)] = 1;
		set++;
	}
	i = 0;
	while (cub->map[index][i])
	{
		if (set_map[(unsigned char)(cub->map[index][i])])
		{
			cub->map[index][i] = '0';
			cub->player.x = i + 0.5;
			cub->player.y = index + 0.5;
			(*buf_player)++;
		}
		i++;
	}
}

static int	ft_check_line(char const *line, char const *next)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == ' ' && \
		(line[i + 1] == '0' || (next && next[i] == '0'))) || (line[i] == '0' \
		&& (!i || !line[i + 1] || !next || !next[i] || next[i] == ' ')))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
