/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:43:58 by mabaghda          #+#    #+#             */
/*   Updated: 2025/06/25 12:39:29 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_map_bonus(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			draw_image(data, data->img_floor, i, j);
			if (data->map[i][j] == '1')
				draw_image(data, data->img_wall, i, j);
			else if (data->map[i][j] == 'P')
				draw_image(data, data->player_main_img, i, j);
			else if (data->map[i][j] == 'C')
				draw_image(data, data->img_main_collective, i, j);
			else if (data->map[i][j] == 'E')
				draw_image(data, data->img_exit, i, j);
			else if (data->map[i][j] == 'M')
				draw_image(data, data->img_enemy, i, j);
			j++;
		}
		i++;
	}
}

int	key_handler_bonus(int keycode, t_game *data)
{
	if (keycode == KEY_ESC)
		return (close_window(data));
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		move_player_bonus(data, -1, 0);
		data->player_main_img = data->img_player;
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		move_player_bonus(data, 1, 0);
		data->player_main_img = data->img_player;
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		move_player_bonus(data, 0, -1);
		data->player_main_img = data->img_player_left;
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		move_player_bonus(data, 0, 1);
		data->player_main_img = data->img_player_right;
	}
	write_movements(data);
	return (0);
}

static void	change_pos_bonus(t_game *data, int new_pos_y, int new_pos_x)
{
	data->map[data->player.pos_y][data->player.pos_x] = '0';
	data->map[new_pos_y][new_pos_x] = 'P';
	data->player.pos_x = new_pos_x;
	data->player.pos_y = new_pos_y;
	draw_map_bonus(data);
}

void	move_player_bonus(t_game *data, int move_y, int move_x)
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
	if (data->map[new_pos_y][new_pos_x] == 'M')
	{
		data->moves++;
		ft_printf("OOPS! You touched an enemy\nMoves: %d\n", data->moves);
		close_window(data);
	}
	data->moves++;
	change_pos_bonus(data, new_pos_y, new_pos_x);
}
