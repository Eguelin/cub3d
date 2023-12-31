/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:05:11 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/31 13:47:42 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char		*ft_fill_file(int fd);
static size_t	ft_count_line(char const *file);
static size_t	ft_char_occurrences(char const c, char const *str, size_t size);

void	ft_open_file(t_cub3d *cub, char const *name)
{
	int		fd;
	size_t	n_line;
	size_t	i;

	if (ft_strncmp(name + ft_strlen(name) - 4, ".cub", 5))
		ft_exit(cub, name, WRONG_ARGUMENTS);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		ft_exit(cub, name, OPEN_ERROR);
	n_line = ft_count_line(name);
	cub->infile = ft_calloc(sizeof(char *), n_line + 1);
	if (!cub->infile)
		ft_exit(cub, NULL, MALLOC_ERROR);
	i = 0;
	cub->infile[i] = ft_fill_file(fd);
	while (cub->infile[i])
		cub->infile[++i] = ft_fill_file(fd);
	close(fd);
	if (i != n_line)
		ft_exit(cub, NULL, MALLOC_ERROR);
}

static char	*ft_fill_file(int fd)
{
	char	*line;
	size_t	size;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	size = ft_strlen(line);
	if (!size)
		return (line);
	size--;
	while (size && line[size] == ' ')
		size--;
	if (line[size] == ' ')
		line[size] = 0;
	else
		line[size + 1] = 0;
	return (line);
}

static size_t	ft_count_line(char const *file)
{
	char	buf[64];
	int		fd;
	size_t	count;
	size_t	n_char;

	count = 0;
	n_char = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_exit(NULL, file, OPEN_ERROR);
	n_char = read(fd, buf, 64);
	while (n_char)
	{
		count += ft_char_occurrences('\n', buf, n_char);
		if (n_char && n_char != 64 && buf[n_char - 1] != '\n')
			count++;
		n_char = read(fd, buf, 64);
	}
	close(fd);
	return (count);
}

static size_t	ft_char_occurrences(char const c, char const *str, size_t size)
{
	size_t	count;

	count = 0;
	size--;
	while (str && size + 1)
	{
		if (str[size] == c)
			count++;
		size--;
	}
	return (count);
}
