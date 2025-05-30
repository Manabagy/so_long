/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:18:51 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/30 12:37:07 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_images(t_game *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "so_long");
	mlx_loop(data->mlx);
	// data->img_wall = mlx_xpm_file_to_image(data->mlx, "textures/100rock.xpm");
	// data->img_floor = mlx_xpm_file_to_image(data->mlx, "textures/100space.xpm");
	// data->img_collective = mlx_xpm_file_to_image(data->mlx, "textures/100stone.xpm");
	// data->img_player = mlx_xpm_file_to_image(data->mlx, "textures/100lokiright.xpm");
}