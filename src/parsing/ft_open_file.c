/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:05:11 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/20 17:25:58 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char		*ft_fill_file(int fd);
static size_t	ft_count_line(char const *file);
static size_t	ft_char_occurrences(char const c, char const *str, size_t size);

char	**ft_open_file(char const *name)
{
	int		fd;
	char	**file;
	size_t	n_line;
	size_t	i;

	if (ft_strncmp(name + ft_strlen(name) - 4, ".cub", 5))
		ft_exit(NULL, name, WRONG_ARGUMENTS);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		ft_exit(NULL, name, OPEN_ERROR);
	n_line = ft_count_line(name);
	file = ft_calloc(sizeof(char *), n_line + 1);
	if (!file)
		ft_exit(NULL, NULL, MALLOC_ERROR);
	i = 0;
	file[i] = ft_fill_file(fd);
	while (file[i])
		file[++i] = ft_fill_file(fd);
	close(fd);
	if (i != n_line)
	{
		ft_free_tab(file);
		ft_exit(NULL, NULL, MALLOC_ERROR);
	}
	return (file);
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
