/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:19:28 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/30 13:24:18 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_comp		comp_list;
	t_game		data;
	t_player	player;

	if (argc != 2)
	{
		ft_printf("Error\nGive me a map!\n");
		return (1);
	}
	init_game(&comp_list, &data, &player);
	if (!check_map(argv[1], &comp_list, &data))
	{
		ft_printf("Error\nInvalid map!\n");
		return (1);
	}
	if (!check_path(&data, &player))
	{
		ft_printf("Invalid Path\n");
		return (1);
	}
	ft_printf("ok\n");
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "so_long");
	draw_images(&data);
	mlx_loop(data.mlx);
	return (0);
}
