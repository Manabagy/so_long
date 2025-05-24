/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:07:17 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/24 11:45:32 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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

void	init_game(t_comp *comp_list, t_game *data)
{
	comp_list->player_count = 0;
	comp_list->exit_count = 0;
	comp_list->coll_count = 0;
	data->height = 0;
}
