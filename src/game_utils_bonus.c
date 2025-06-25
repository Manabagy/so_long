/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:32:18 by mabaghda          #+#    #+#             */
/*   Updated: 2025/06/25 13:00:01 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	valid_characters_bonus(char *line)
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

void	flood_fill_coll_bonus(char **map, int x, int y, int *found_c)
{
	if (map[y][x] == '1' || map[y][x] == 'L' || map[y][x] == 'E'
		|| map[y][x] == 'M')
		return ;
	if (map[y][x] == 'C')
		(*found_c)++;
	map[y][x] = 'L';
	flood_fill_coll(map, x + 1, y, found_c);
	flood_fill_coll(map, x - 1, y, found_c);
	flood_fill_coll(map, x, y + 1, found_c);
	flood_fill_coll(map, x, y - 1, found_c);
}

void	flood_fill_exit_bonus(char **map, int x, int y, int *exit)
{
	if (map[y][x] == '1' || map[y][x] == 'L' || map[y][x] == 'M')
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

int	first_and_last_wall_bonus(int fd)
{
	char	*line;
	char	*first_line;
	char	*last_line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	first_line = ft_strdup(line);
	last_line = NULL;
	while (line != NULL)
	{
		if (!is_empty_or_spaces(line))
		{
			free(last_line);
			last_line = ft_strdup(line);
			if (!valid_characters_bonus(line))
				return (free(line), free(first_line), get_next_line(-1),
					free(last_line), 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!firstnlast(first_line) || !firstnlast(last_line))
		return (free(line), free(first_line), free(last_line), 0);
	return (close(fd), free(line), free(first_line), free(last_line), 1);
}

int	check_map_bonus(char *filename, t_game *data)
{
	int	fd;
	int	len;

	len = ft_strlen(filename);
	if (!(filename[len - 1] == 'r' && filename[len - 2] == 'e'
			&& filename[len - 3] == 'b' && filename[len - 4] == '.'))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!check_empty_lines(fd, data))
		return (close(fd), 0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!isvalid_map(fd, &data->comps, data))
		return (close(fd), 0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!first_and_last_wall_bonus(fd))
		return (close(fd), 0);
	allocate_map(filename, data);
	return (1);
}
