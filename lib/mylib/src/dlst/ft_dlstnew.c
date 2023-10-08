/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:49:23 by eguelin           #+#    #+#             */
/*   Updated: 2023/05/17 16:35:04 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*dlstnew;

	dlstnew = malloc(sizeof(t_dlist));
	if (!dlstnew)
		return (NULL);
	dlstnew->content = content;
	dlstnew->previous = NULL;
	dlstnew->next = NULL;
	return (dlstnew);
}
