/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:18:51 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/30 13:21:15 by mabaghda         ###   ########.fr       */
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
}

int	draw_images(t_game *data)
{
	init_images(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_floor, 0 * 100, 0
		* 100);
	mlx_put_image_to_window(data->mlx, data->win, data->img_wall, 1 * 100, 0
		* 100);
	mlx_put_image_to_window(data->mlx, data->win, data->img_collective, 2 * 100,
		0 * 100);
	mlx_put_image_to_window(data->mlx, data->win, data->img_player, 3 * 100, 0
		* 100);
	return (0);
}
