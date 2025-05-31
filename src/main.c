/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:19:28 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/31 19:23:02 by manana           ###   ########.fr       */
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
		return (ft_printf("Error\nGive me a map!\n"), 1);
	}
	init_game(&comp_list, &data, &player);
	if (!check_map(argv[1], &comp_list, &data))
	{
		return (ft_printf("Error\nInvalid map!\n"), 1);
	}
	if (!check_path(&data, &player))
	{
		return (ft_printf("Invalid Path\n"), 1);
	}
	init_images(&data);
	start_game(&data);
	return (0);
}
