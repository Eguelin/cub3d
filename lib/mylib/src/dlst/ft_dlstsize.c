/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:27:39 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/17 18:36:54 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_dlstsize(t_dlist *dlst)
{
	int	n;

	n = 0;
	dlst = ft_dlstfirst(dlst);
	while (dlst)
	{
		dlst = dlst->next;
		n++;
	}
	return (n);
}
