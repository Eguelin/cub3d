/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/18 15:21:31 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "mylib.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

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

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_player
{
	t_point	position;
	double	angle;
}	t_player;

typedef struct s_cub3d
{
	t_image		texture[4];
	t_image		minimap_img;
	t_image		player_img;
	t_image		windows;
	t_player	player;
	char		**map;
	int			f_colors;
	int			c_colors;
	void		*mlx_win;
	void		*mlx;
}	t_cub3d;

/////// [parsing] ///////
int		ft_check_map(t_cub3d *cub, char **start_map);
void	ft_get_map(t_cub3d *cub, char **file);
char	**ft_open_file(char const *file);
/////// [MAPPING] ///////
void	cub3d_manager(t_cub3d *cub);
int		ft_count_map_len(char **map);
int		ft_count_map_line(char **map);
void	ft_minimap(t_cub3d *cub, char **map);
void	ft_move_direction(t_cub3d *cub, int keycode);
void	ft_angle_direction(t_cub3d *cub, int keycode);
void	ft_put_img_to_img(t_cub3d *cub);
void	my_mlx_pixel_put(t_image *txr, int x, int y, int color);
void	ft_parser(t_cub3d *cub, char **argv);
int		init_texture(t_cub3d *cub, char **file);
int		get_colors(t_cub3d *cub, char *str, int view);

/////// [utils] ///////
void	ft_exit(t_cub3d *cub, char const *s, int exit);
int		ft_close_win(t_cub3d *cub);
void	ft_init_cub3d(t_cub3d	*cub);
int		ft_perror(char const *s, int error);
char	*ft_strndup(const char *s, int len);
void	ft_destroy_texture(t_cub3d *cub);
void	ft_free_bat(void **tab, size_t size);

#endif
