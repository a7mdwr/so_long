#include "so_long.h"

char **copy_map(t_long *s)
{
    int size;
    int j;
    int i;

    j = 0;
    size = 0;
    i = 0;
    while (s->array[size])
        size++;
    s->map_dup = malloc(sizeof(char *) * (size + 1));
    if (!s->map_dup)
        return NULL;
    while(s->array[j])
    {
        s->map_dup[i] = ft_strdup(s->array[j]);
        j++;
        i++;
    }
    s->map_dup[i] = NULL;
    return (s->map_dup);
}


void cheak_path(int x, int y, char **map, t_long *s)
{
    if(map[x][y] )
}