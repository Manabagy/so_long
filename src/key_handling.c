/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 19:27:59 by manana            #+#    #+#             */
/*   Updated: 2025/06/02 15:35:31 by mabaghda         ###   ########.fr       */
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
		move_player(data, -1, 0);
	else if (keycode == KEY_S)
		move_player(data, 1, 0);
	else if (keycode == KEY_A)
		move_player(data, 0, -1);
	else if (keycode == KEY_D)
		move_player(data, 0, 1);
	return (0);
}

void	move_player(t_game *data, int move_y, int move_x)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = data->player.pos_x + move_x;
	new_pos_y = data->player.pos_y + move_y;
	if (data->map[new_pos_y][new_pos_x] == '1')
		return ;
	if (data->map[new_pos_y][new_pos_x] == 'C')
		data->collected++;
	if (data->map[new_pos_y][new_pos_x] == 'E')
	{
		if (data->collected == data->comps.coll_count)
		{
			ft_printf("You won in %d moves!\n", data->moves + 1);
			close_window(data);
		}
		return ;
	}
	data->moves++;
	data->map[data->player.pos_y][data->player.pos_x] = '0';
	data->map[new_pos_y][new_pos_x] = 'P';
	draw_image(data, data->img_floor, data->player.pos_y, data->player.pos_x);
	draw_image(data, data->img_player_right, new_pos_y, new_pos_x);
	data->player.pos_x = new_pos_x;
	data->player.pos_y = new_pos_y;
}
