/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:07:17 by mabaghda          #+#    #+#             */
/*   Updated: 2025/06/07 18:42:47 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_line(char *line, t_comp *comp_list)
{
	if (!line)
		return (0);
	count_components(line, comp_list);
	if (!check_wall(line))
		return (0);
	return (1);
}

int	width(char *line)
{
	if (!line)
		return (0);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	return (ft_strlen(line));
}

int	check_comp_count(t_comp *comp_list)
{
	if (comp_list->player_count != 1 || comp_list->exit_count != 1
		|| comp_list->coll_count == 0)
		return (0);
	return (1);
}

static void	init_comps(t_game *data)
{
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	data->comps.player_count = 0;
	data->comps.exit_count = 0;
	data->comps.coll_count = 0;
}

void	init_game(t_game *data)
{
	init_comps(data);
	data->collected = 0;
	data->moves = 0;
	data->height = 0;
	data->width = 0;
	data->map = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->index = 0;
	data->img_main_collective = NULL;
	data->player_main_img = NULL;
	data->img_collective[0] = NULL;
	data->img_collective[1] = NULL;
	data->img_collective[2] = NULL;
	data->img_collective[3] = NULL;
	data->img_collective[4] = NULL;
	data->img_wall = NULL;
	data->img_player = NULL;
	data->img_player_right = NULL;
	data->img_player_left = NULL;
	data->img_floor = NULL;
	data->img_exit = NULL;
	data->img_enemy = NULL;
	data->counter = 0;
}
