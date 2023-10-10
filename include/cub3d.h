/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/10 17:43:06 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "mylib.h"
# include "mlx.h"
#include <fcntl.h>

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

typedef struct e_cube 
{
	char	*NO_texture;
	char	*SO_texture;
	char	*WE_texture;
	char	*EA_texture;
	char	*F_colors;
	char	*C_colors;
}	t_cube;

int	parsing(t_cube *cube, int argc, char **argv);
int	init_texture(t_cube *cube, char **file);

#endif
