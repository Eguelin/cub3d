/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/16 21:50:40 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "mylib.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define FALSE 0 
# define TRUE 1

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
void	set_view_minimap(t_cube *cub, char **map);
void	my_mlx_pixel_put(t_texture *txr, int x, int y, int color);
/////// [utils] ///////
int		ft_perror(const char *s, int error);
char	*ft_strndup(const char *s, int len);
void	ft_destroy_texture(t_cube *cub);
void	ft_free_bat(void **tab, size_t size);

#endif
