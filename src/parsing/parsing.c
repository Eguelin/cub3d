/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:46:19 by acarlott          #+#    #+#             */
/*   Updated: 2023/10/12 21:21:25 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	content_condition(char *file, int *tab)
{
	if (!ft_strncmp(file, "NO", 2) && tab[0] != 1)
		return (tab[0] = 1, EXIT_SUCCESS);
	if (!ft_strncmp(file, "SO", 2) && tab[1] != 1)
		return (tab[1] = 1, EXIT_SUCCESS);
	if (!ft_strncmp(file, "WE", 2) && tab[2] != 1)
		return (tab[2] = 1, EXIT_SUCCESS);
	if (!ft_strncmp(file, "EA", 2) && tab[3] != 1)
		return (tab[3] = 1, EXIT_SUCCESS);
	if (!ft_strncmp(file, "F", 1) && tab[4] != 1)
		return (tab[4] = 1, EXIT_SUCCESS);
	if (!ft_strncmp(file, "C", 1) && tab[5] != 1)
		return (tab[5] = 1, EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static int	check_content(char **file)
{
	int	value;
	int	i;
	int	tab[6];

	value = 0;
	i = - 1;
	while (tab[++i])
		tab[i] = 0;
	i = -1;
	while (file[++i] && value != 6)
	{
		while (file[i][0] == '\n')
			i++;
		if (!file[i])
			break ;
		if (content_condition(file[i], tab) == EXIT_SUCCESS)
			value++;
		else
			break ;
	}
	if (value != 6)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parsing(t_cube *cub, char **argv)
{
	char	**file;

	file = ft_open_file(argv[1]);
	if (!file)
		return (EXIT_FAILURE);
	if (check_content(file) == EXIT_FAILURE)
		return (ft_free_split(file),  \
		ft_perror("Duplicate or wrong input path", SORT_ERROR));
	if (init_texture(cub, file) == EXIT_FAILURE)
		return (ft_free_split(file), EXIT_FAILURE);
	ft_free_split(file);
	return (EXIT_SUCCESS);
}
