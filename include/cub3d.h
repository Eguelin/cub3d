/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/11 16:09:23 by eguelin          ###   ########lyon.fr   */
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
	WRONG_FORMAT,
	WRONG_FORMAT_BIS,
	WRONG_ARGUMENTS,
	OPEN_ERROR,
	MALLOC_ERROR,
	ENV_ERROR
}	t_error;

/////// [parsing] ///////
int		ft_check_file_name(char *name);
char	**ft_open_file(char const *file);

/////// [utils] ///////
int		ft_perror(const char *s, int error);

#endif
