/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:18:51 by mabaghda          #+#    #+#             */
/*   Updated: 2025/06/02 19:28:11 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_images(t_game *data)
{
	int	w;
	int	h;

	data->img_wall = mlx_xpm_file_to_image(data->mlx, "textures/100rock.xpm",
			&w, &h);
	data->img_floor = mlx_xpm_file_to_image(data->mlx, "textures/100space.xpm",
			&w, &h);
	data->img_collective = mlx_xpm_file_to_image(data->mlx,
			"textures/100stone.xpm", &w, &h);
	data->img_player = mlx_xpm_file_to_image(data->mlx, "textures/100loki.xpm",
			&w, &h);
	data->img_player_right = mlx_xpm_file_to_image(data->mlx,
			"textures/100lokiright.xpm", &w, &h);
	data->img_player_left = mlx_xpm_file_to_image(data->mlx,
			"textures/100lokileft.xpm", &w, &h);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "textures/100asgard.xpm",
			&w, &h);
	data->img_enemy = mlx_xpm_file_to_image(data->mlx, "textures/100thanos.xpm",
			&w, &h);
	if (!data->img_wall || !data->img_floor || !data->img_collective
		|| !data->img_player_right || !data->img_player_left || !data->img_exit
		|| !data->img_enemy || !data->img_player)
	{
		ft_printf("Error: Failed to load one or more textures\n");
		exit(1);
	}
}

void	draw_image(t_game *data, void *img, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->win, img, (j * SIZE), (i * SIZE));
}

void	draw_map(t_game *data)
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
				draw_image(data, data->img_player, i, j);
			else if (data->map[i][j] == 'C')
				draw_image(data, data->img_collective, i, j);
			else if (data->map[i][j] == 'E')
				draw_image(data, data->img_exit, i, j);
			else if (data->map[i][j] == 'M')
				draw_image(data, data->img_enemy, i, j);
			j++;
		}
		i++;
	}
}

void	start_game(t_game *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (data->width * SIZE), (data->height
				* SIZE), "so_long");
	init_images(data);
	draw_map(data);
	mlx_key_hook(data->win, key_handler, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
}
