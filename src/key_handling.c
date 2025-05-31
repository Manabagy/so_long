/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 19:27:59 by manana            #+#    #+#             */
/*   Updated: 2025/05/31 19:52:52 by manana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(int keycode, t_game *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	key_handler(int keycode, t_game *data)
{
	// if (keycode == KEY_ESC)
	//     close_window(data);
	if (keycode == KEY_W)
		move_player(data, -1, 0); // up
	else if (keycode == KEY_S)
		move_player(data, 1, 0); // down
	else if (keycode == KEY_A)
		move_player(data, 0, -1); // left
	else if (keycode == KEY_D)
		move_player(data, 0, 1); // rght
	return (0);
}

// mlx_key_hook(data->win, key_handler, data);
// mlx_hook(data->win, 17, 0, close_window, data);
