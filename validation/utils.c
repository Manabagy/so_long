/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:23:58 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/19 19:13:16 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int	firstnlast(line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i] && line[i] != '\n')
// 	{
// 		if (line[i] != 1)
// 			return (0);
// 	}
// 	return (1);
// }

int	check_comp_count(t_comp *comp_list)
{
	if (comp_list->player_count != 1)
		return (0);
	else if (comp_list->exit_count != 1)
		return (0);
	return (1);
}

int	width_height_count(char *filename, t_game *data)
{
	char	*line;
	int		line_count;
	int		fd;

	line_count = 1;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		line_count++;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		data->width = ft_strlen(line);
		if (ft_strlen(line) != data->width || line[0] == '\n')
			return (0);
		line = get_next_line(fd);
	}
	data->height = line_count;
	return (1);
}
