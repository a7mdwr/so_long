
#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>

#define OPEN_MAX 1024


typedef struct s_long
{
    char **array;
    int x;
    int y;
}   t_long;

int same_rows(t_long *s);

#endif