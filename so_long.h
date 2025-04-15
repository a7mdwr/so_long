
#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>

#define OPEN_MAX 1024

typedef struct s_game
{
    char **map;
    char **map_dup;
    int C;
    int P;
    int p_x;
    int p_y;
    int E;
    int x;
    int y;
    int map_width;
    int map_height;
}   t_game;

int same_rows(t_game *s);
void print_map(char **map);
char **copy_map(t_game *s);
int cheak_paths(t_game *s);
void paths(int x, int y, char **map, t_game *s);
void	free_2d(char **str);

#endif