/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:23:58 by mabaghda          #+#    #+#             */
/*   Updated: 2025/06/07 18:46:40 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	valid_characters(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'M')
			return (0);
		i++;
	}
	return (1);
}

int	firstnlast(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(char *line)
{
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
		return (0);
	else
		return (1);
}

void	find_p_pos(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player.pos_y = i;
				data->player.pos_x = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
