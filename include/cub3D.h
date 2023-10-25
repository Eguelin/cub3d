/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/23 12:30:23 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "mylib.h"
# include "mlx.h"
# include "mlx_int.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define FOV 1.0472
# define HEIGHT 2058
# define LENGTH 3840

typedef enum e_error
{
	WRONG_FORMAT = 1,
	WRONG_FORMAT_BIS,
	WRONG_ARGUMENTS,
	OPEN_ERROR,
	MAP_ERROR,
	MALLOC_ERROR,
	ENV_ERROR,
	SORT_ERROR,
	COLORS_ERROR
}	t_error;

typedef enum e_view
{
	FLOOR,
	CEILING,
	NORTH,
	SOUTH,
	EAST,
	WEST,
}	t_view;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_player
{
	t_point	position;
	double	angle;
}	t_player;

typedef struct s_cub3d
{
	void		*mlx;
	void		*mlx_win;
	t_player	player;
	t_img		*windows;
	t_img		*minimap_img;
	t_img		*player_img;
	t_img		*texture[4];
	int			f_colors;
	int			c_colors;
	char		**map;
	double		angle[(LENGTH >> 1) + 1];
}	t_cub3d;

/////// [mlx-plug-in] ///////
void	ft_put_image_to_image(t_img *img_1, t_img *img_2, int x, int y);
void	ft_put_pixel_to_image(t_img *img, int x, int y, int color);

/////// [parsing] ///////
int		ft_check_map(t_cub3d *cub, char **start_map);
void	ft_get_map(t_cub3d *cub, char **file);
char	**ft_open_file(char const *file);
void	ft_parser(t_cub3d *cub, char **argv);
int		init_texture(t_cub3d *cub, char **file);
int		get_colors(t_cub3d *cub, char *str, int view);

/////// [ray-casting] ///////
void	ft_calculate_angle_array(t_cub3d *cub);

/////// [utils] ///////
void	ft_exit(t_cub3d *cub, char const *s, int exit);
int		ft_close_win(t_cub3d *cub);
void	ft_init_cub3d(t_cub3d	*cub);
int		ft_perror(char const *s, int error);
char	*ft_strndup(const char *s, int len);

#endif
