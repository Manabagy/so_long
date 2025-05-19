/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:10:06 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/19 22:23:51 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_wall(char *line)
{
	if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
		return (0);
	else
		return (1);
}

void	count_components(char *line, t_comp *comp_list)
{
	int	i;

	i = 0;
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
	count_components(line, comp_list);
	if (!check_wall(line))
		return (0);
	return (1);
}

void	width(char *line, t_game *data)
{
	if (!line)
		return ;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	data->width = ft_strlen(line);
}

int	isvalid_map(char *filename)
{
	int		fd;
	char	*line;
	t_comp	comp_list;
	t_game	data;

	data.height = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	width(line, &data);
	while (line != NULL)
	{
		data.height++;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (data.width != ft_strlen(line) || (!check_line(line, &comp_list)))
			return (0);
		line = get_next_line(fd);
	}
	close(fd);
	if (!first_and_last_wall(filename) || !check_comp_count(&comp_list))
		return (0);
	return (1);
}
