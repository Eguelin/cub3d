/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/12 19:44:15 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "mylib.h"
# include "mlx.h"
# include <fcntl.h>

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

typedef struct s_texture
{
	void	*img;
	int		w;
	int		h;
}	t_texture;

typedef struct s_cube
{
	t_texture	texture[4];
	int			f_colors;
	int			c_colors;
	void		*mlx_win;
	void		*mlx;
	int			x;
	int			y;
}	t_cube;

/////// [parsing] ///////
int		parsing(t_cube *cub, char **argv);
int		init_texture(t_cube *cub, char **file);
int		get_colors(t_cube *cub, char *str, int i, int view);
char	**ft_open_file(char const *file);
/////// [utils] ///////
int		ft_perror(const char *s, int error);
char	*ft_strndup(const char *s, int len);
// void	ft_free_exit(t_cube *cub, int error);
// void	ft_free_mlx(t_cube *cub);
void	ft_free_bat(void **tab, size_t size);
void	cube_manager(t_cube *cub);

#endif
