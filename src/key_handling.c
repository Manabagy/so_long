/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 19:27:59 by manana            #+#    #+#             */
/*   Updated: 2025/06/25 12:58:45 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_handler(int keycode, t_game *data)
{
	if (keycode == KEY_ESC)
		return (close_window(data));
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		data->player_main_img = data->img_player;
		move_player(data, -1, 0);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		data->player_main_img = data->img_player;
		move_player(data, 1, 0);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		data->player_main_img = data->img_player_left;
		move_player(data, 0, -1);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		data->player_main_img = data->img_player_right;
		move_player(data, 0, 1);
	}
	return (0);
}

void	check_win(t_game *data)
{
	if (data->collected == data->comps.coll_count)
	{
		ft_printf("You won in %d moves!\n", data->moves + 1);
		close_window(data);
	}
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
		check_win(data);
		return ;
	}
	data->moves++;
	change_pos(data, new_pos_y, new_pos_x);
}

void	change_pos(t_game *data, int new_pos_y, int new_pos_x)
{
	data->map[data->player.pos_y][data->player.pos_x] = '0';
	data->map[new_pos_y][new_pos_x] = 'P';
	draw_image(data, data->img_floor, data->player.pos_y, data->player.pos_x);
	draw_image(data, data->player_main_img, new_pos_y, new_pos_x);
	data->player.pos_x = new_pos_x;
	data->player.pos_y = new_pos_y;
}
