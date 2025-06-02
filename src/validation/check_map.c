/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:10:06 by mabaghda          #+#    #+#             */
/*   Updated: 2025/06/02 15:36:33 by mabaghda         ###   ########.fr       */
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

int	check_map(char *filename, t_game *data)
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
	if (!isvalid_map(fd, &data->comps, data))
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

int	check_path(t_game *data)
{
	char	**dup1;
	char	**dup2;
	int		found_c;
	int		exit_reached;

	found_c = 0;
	exit_reached = 0;
	find_p_pos(data);
	dup1 = dup_map(data->map, data->height);
	dup2 = dup_map(data->map, data->height);
	flood_fill_coll(dup1, data->player.pos_x, data->player.pos_y, &found_c);
	if (found_c != data->comps.coll_count)
		return (0);
	// return (free_array(dup1), free_array(dup2), 0);
	flood_fill_exit(dup2, data->player.pos_x, data->player.pos_y,
		&exit_reached);
	if (!exit_reached)
		return (0);
	// return (free_array(dup1), free_array(dup2), 0);
	// free_array(dup1);
	// free_array(dup2);
	return (1);
}
