/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/11 00:44:25 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../lib/mylib/include/mylib.h"
# include "mlx.h"
# include <fcntl.h>

# define FALSE 0 
# define TRUE 1

typedef enum e_error
{
	SUCCESS,
	EMPTY_ENV,
	ERROR_PARAM,
	ERROR_SORT,
	ERROR_TEXTURE,
	ERROR_MALLOC,
}	t_error;

typedef struct s_pars
{
	char	*NO_texture;
	char	*SO_texture;
	char	*WE_texture;
	char	*EA_texture;
	char	*F_colors;
	char	*C_colors;
}	t_pars;

typedef struct s_cube
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	t_pars	*pars;
}	t_cube;

int		parsing(t_pars *pars, char **argv);
int		init_texture(t_pars *pars, char **file);
char	*ft_strndup(const char *s, int len);
void	ft_free_exit(t_pars *pars, int error);
void	cube_manager(t_pars *pars);

#endif
