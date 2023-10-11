/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:00:45 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/11 16:51:32 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void	ft_free_bat(void **tab, size_t size)
{
	size_t	i;

	i = 0;
	if (!tab)
		return ;
	while (i < size)
		free(tab[i++]);
	free(tab);
}
