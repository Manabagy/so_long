/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:43:16 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/27 12:45:11 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	fill_map(char *line, t_game *data, int times)
{
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	data->map[times] = ft_strdup(line);
	if (!data->map[times])
	{
		free_array(data->map);
		return (0);
	}
	return (1);
}

int	allocate_map(char *filename, t_game *data)
{
	char	*line;
	int		fd;
	int		times;

	times = 0;
	fd = open(filename, O_RDONLY);
	if (!fd)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	data->map = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (!data->map)
		return (0);
	while (line != NULL)
	{
		fill_map(line, data, times);
		free(line);
		line = get_next_line(fd);
		times++;
	}
	data->map[times] = NULL;
	free(line);
	close(fd);
	return (1);
}
