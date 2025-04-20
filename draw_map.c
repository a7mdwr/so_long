/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:16:33 by aradwan           #+#    #+#             */
/*   Updated: 2025/04/20 15:21:06 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_images(t_game *s)
{
	int	dim;

	dim = T_S;
	s->player = mlx_xpm_file_to_image(s->mlx, P_P, &dim, &dim);
	s->floor = mlx_xpm_file_to_image(s->mlx, F_P, &dim, &dim);
	s->wall = mlx_xpm_file_to_image(s->mlx, W_P, &dim, &dim);
	s->exit = mlx_xpm_file_to_image(s->mlx, E_P, &dim, &dim);
	s->collect = mlx_xpm_file_to_image(s->mlx, C_P, &dim, &dim);
	if (!s->wall || !s->floor | !s->exit || !s->collect || !s->player)
		return (0);
	return (1);
}

void	cleaner(t_game *s)
{
	mlx_destroy_image(s->mlx, s->player);
	mlx_destroy_image(s->mlx, s->floor);
	mlx_destroy_image(s->mlx, s->wall);
	mlx_destroy_image(s->mlx, s->exit);
	mlx_destroy_image(s->mlx, s->collect);
	mlx_clear_window(s->mlx, s->win);
}

static void	help_put_image(t_game *s, int i, int j)
{
	if (s->map[j][i] == '1')
		mlx_put_image_to_window(s->mlx, s->win, s->wall, i * T_S, j * T_S);
	else if (s->map[j][i] == '0')
		mlx_put_image_to_window(s->mlx, s->win, s->floor, i * T_S, j * T_S);
	else if (s->map[j][i] == 'P')
	{
		mlx_put_image_to_window(s->mlx, s->win, s->floor, i * T_S, j * T_S);
		mlx_put_image_to_window(s->mlx, s->win, s->player, i * T_S, j * T_S);
	}
	else if (s->map[j][i] == 'E')
	{
		mlx_put_image_to_window(s->mlx, s->win, s->floor, i * T_S, j * T_S);
		mlx_put_image_to_window(s->mlx, s->win, s->exit, i * T_S, j * T_S);
	}
	else if (s->map[j][i] == 'C')
	{
		mlx_put_image_to_window(s->mlx, s->win, s->floor, i * T_S, j * T_S);
		mlx_put_image_to_window(s->mlx, s->win, s->collect, i * T_S, j * T_S);
	}
}

void	put_image_in_tile(t_game *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s->map[j])
	{
		i = 0;
		while (s->map[j][i])
		{
			help_put_image(s, i, j);
			i++;
		}
		j++;
	}
}
