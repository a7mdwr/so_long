/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:45:31 by aradwan           #+#    #+#             */
/*   Updated: 2025/04/17 16:25:24 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_2d(char **str)
{
 	int	i;
 
 	i = 0;
     while (str[i])
 	    free(str[i++]);
 	free(str);
}

int count_lines(int fd, t_game *s)
 {
     int count;
     char *line;
     int first;
     int i;

    i = 0;
    first = 1;
    count = 0;
    line = get_next_line(fd);
    while(line)
    {
        if(first)
        {
            while(line[i])
                i++;
            first = 0;
        }
         count++;
         free(line);
         line = get_next_line(fd);
    }
    s->x = i;
    s->y = count;
    return count;
 }

int read_map(char **av ,t_game *s)
{
    int lines_num;
    int i;
    int fd;
    char *line;

    lines_num = 0;
    i = 0;
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
         return (write(2, "Error\n", 7), 0);
    lines_num = count_lines(fd, s);
    close(fd);
    s->map = malloc(sizeof(char *) * (lines_num + 1));
    if (!s->map)
         return (write(2, "Error\nallocation failed\n", 25), close(fd), 0);
    fd = open(av[1], O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        s->map[i] = ft_strtrim(line, "\n");
        i++;
        free(line);
    }
    s->map[i] = NULL;
    close(fd);
    return (1);
}

int check(int ac, char **av)
{
    t_game s;
    
    if (ac != 2)
         return (write(2, "Error\nless than 2 ac", 21), 0);
    if (!cheak_ber(av[1]))
        return (write(2, "Error\nnot .ber file\n", 21), 0);
    read_map(av, &s);
    if (!same_rows(&s))
    {
        free_2d(s.map);
        return (write(2, "Error\nnot reqtiangle or invalid char\n", 38), 0);
    }
    if (!cheak_paths(&s))
        return (write(2, "Error\ninvalid pahts\n", 20), 0);
    return (1);
}