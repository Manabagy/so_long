/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 19:27:59 by manana            #+#    #+#             */
/*   Updated: 2025/06/02 11:32:30 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_game *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	key_handler(int keycode, t_game *data)
{
	if (keycode == KEY_ESC)
		return (close_window(data));
	if (keycode == KEY_W)
		move_player(data, &data->player, -1, 0);
	else if (keycode == KEY_S)
		move_player(data, &data->player, 1, 0);
	else if (keycode == KEY_A)
		move_player(data, &data->player, 0, -1);
	else if (keycode == KEY_D)
		move_player(data, &data->player, 0, 1);
	return (0);
}

void	move_player(t_game *data, t_player *player, int move_y, int move_x)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = player->pos_x + move_x;
	new_pos_y = player->pos_y + move_y;
	if (new_pos_x < 0 || new_pos_y < 0 || new_pos_y >= data->height
		|| new_pos_x >= data->width)
		return ;
	if (data->map[new_pos_y][new_pos_x] == '1')
		return ;
	data->map[player->pos_y][player->pos_x] = '0';
	data->map[new_pos_y][new_pos_x] = 'P';
	player->pos_x = new_pos_x;
	player->pos_y = new_pos_y;
	draw_map(data);
}
