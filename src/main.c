/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:19:28 by mabaghda          #+#    #+#             */
/*   Updated: 2025/06/02 12:44:21 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc != 2)
	{
		return (ft_printf("Error\nGive me a map!\n"), 1);
	}
	init_game(&data);
	if (!check_map(argv[1], &data))
	{
		return (ft_printf("Error\nInvalid map!\n"), 1);
	}
	if (!check_path(&data))
		return (ft_printf("Error\nInvalid Path\n"), 1);
	start_game(&data);
	return (0);
}
