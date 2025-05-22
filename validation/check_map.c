/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:10:06 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/22 20:49:44 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

int	isvalid_map(int fd)
{
	char	*line;
	t_comp	comp_list;
	t_game	data;

	data.height = 0;
	comp_list.player_count = 0;
	comp_list.exit_count = 0;
	comp_list.coll_count = 0;
	line = get_next_line(fd);
	data.width = width(line);
	while (line != NULL)
	{
		data.height++;
		if (data.width != width(line) || (!check_line(line, &comp_list)))
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	if (!check_comp_count(&comp_list))
		return (0);
	return (1);
}

int	check_map(char *filename)
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
	if (!isvalid_map(fd))
		return (0);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!first_and_last_wall(fd))
		return (0);
	return (1);
}
