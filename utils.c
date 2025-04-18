/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:07:17 by aradwan           #+#    #+#             */
/*   Updated: 2025/04/18 16:06:15 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	char_cheak(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E')
		return (1);
	else
		return (0);
}

static int	is_wall_line(char *row)
{
	int i;
	
	i = 0;
	while (row[i])
	{
		if (row[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

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

int count_chars(t_game *s)
{
    int i;
    int j;

    j = 0;
    while(s->map[j])
    {   
        i = 0;
        while(s->map[j][i])
        {
            if (s->map[j][i] == 'C')
                s->C++;
            else if (s->map[j][i] == 'P')
            {
                s->p_x = j;
                s->p_y = i;
                s->P++;
            }
            else if (s->map[j][i] == 'E')
                s->E++;
            i++;
        }
        j++;
    }
    if (s->C <= 0|| s->E != 1 || s->P != 1)
        return (0);
    return 1;
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
		return (write(2, "Error\nMap must have 1P, 1E, 1+C\n", 33), 1);
	return (1);
}
