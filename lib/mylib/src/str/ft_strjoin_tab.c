/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:43:08 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/16 08:49:23 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

char	*ft_strjoin_tab(char **tab)
{
	size_t	size;
	int		i;
	char	*str;

	size = 0;
	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
		size += ft_strlen(tab[i++]);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	ft_strlcpy(str, tab[i++], size + 1);
	while (tab[i])
		ft_strlcat(str, tab[i++], size + 1);
	return (str);
}
