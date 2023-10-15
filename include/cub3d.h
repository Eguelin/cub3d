/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/15 14:05:59 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "mylib.h"
# include "mlx.h"
# include <sys/stat.h>
# include <fcntl.h>

typedef enum e_error
{
	WRONG_FORMAT = 1,
	WRONG_FORMAT_BIS,
	WRONG_ARGUMENTS,
	OPEN_ERROR,
	MAP_ERROR,
	MALLOC_ERROR,
	ENV_ERROR
}	t_error;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_cub3d
{
	char	**map;
	t_point	player;
}	t_cub3d;

/////// [parsing] ///////
void	ft_check_map(t_cub3d *cub);
void	ft_get_map(t_cub3d *cub, char **file);
char	**ft_open_file(char const *file);
void	ft_parser(t_cub3d *cub, char **argv);

/////// [utils] ///////
void	ft_exit(t_cub3d *cub, char const *s, int exit);
int		ft_perror(char const *s, int error);

#endif
