/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:54:20 by aradwan           #+#    #+#             */
/*   Updated: 2025/04/18 18:54:24 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>

# define TILE_SIZE 64

typedef struct s_game
{
	char	**map;
	char	**map_dup;
	int		C;
	int		P;
	int		p_x;
	int		p_y;
	int		E;
	int		x;
	int		y;
	int		map_height;
}	t_game;

int		same_rows(t_game *s);
void	print_map(char **map);
char	**copy_map(t_game *s);
int		cheak_paths(t_game *s);
void	paths(int x, int y, char **map, t_game *s);
void	free_2d(char **str);
int		cheak_ber(char *file);
int		check(int ac, char **av);
int		read_map(char **av, t_game *s);
int		count_lines(int fd, t_game *s);
void	free_map(char **str);
int		char_cheak(char c);
int		is_wall_line(char *row);

#endif