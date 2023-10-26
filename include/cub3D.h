/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/26 20:49:50 by acarlott         ###   ########lyon.fr   */
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

# define FLOOR 0
# define CEILING 1
# define KEY_ESC 65307
# define KEY_F1 65470
# define KEY_F2 65471
# define KEY_F3 65472
# define KEY_F4 65473
# define KEY_F5 65474
# define KEY_F6 65475
# define KEY_F7 65476
# define KEY_F8 65477
# define KEY_F9 65478
# define KEY_F10 65479
# define KEY_F11 65480
# define KEY_F12 65481
# define KEY_GRAVE_ACCENT 96
# define KEY_1 49
# define KEY_2 50
# define KEY_3 51
# define KEY_4 52
# define KEY_5 53
# define KEY_6 54
# define KEY_7 55
# define KEY_8 56
# define KEY_9 57
# define KEY_0 48
# define KEY_DASH_UNDERSCORE 45
# define KEY_EQUALS_PLUS 61
# define KEY_BACKSPACE 65288
# define KEY_TAB 65289
# define KEY_Q 113
# define KEY_W 119
# define KEY_E 101
# define KEY_R 114
# define KEY_T 116
# define KEY_Y 121
# define KEY_U 117
# define KEY_I 105
# define KEY_O 111
# define KEY_P 112
# define KEY_OPEN_BRACKET 91
# define KEY_CLOSE_BRACKET 93
# define KEY_BACKSLASH 92
# define KEY_CAPS_LOCK 65509
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_F 102
# define KEY_G 103
# define KEY_H 104
# define KEY_J 106
# define KEY_K 107
# define KEY_L 108
# define KEY_SEMICOLON 59
# define KEY_SINGLE_QUOTE 39
# define KEY_ENTER 65293
# define KEY_LEFT_SHIFT 65505
# define KEY_Z 122
# define KEY_X 120
# define KEY_C 99
# define KEY_V 118
# define KEY_B 98
# define KEY_N 110
# define KEY_M 109
# define KEY_COMMA 44
# define KEY_PERIOD 46
# define KEY_SLASH 47
# define KEY_RIGHT_SHIFT 65506
# define KEY_LEFT_COMMAND 65507
# define KEY_LEFT_ALT 65513
# define KEY_SPACE 32
# define KEY_RIGHT_ALT 65514
# define KEY_MENU 65383
# define KEY_RIGHT_COMMAND 65508
# define KEY_UP_ARROW 65362
# define KEY_LEFT_ARROW 65361
# define KEY_DOWN_ARROW 65364
# define KEY_RIGHT_ARROW 65363

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
	t_img		*minimap[4];
	t_img		*texture[4];
	t_img		*windows;
	float		resize_len;
	int			f_colors;
	int			c_colors;
	char		**map;
}	t_cub3d;

/////// [parsing] ///////
void	ft_put_image_to_image(t_img *img_1, t_img *img_2, int x, int y);
void	ft_put_pixel_to_image(t_img *img, int x, int y, int color);

/////// [parsing] ///////
int		ft_check_map(t_cub3d *cub, char **start_map);
void	ft_get_map(t_cub3d *cub, char **file);
char	**ft_open_file(char const *file);
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
void	ft_resize_img(t_cub3d *cub, t_img **img, float len);
void	ft_clear_image(t_img *img);
// [PIXEL] //
void	ft_put_inset(t_cub3d *cub, float x, float y, int size);
void	ft_put_element(t_cub3d *cub, float x, float y, int size);
void	my_mlx_pixel_put(t_img *txr, int x, int y, int color);
// [MOVE] //
void	ft_move_north_south(t_cub3d *cub, int keycode);
void	ft_move_east_west(t_cub3d *cub, int keycode);
void	ft_angle_direction(t_cub3d *cub, int keycode);

/////// [utils] ///////
void	ft_exit(t_cub3d *cub, char const *s, int exit);
int		ft_close_win(t_cub3d *cub);
void	ft_init_cub3d(t_cub3d	*cub);
int		ft_perror(char const *s, int error);
char	*ft_strndup(const char *s, int len);

#endif
