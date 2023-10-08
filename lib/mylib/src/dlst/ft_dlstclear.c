/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:32:26 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/17 20:07:40 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void	ft_dlstclear(t_dlist **dlst, void (*del)(void*))
{
	t_dlist	*tmp;

	if (!dlst || !del)
		return ;
	*dlst = ft_dlstfirst(*dlst);
	while (*dlst)
	{
		tmp = (*dlst)->next;
		ft_dlstdelone(*dlst, del);
		*dlst = tmp;
	}
}
