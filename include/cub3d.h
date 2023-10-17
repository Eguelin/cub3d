/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/17 17:42:52 by acarlott         ###   ########lyon.fr   */
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
	WRONG_FORMAT,
	WRONG_FORMAT_BIS,
	WRONG_ARGUMENTS,
	OPEN_ERROR,
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


typedef struct s_player
{
	float	angle;
	float	x_start;
	float	y_start;
	float	x_end;
	float	y_end;
}	t_player;

typedef struct s_texture
{
	char	*addr;
	void	*img;
	int		w;
	int		h;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_cube
{
	t_texture	texture[4];
	t_texture	minimap_img;
	t_texture	player_img;
	t_texture	windows;
	t_player	player;
	char		**map;
	int			f_colors;
	int			c_colors;
	void		*mlx_win;
	void		*mlx;
}	t_cube;

/////// [parsing] ///////
int		parsing(t_cube *cub, char **argv);
int		init_texture(t_cube *cub, char **file);
int		get_colors(t_cube *cub, char *str, int view);
char	**ft_open_file(char const *file);
/////// [MAPPING] ///////
void	cube_manager(t_cube *cub);
int		ft_count_map_len(char **map);
int		ft_count_map_line(char **map);
void	ft_minimap(t_cube *cub, char **map);
void	ft_move_direction(t_cube *cub, int keycode);
void	ft_angle_direction(t_cube *cub, int keycode);
void	ft_put_img_to_img(t_cube *cub);
void	my_mlx_pixel_put(t_texture *txr, int x, int y, int color);
/////// [utils] ///////
int		ft_perror(const char *s, int error);
char	*ft_strndup(const char *s, int len);
void	ft_destroy_texture(t_cube *cub);
void	ft_free_bat(void **tab, size_t size);

#endif
