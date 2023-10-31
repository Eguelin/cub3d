/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/31 16:03:27 by eguelin          ###   ########lyon.fr   */
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

# define FOV_2 0.5235987756
# define HEIGHT 2058
# define LENGTH 3840
# define LENGTH_2 1920
# define WALL_SIZE 3325
# define X 0
# define Y 1
# define FLOOR 0
# define CEILING 1

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
	COLORS_ERROR,
	IMG_ERROR
}	t_error;

typedef enum e_minimap
{
	MINIMAP,
	WALL,
	PLAYER,
	BORDER
}	t_minimap;

typedef enum e_view
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_view;

typedef enum e_hitbox
{
	TOP_L,
	TOP_R,
	BOTTOM_L,
	BOTTOM_R
}	t_hitbox;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_player
{
	t_point	position;
	t_point	hitbox[4];
	double	angle;
}	t_player;

typedef struct s_display
{
	t_img	*texture;
	t_point	impact;
	double	distance;
	int		wall_size;
	double	ratio_x;
	double	ratio_y;
}	t_display;

typedef struct s_cub3d
{
	void		*mlx;
	void		*mlx_win;
	t_player	player;
	t_img		*minimap[4];
	t_img		*texture[4];
	t_img		*windows;
	float		resize_len;
	int			f_colors;
	int			c_colors;
	char		**map;
	char		**infile;
	size_t		map_width;
	size_t		map_height;
	double		angle[LENGTH_2 + 1];
}	t_cub3d;

/////// [display] ///////
void	ft_visual_field(t_cub3d *cub);

/////// [mlx-plug-in] ///////
void	ft_put_image_to_image(t_img *img_1, t_img *img_2, int x, int y);
void	ft_put_pixel_to_image(t_img *img, int x, int y, int color);
void	ft_resize_img(t_cub3d *cub, t_img **img, float len);
void	ft_clear_image(t_img *img);

/////// [ray-casting] ///////
void	ft_ray_casting(t_cub3d *cub, double angle, t_display *display);

/////// [exit] ///////
int		ft_close_win(t_cub3d *cub);
void	ft_exit(t_cub3d *cub, char const *s, int exit);

/////// [init] ///////
void	ft_init(t_cub3d	*cub, char **argv);

/////// [parsing] ///////
int		ft_diffusion(char **map);
int		ft_check_map(t_cub3d *cub, char **start_map);
void	ft_get_map(t_cub3d *cub, char **file);
void	ft_open_file(t_cub3d *cub, char const *name);
void	ft_parser(t_cub3d *cub, char **argv);
int		init_texture(t_cub3d *cub, char **file);
int		get_colors(t_cub3d *cub, char *str, int view);

/////// [MAPPING] ///////
void	cub3d_manager(t_cub3d *cub);
// [IMG] //
void	set_player_img(t_cub3d *cub, int size);
void	set_minimap_img(t_cub3d *cub, char **map);
void	set_window_img(t_cub3d *cub, int width, int height);
void	set_miniborder_img(t_cub3d *cub, int height, int width);
void	ft_put_image_to_image(t_img *img_1, t_img *img_2, int x, int y);
// [PIXEL] //
void	ft_put_inset(t_cub3d *cub, float x, float y, int size);
void	ft_put_element(t_cub3d *cub, float x, float y, int size);
void	my_mlx_pixel_put(t_img *txr, int x, int y, int color);
// [MOVE] //
void	init_hitbox_player(t_cub3d *cub);
int		ft_hitbox(t_cub3d *cub, int keycode, int point);
void	ft_move_north_south(t_cub3d *cub, int keycode);
void	ft_move_east_west(t_cub3d *cub, int keycode);
void	ft_angle_direction(t_cub3d *cub, int keycode);

/////// [utils] ///////
int		ft_perror(char const *s, int error);
char	*ft_strndup(const char *s, int len);

#endif
