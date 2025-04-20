/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradwan <aradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:08:44 by aradwan           #+#    #+#             */
/*   Updated: 2025/04/20 15:50:01 by aradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cheak_ber(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	s;

	ft_bzero(&s, sizeof(t_game));
	if (!check(ac, av, &s))
		return (0);
	s.mlx = mlx_init();
	s.win = mlx_new_window(s.mlx, (s.x - 1) * T_S, s.y * T_S, "so long");
	if (!load_images(&s))
	{
		mlx_destroy_window(s.mlx, s.win);
		return (ft_putendl_fd("error", 2), free_map(s.map), 0);
	}
	put_image_in_tile(&s);
	mlx_key_hook(s.win, handle_key, &s);
	mlx_hook(s.win, 17, 0, close_game, &s);
	mlx_loop(s.mlx);
}
