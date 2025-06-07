/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:45:04 by mabaghda          #+#    #+#             */
/*   Updated: 2025/06/07 18:47:02 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static void	destroy_collective(t_game *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (data->img_collective[i])
			mlx_destroy_image(data->mlx, data->img_collective[i]);
		i++;
	}
}

int	close_window(t_game *data)
{
	if (data->img_wall)
		mlx_destroy_image(data->mlx, data->img_wall);
	if (data->img_floor)
		mlx_destroy_image(data->mlx, data->img_floor);
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
	destroy_collective(data);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_array(data->map);
	exit(0);
}
