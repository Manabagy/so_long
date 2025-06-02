/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 19:27:59 by manana            #+#    #+#             */
/*   Updated: 2025/06/02 19:24:34 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_game *data)
{
	if (data->img_wall)
		mlx_destroy_image(data->mlx, data->img_wall);
	if (data->img_floor)
		mlx_destroy_image(data->mlx, data->img_floor);
	if (data->img_collective)
		mlx_destroy_image(data->mlx, data->img_collective);
	if (data->img_player)
		mlx_destroy_image(data->mlx, data->img_player);
	if (data->img_player_right)
		mlx_destroy_image(data->mlx, data->img_player_right);
	if (data->img_player_left)
		mlx_destroy_image(data->mlx, data->img_player_left);
	if (data->img_exit)
		mlx_destroy_image(data->mlx, data->img_exit);
	if (data->img_enemy)
		mlx_destroy_image(data->mlx, data->img_enemy);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_array(data->map);
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
	{
		data->key_pressed = 1;
		move_player(data, 0, -1);
	}
	else if (keycode == KEY_D)
	{
		data->key_pressed = 2;
		move_player(data, 0, 1);
	}
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
	if (data->map[new_pos_y][new_pos_x] == 'M')
	{
		ft_printf("OOPS! You touched an enemy\nMoves: %d\n", data->moves);
		close_window(data);
	}
	data->moves++;
	change_pos(data, new_pos_y, new_pos_x);
}

void	change_pos(t_game *data, int new_pos_y, int new_pos_x)
{
	data->map[data->player.pos_y][data->player.pos_x] = '0';
	data->map[new_pos_y][new_pos_x] = 'P';
	draw_image(data, data->img_floor, data->player.pos_y, data->player.pos_x);
	if (data->key_pressed == 1)
		draw_image(data, data->img_player_left, new_pos_y, new_pos_x);
	else if (data->key_pressed == 2)
		draw_image(data, data->img_player_right, new_pos_y, new_pos_x);
	else
		draw_image(data, data->img_player, new_pos_y, new_pos_x);
	data->player.pos_x = new_pos_x;
	data->player.pos_y = new_pos_y;
}
