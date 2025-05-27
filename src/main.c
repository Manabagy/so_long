/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:19:28 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/27 12:42:33 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_comp	comp_list;
	t_game	data;

	if (argc != 2)
		return (1);
	init_game(&comp_list, &data);
	if (!check_map(argv[1], &comp_list, &data))
	{
		ft_printf("Invalid map\n");
		return (1);
	}
	ft_printf("ok\n");
	return (0);
}
