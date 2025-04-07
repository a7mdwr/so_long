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


void paths(int x, int y, char **map, t_long *s)
{
    if(map[x][y] == '1' || map[x][y] == 'X')
        return ;
    if (map[x][y] == 'C')
        s->C--;
    else if (map[x][y] == 'E')
        s->E--;
    map[x][y] = 'X';
    paths(x + 1, y , map, s);
    paths(x - 1, y , map, s);
    paths(x, y + 1, map, s);
    paths(x, y -1 , map, s);
}

int cheak_paths(t_long *s)
{
    paths(s->x, s->y, s->map_dup, s);
    if (s->P > 0 || s->E > 0 || s->C > 0)
        return 0;
    return 1;
}