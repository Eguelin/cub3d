/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:10:33 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/13 02:16:16 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_close_window(void)
{
	exit(0);
}

int	ft_count_map_len(char **map)
{
	int	i;
	int	j;
	int	max;

	max = ft_strlen(map[0]);
	i = 0;
	while (map[i] && map[i][0] != '\0' && map[i + 1])
	{
		ft_printf_fd(2, "len === %s\n", map[i]);
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		if (max < j)
			max = j;
		i++;
	}
	return (max);
}

int	ft_count_map_line(char **map)
{
	int	i;

	i = 1;
	while (map[i])
		i++;
	return (i);
}

void	cube_manager(t_cube *cub)
{
	int		len;
	int		width;
	char *map[] = {"        1111111111111111111111111\n\0",
	    "        1000000000110000000000001\n\0",
	    "        1011000001110000000000001\n\0",
	    "        1001000000000000000000001\n\0",
	    "111111111011000001110000000000001\n\0",
	    "100000000011000001110111111111111\n\0",
	    "11110111111111011100000010001\n\0",
	    "11110111111111011101010010001\n\0",
	    "11000000110101011100000010001\n\0",
	    "10000000000000001100000010001\n\0",
	    "10000000000000001101010010001\n\0",
	    "11000001110101011111011110N0111\n\0",
	    "111101111110101101111010001\n\0",
	    "111111111111111111111111\0"
};

	len = 32;
	width = 32;
	cub->x = 0;
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, (len * 32), (width * 32), "Cub3d");
	ft_put_texture(cub, map);
	mlx_hook(cub->mlx_win, 17, 0, ft_close_window, &cub);
	mlx_loop(cub->mlx);
}
