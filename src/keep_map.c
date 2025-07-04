/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:43:16 by mabaghda          #+#    #+#             */
/*   Updated: 2025/06/25 11:42:06 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	fill_map(char *line, t_game *data)
{
	if (!line)
	{
		free_array(data->map);
		return (0);
	}
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	data->map[data->check_map.times] = ft_strdup(line);
	if (!(data->map[data->check_map.times]))
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
		if (!is_empty_or_spaces(line))
		{
			if (!fill_map(line, data))
				return (0);
			data->check_map.times++;
		}
		free(line);
		line = get_next_line(fd);
	}
	data->map[data->check_map.times] = NULL;
	return (close(fd), free(line), 1);
}

void	flood_fill_coll(char **map, int x, int y, int *found_c)
{
	if (map[y][x] == '1' || map[y][x] == 'L' || map[y][x] == 'E')
		return ;
	if (map[y][x] == 'C')
		(*found_c)++;
	map[y][x] = 'L';
	flood_fill_coll(map, x + 1, y, found_c);
	flood_fill_coll(map, x - 1, y, found_c);
	flood_fill_coll(map, x, y + 1, found_c);
	flood_fill_coll(map, x, y - 1, found_c);
}

void	flood_fill_exit(char **map, int x, int y, int *exit)
{
	if (map[y][x] == '1' || map[y][x] == 'L')
		return ;
	if (map[y][x] == 'E')
	{
		*exit = 1;
		return ;
	}
	map[y][x] = 'L';
	flood_fill_exit(map, x + 1, y, exit);
	flood_fill_exit(map, x - 1, y, exit);
	flood_fill_exit(map, x, y + 1, exit);
	flood_fill_exit(map, x, y - 1, exit);
}

char	**dup_map(char **map, int size)
{
	char	**duplicate;
	int		i;

	i = 0;
	duplicate = (char **)malloc(sizeof(char *) * (size + 1));
	if (!duplicate)
		return (NULL);
	while (i < size)
	{
		duplicate[i] = ft_strdup(map[i]);
		if (!duplicate[i])
		{
			free_array(duplicate);
			return (NULL);
		}
		i++;
	}
	duplicate[i] = NULL;
	return (duplicate);
}
