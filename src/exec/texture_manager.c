/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:42:35 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/13 02:17:22 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_texture(t_cube *cub, char **map)
{
	int	len;
	int	line;
	int	x;
	int	y;

	x = 0;
	line = ft_count_map_line(map);
	len = ft_strlen(map[0]);
	ft_printf(" len = %d\n", line);
	ft_printf(" len = %d\n", len);
	while (map[x] && x < line - 3)
	{
		ft_printf("%s\n", map[x]);
		y = 0;
		while (map[x][y] && map[x][y] != '\n'  && y < len - 3)
		{
			if (map[x][y] == '1')
					mlx_put_image_to_window(cub->mlx, cub->mlx_win, \
					cub->texture[0].img, (x * 16) , (y * 16));
			y++;
		}
		x++;
	}
}
