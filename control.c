/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:43:32 by aradwan           #+#    #+#             */
/*   Updated: 2025/04/20 14:45:28 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	printer(t_game *s)
{
	write(1, "moves : ", 9);
	ft_putnbr_fd(s->moves++, 1);
	write(1, "\n", 1);
}

void	move_player(t_game *s, int new_y, int new_x)
{
	if (s->map[new_y][new_x] == '1')
		return ;
	if (s->map[new_y][new_x] == 'C')
		s->c--;
	if (s->map[new_y][new_x] == 'E')
	{
		if (s->c == 0)
		{
			write(1, "You win\n", 8);
			close_game(s);
		}
		else
			return ;
	}
	printer(s);
	s->map[s->p_x][s->p_y] = '0';
	s->map[new_y][new_x] = 'P';
	s->p_x = new_y;
	s->p_y = new_x;
	cleaner(s);
	load_images(s);
	put_image_in_tile(s);
}

int	handle_key(int keycode, t_game *s)
{
	int	i;

	i = 0;
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W)
		move_player(s, s->p_x - 1, s->p_y);
	else if (keycode == KEY_S)
		move_player(s, s->p_x + 1, s->p_y);
	else if (keycode == KEY_A)
		move_player(s, s->p_x, s->p_y - 1);
	else if (keycode == KEY_D)
		move_player(s, s->p_x, s->p_y + 1);
	return (0);
}

int	close_game(t_game *s)
{
	mlx_destroy_image(s->mlx, s->player);
	mlx_destroy_image(s->mlx, s->floor);
	mlx_destroy_image(s->mlx, s->wall);
	mlx_destroy_image(s->mlx, s->exit);
	mlx_destroy_image(s->mlx, s->collect);
	mlx_clear_window(s->mlx, s->win);
	mlx_destroy_window(s->mlx, s->win);
	free_map(s->map);
	exit(0);
	return (0);
}
