/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:23:58 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/19 18:09:36 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_comp_count(t_comp *comp_list)
{
	if (comp_list->player_count != 1)
		return (0);
	else if (comp_list->exit_count != 1)
		return (0);
	return (1);
}

int	width_height_count(int fd, t_game *data)
{
	char	*line;
	int		line_count;
	int		i;

	i = 0;
	line_count = 1;
	data->width = ft_strlen(line = get_next_line(fd));
	while ((line = get_next_line(fd)))
	{
		line = get_next_line(fd);
		line_count++;
		if (ft_strlen(line) != data->width || line[0] == '\n')
			return (0);
	}
	data->height = line_count;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != 1)
			return (0);
	}
	return (1);
}
