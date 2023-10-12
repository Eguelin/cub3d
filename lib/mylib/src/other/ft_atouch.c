/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atouch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:40:55 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/12 12:36:35 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_atouch(const char *str)
{
	size_t			i;
	unsigned char	somme;

	i = 0;
	somme = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		return (-1);
	else if (str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		if (somme != (unsigned char)(somme * 10 + (str[i] - '0')) / 10)
			return (-1);
		somme = somme * 10 + (str[i] - '0');
		i++;
	}
	return (somme);
}
