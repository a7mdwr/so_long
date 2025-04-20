/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:07:17 by aradwan           #+#    #+#             */
/*   Updated: 2025/04/20 14:04:41 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	helper_function(char **str)
{
	int	j;
	int	len;

	j = 0;
	if (!is_wall_line(str[0]))
		return (0);
	while (str[j])
	{
		len = ft_strlen(str[j]) - 1;
		if (str[j][0] != '1' || str[j][len] != '1')
			return (0);
		j++;
	}
	if (!is_wall_line(str[j - 1]))
		return (0);
	return (1);
}

static void	scan_map(t_game *s, int i, int j)
{
	if (s->map[j][i] == 'C')
		s->c++;
	else if (s->map[j][i] == 'P')
	{
		s->p_x = j;
		s->p_y = i;
		s->p++;
	}
	else if (s->map[j][i] == 'E')
		s->e++;
}

int	count_chars(t_game *s)
{
	int	i;
	int	j;

	j = 0;
	while (s->map[j])
	{
		i = 0;
		while (s->map[j][i])
		{
			scan_map(s, i, j);
			i++;
		}
		j++;
	}
	if (s->c <= 0 || s->e != 1 || s->p != 1)
		return (0);
	return (1);
}

static int	check_valid_chars(char **map)
{
	int	i;
	int	j;

	j = 1;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (!char_cheak(map[j][i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	same_rows(t_game *s)
{
	int	j;

	if (!check_valid_chars(s->map))
		return (0);
	j = 0;
	while (s->map[j] && s->map[j + 1])
	{
		if (ft_strlen(s->map[j]) != ft_strlen(s->map[j + 1]))
			return (0);
		j++;
	}
	if (!helper_function(s->map) || !count_chars(s))
		return (write(2, "error\nMap must have 1P, 1e, 1+C\n", 33), 1);
	return (1);
}
