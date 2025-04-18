#include "so_long.h"

void	free_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char **copy_map(t_game *s)
{
    int size;
    int j;
    int i;

    j = 0;
    size = 0;
    i = 0;
    while (s->map[size])
        size++;
    s->map_dup = malloc(sizeof(char *) * (size + 1));
    if (!s->map_dup)
        return NULL;
    while(s->map[j])
    {
        s->map_dup[i] = ft_strdup(s->map[j]);
        j++;
        i++;
    }
    s->map_dup[i] = NULL;
    return (s->map_dup);
}


void paths(int x, int y, char **map, t_game *s)
{
    if(map[x][y] == '1' || map[x][y] == 'X')
        return ;
    if (map[x][y] == 'C')
        s->C--;
    if (map[x][y] == 'E')
        s->E--;
    map[x][y] = 'X';
    paths(x + 1, y , map, s);
    paths(x - 1, y , map, s);
    paths(x, y + 1, map, s);
    paths(x, y -1 , map, s);
}

void print_map(char **map)
{
    int i = 0;

    if (!map)
    {
        printf("Map is NULL\n");
        return;
    }

    printf("===== Duplicated Map =====\n");
    while (map[i])
    {

        printf("%s\n", map[i]);
        i++;
    }
    printf("===========================\n");
}

int cheak_paths(t_game *s)
{
	int		valid_collect;
	int		valid_exit;

	valid_collect = s->C;
	valid_exit = s->E;
    copy_map(s);
	paths(s->p_x, s->p_y,s->map_dup, s);
    free_map(s->map_dup);
	if (s->C > 0 || s->E > 0)
        return (0);
	s->C = valid_collect;
	s->E = valid_exit;
	return (1);
}

