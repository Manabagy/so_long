/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:18:51 by mabaghda          #+#    #+#             */
/*   Updated: 2025/06/25 12:05:35 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	load_image(void *mlx, void **img, char *path)
{
	int	w;
	int	h;

	*img = mlx_xpm_file_to_image(mlx, path, &w, &h);
}

void	init_images(t_game *data)
{
	load_image(data->mlx, &data->img_wall, "textures/100rock.xpm");
	load_image(data->mlx, &data->img_floor, "textures/100space.xpm");
	load_image(data->mlx, &data->img_player, "textures/100loki.xpm");
	load_image(data->mlx, &data->img_player_right, "textures/100lokiright.xpm");
	load_image(data->mlx, &data->img_player_left, "textures/100lokileft.xpm");
	load_image(data->mlx, &data->img_exit, "textures/100asgard.xpm");
	load_image(data->mlx, &data->img_enemy, "textures/100thanos.xpm");
	load_image(data->mlx, &data->img_collective[0], "textures/stone1.xpm");
	load_image(data->mlx, &data->img_collective[1], "textures/stone2.xpm");
	load_image(data->mlx, &data->img_collective[2], "textures/stone3.xpm");
	load_image(data->mlx, &data->img_collective[3], "textures/stone4.xpm");
	load_image(data->mlx, &data->img_collective[4], "textures/stone5.xpm");
	if (!data->img_wall || !data->img_floor || !data->img_collective[0]
		|| !data->img_collective[1] || !data->img_collective[2]
		|| !data->img_collective[3] || !data->img_collective[4]
		|| !data->img_player || !data->img_player_right
		|| !data->img_player_left || !data->img_exit || !data->img_enemy)
	{
		ft_printf("Error: Failed to load one or more textures\n");
		exit(1);
	}
	data->player_main_img = data->img_player;
	data->img_main_collective = data->img_collective[1];
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
				draw_image(data, data->player_main_img, i, j);
			else if (data->map[i][j] == 'C')
				draw_image(data, data->img_main_collective, i, j);
			else if (data->map[i][j] == 'E')
				draw_image(data, data->img_exit, i, j);
			j++;
		}
		i++;
	}
}

void	write_movements(t_game *data)
{
	char	*s;

	s = ft_itoa(data->moves);
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, "Movements:");
	mlx_string_put(data->mlx, data->win, 75, 10, 0xFFFFFF, s);
	free(s);
}
