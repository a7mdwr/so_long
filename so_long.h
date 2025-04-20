/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:54:20 by aradwan           #+#    #+#             */
/*   Updated: 2025/04/20 14:47:08 by aradwan          ###   ########.fr       */
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
# include "mlx/mlx.h"

# define P_P "textures/player.xpm"
# define F_P "textures/floor.xpm"
# define W_P "textures/wall.xpm"
# define E_P "textures/exit.xpm"
# define C_P "textures/collect.xpm"
# define T_S 64
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_game
{
	char	**map;
	char	**map_dup;
	int		c;
	int		p;
	int		p_x;
	int		p_y;
	int		e;
	int		x;
	int		y;
	int		map_height;
	int		lines_num;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collect;
	int		moves;
}	t_game;

int		same_rows(t_game *s);
void	print_map(char **map);
char	**copy_map(t_game *s);
int		cheak_paths(t_game *s);
void	paths(int x, int y, char **map, t_game *s);
void	free_2d(char **str);
int		cheak_ber(char *file);
int		check(int ac, char **a, t_game *s);
int		read_map(char **av, t_game *s);
int		count_lines(int fd, t_game *s);
void	free_map(char **str);
int		char_cheak(char c);
int		is_wall_line(char *row);

// mlx func
int		load_images(t_game *s);
void	put_image_in_tile(t_game *s);
int		handle_key(int keycode, t_game *s);
int		close_game(t_game *s);
void	cleaner(t_game *s);
#endif