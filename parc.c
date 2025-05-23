/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:45:31 by aradwan           #+#    #+#             */
/*   Updated: 2025/04/20 15:50:21 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	char_cheak(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E')
		return (1);
	else
		return (0);
}

int	count_lines(int fd, t_game *s)
{
	int		count;
	char	*line;
	int		first;
	int		i;

	i = 0;
	first = 1;
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (first)
		{
			while (line[i])
				i++;
			first = 0;
		}
		count++;
		free(line);
		line = get_next_line(fd);
	}
	s->x = i;
	s->y = count;
	return (count);
}

int	read_map(char **av, t_game *s)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "error\n", 7), 0);
	s->lines_num = count_lines(fd, s);
	close(fd);
	s->map = malloc(sizeof(char *) * (s->lines_num + 1));
	if (!s->map)
		return (write(2, "error\nallocation failed\n", 25), close(fd), 0);
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		s->map[i] = ft_strtrim(line, "\n");
		i++;
		free(line);
		line = get_next_line(fd);
	}
	s->map[i] = NULL;
	close(fd);
	return (1);
}

int	check(int ac, char **av, t_game *s)
{
	if (ac != 2)
		return (write(2, "error\nless than 2 ac", 21), 0);
	else if (!cheak_ber(av[1]))
		return (write(2, "error\nnot .ber file\n", 21), 0);
	if (!read_map(av, s))
		return (0);
	if (!*(s->map))
		return (free_map(s->map), 0);
	if (!same_rows(s))
	{
		free_map(s->map);
		return (write(2, "error\nnot reqtiangle or invalid char\n", 38), 0);
	}
	if (!cheak_paths(s))
		return (write(2, "error\ninvalid pahts\n", 20), 0);
	return (1);
}

int	is_wall_line(char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '1')
			return (0);
		i++;
	}
	return (1);
}
