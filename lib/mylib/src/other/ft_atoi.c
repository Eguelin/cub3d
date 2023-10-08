/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:40:55 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/18 18:13:54 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

static int	check_neg(int neg)
{
	if (neg == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	long	somme;
	int		neg;

	i = 0;
	neg = 1;
	somme = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= 48 && str[i] <= 57))
	{
		if (somme != (somme * 10 + (str[i] - '0')) / 10)
			return (check_neg(neg));
		somme = somme * 10 + (str[i] - '0');
		i++;
	}
	return (somme * neg);
}
