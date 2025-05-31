/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:10:06 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/31 19:02:17 by manana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	first_and_last_wall(int fd)
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
		if (last_line)
			free(last_line);
		last_line = ft_strdup(line);
		if (!valid_characters(line))
			return (free(line), free(first_line), free(last_line), 0);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!firstnlast(first_line) || !firstnlast(last_line))
		return (free(first_line), free(last_line), 0);
	free(first_line);
	free(last_line);
	return (1);
}

int	isvalid_map(int fd, t_comp *comp_list, t_game *data)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	data->width = width(line);
	(void)comp_list;
	while (line != NULL)
	{
		data->height++;
		if (data->width != width(line) || (!check_line(line, comp_list)))
			return (free(line), 0);
		free(line);
		line = get_next_line(fd);
	}
	if (!check_comp_count(comp_list))
		return (free(line), 0);
	free(line);
	close(fd);
	return (1);
}

int	check_map(char *filename, t_comp *comp_list, t_game *data)
{
	int	fd;
	int	len;

	(void)comp_list;
	(void)data;
	len = ft_strlen(filename);
	if (!(filename[len - 1] == 'r' && filename[len - 2] == 'e'
			&& filename[len - 3] == 'b' && filename[len - 4] == '.'))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!isvalid_map(fd, comp_list, data))
		return (close(fd), 0);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!first_and_last_wall(fd))
		return (close(fd), 0);
	close(fd);
	allocate_map(filename, data);
	return (1);
}

int	is_valid_path(char **map_dub)
{
	int	y;
	int	x;

	y = 0;
	while (map_dub[y])
	{
		x = 0;
		while (map_dub[y][x])
		{
			if (map_dub[y][x] == 'C' || map_dub[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_path(t_game *data, t_player *player)
{
	char	**dub;

	find_p_pos(data, player);
	dub = dup_map(data->map, data->height);
	flood_fill(dub, player->pos_x, player->pos_y);
	if (!is_valid_path(dub))
		return (0);
	return (1);
}
