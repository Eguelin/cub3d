/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:19:26 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/17 16:39:20 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

t_dlist	*ft_dlstfirst(t_dlist *dlst)
{
	if (!dlst)
		return (NULL);
	while (dlst->previous)
		dlst = dlst->previous;
	return (dlst);
}
