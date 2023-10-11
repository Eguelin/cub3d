/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:05:11 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/11 17:15:27 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	ft_count_line(char const *file);
static int		ft_open(char const *file, int flag);
static size_t	ft_char_occurrences(char const c, char const *str);

char	**ft_open_file(char const *file)
{
	int		fd;
	char	**line;
	size_t	i;
	size_t	n_line;

	i = 0;
	fd = ft_open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	n_line = ft_count_line(file) + 1;
	line = ft_calloc(sizeof(char *), n_line);
	if (!line)
		return (ft_perror(NULL, MALLOC_ERROR), NULL);
	line[i] = get_next_line(fd);
	while (line[i])
		line[++i] = get_next_line(fd);
	close(fd);
	// if (i != n_line - 1)
	// {
	// 	ft_free_bat((void **)line, n_line);
	// 	return (ft_perror(NULL, MALLOC_ERROR), NULL);
	// }
	return (line);
}

static size_t	ft_count_line(char const *file)
{
	char	buf[65];
	int		fd;
	size_t	count;
	size_t	n_char;

	count = 0;
	n_char = 1;
	fd = ft_open(file, O_RDONLY);
	if (fd == -1)
		return (count);
	ft_memset(buf, 0, 65);
	while (n_char)
	{
		n_char = read(fd, buf, 64);
		if (!(n_char + 1))
			return (close(fd), 0);
		count += ft_char_occurrences('\n', buf);
		if (n_char != 64 && buf[n_char - 1] != '\n')
			count++;
		ft_memset(buf, 0, 65);
	}
	close(fd);
	return (count);
}

static int	ft_open(char const *file, int flag)
{
	int		fd;

	fd = open(file, flag);
	if (fd == -1)
	{
		ft_perror(NULL, OPEN_ERROR);
		return (-1);
	}
	return (fd);
}

static size_t	ft_char_occurrences(char const c, char const *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
