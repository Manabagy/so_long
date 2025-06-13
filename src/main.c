/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:19:28 by mabaghda          #+#    #+#             */
/*   Updated: 2025/06/13 21:40:52 by manana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	animate_coin(t_game *data)
{
	if (data->index == 4)
		data->index = 0;
	else
		data->index++;
	data->img_main_collective = data->img_collective[data->index];
}

int	render_next_frame(t_game *data)
{
	if (!data)
		return (0);
	data->counter++;
	if (data->counter >= 6000)
	{
		draw_map(data);
		write_movements(data);
		animate_coin(data);
		data->counter = 0;
	}
	return (1);
}

void	count_components(char *line, t_comp *comp_list)
{
	int	i;

	i = 0;
	if (!line || !comp_list)
		return ;
	while (line[i])
	{
		if (line[i] == 'P')
			comp_list->player_count++;
		if (line[i] == 'E')
			comp_list->exit_count++;
		if (line[i] == 'C')
			comp_list->coll_count++;
		i++;
	}
}

void	start_game(t_game *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (data->width * SIZE), (data->height
				* SIZE), "so_long");
	init_images(data);
	draw_map(data);
	mlx_key_hook(data->win, key_handler, data);
	mlx_hook(data->win, 17, 1L << 0, close_window, data);
	mlx_loop_hook(data->mlx, render_next_frame, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc != 2)
		return (ft_printf("Error\nGive me a map!\n"), 1);
	init_game(&data);
	if (!check_map(argv[1], &data))
		return (ft_printf("Error\nInvalid map!\n"), 1);
	if (!check_path(&data))
		return (ft_printf("Error\nInvalid Path\n"), free_array(data.map), 1);
	start_game(&data);
	return (0);
}
