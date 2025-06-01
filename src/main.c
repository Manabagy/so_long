/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:19:28 by mabaghda          #+#    #+#             */
/*   Updated: 2025/06/01 15:03:06 by mabaghda         ###   ########.fr       */
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
	if (!check_path(&data, &player, &comp_list))
		return (ft_printf("Error\nInvalid Path\n"), 1);
	start_game(&data, &comp_list);
	return (0);
}
