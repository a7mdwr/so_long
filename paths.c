/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:38:59 by aradwan           #+#    #+#             */
/*   Updated: 2025/04/20 15:40:37 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	**copy_map(t_game *s)
{
	int	size;
	int	j;
	int	i;

	j = 0;
	size = 0;
	i = 0;
	while (s->map[size])
		size++;
	s->map_dup = malloc(sizeof(char *) * (size + 1));
	if (!s->map_dup)
		return (NULL);
	while (s->map[j])
	{
		s->map_dup[i] = ft_strdup(s->map[j]);
		j++;
		i++;
	}
	s->map_dup[i] = NULL;
	return (s->map_dup);
}

void	paths(int x, int y, char **map, t_game *s)
{
	if (map[x][y] == '1' || map[x][y] == 'X')
		return ;
	if (map[x][y] == 'C')
		s->c--;
	if (map[x][y] == 'E')
		s->e--;
	map[x][y] = 'X';
	paths(x + 1, y, map, s);
	paths(x - 1, y, map, s);
	paths(x, y + 1, map, s);
	paths(x, y -1, map, s);
}

int	cheak_paths(t_game *s)
{
	int		valid_collect;
	int		valid_exit;

	valid_collect = s->c;
	valid_exit = s->e;
	copy_map(s);
	paths(s->p_x, s->p_y, s->map_dup, s);
	free_map(s->map_dup);
	if (s->c > 0 || s->e > 0)
		return (0);
	s->c = valid_collect;
	s->e = valid_exit;
	return (1);
}
