/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:39:14 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/18 11:16:29 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	content_condition(char *file, int *tab);
static int	check_content(char **file);

void	ft_parser(t_cub3d *cub, char **argv)
{
	char	**file;

	file = ft_open_file(argv[1]);
	if (check_content(file))
	{
		ft_free_tab(file);
		ft_exit(cub, "Duplicate or wrong input path", SORT_ERROR);
	}
	if (init_texture(cub, file))
	{
		ft_free_tab(file);
		ft_exit(cub, NULL, MALLOC_ERROR);
	}
	ft_get_map(cub, file);
	ft_free_tab(file);
}

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
	int tab[6];

	value = 0;
	i = 0;
	ft_memset(tab, 0, sizeof(tab));
	while (file[i] && value != 6)
	{
		while (file[i][0] == '\0')
			i++;
		if (!file[i])
			break ;
		if (content_condition(file[i], tab) == EXIT_SUCCESS)
			value++;
		else
			break ;
		i++;
	}
	if (value != 6)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
