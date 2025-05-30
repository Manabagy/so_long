/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:18:51 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/30 14:59:04 by mabaghda         ###   ########.fr       */
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
	data->img_player = mlx_xpm_file_to_image(data->mlx,
			"textures/100lokiright.xpm", &w, &h);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "textures/100asgard.xpm",
			&w, &h);
}

void	draw_map(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	init_images(data);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img_floor, (j
					* SIZE), (i * SIZE));
			// if (data->map[i][j] == '0')
			// 	mlx_put_image_to_window(data->mlx, data->win, data->img_floor,
			// 		(j * SIZE), (i * SIZE));
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img_wall, (j
						* SIZE), (i * SIZE));
			else if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->img_player,
					(j * SIZE), (i * SIZE));
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->img_collective, (j * SIZE), (i * SIZE));
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->img_exit, (j
						* SIZE), (i * SIZE));
			j++;
		}
		i++;
	}
}

void	start_game(t_game *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (data->width * SIZE), (data->height * SIZE), "so_long");
	draw_map(data);
	mlx_loop(data->mlx);
}