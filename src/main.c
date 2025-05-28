/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:19:28 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/28 16:15:41 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_comp		comp_list;
	t_game		data;
	t_player	player;
	void		*mlx;
	void		*mlx_win;

	if (argc != 2)
		return (1);
	init_game(&comp_list, &data, &player);
	if (!check_map(argv[1], &comp_list, &data))
	{
		ft_printf("Invalid map\n");
		return (1);
	}
	if (!check_path(&data, &player))
	{
		ft_printf("Invalid Path\n");
		return (1);
	}
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	mlx_loop(mlx);
	ft_printf("ok\n");
	return (0);
}
