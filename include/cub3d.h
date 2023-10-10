/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/10 18:58:46 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H
# include "mylib.h"
# include "mlx.h"

typedef enum e_error
{
	WRONG_FORMAT,
	WRONG_FORMAT_BIS,
	WRONG_ARGUMENTS,
	OPEN_ERROR,
	MALLOC_ERROR
	ENV_ERROR
}	t_error;

#endif
