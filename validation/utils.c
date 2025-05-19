/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:23:58 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/19 22:29:11 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

int	check_comp_count(t_comp *comp_list)
{
	if (comp_list->player_count != 1 || comp_list->exit_count != 1
		|| comp_list->coll_count == 0)
		return (0);
	return (1);
}

int	first_and_last_wall(char *filename)
{
	char	*line;
	char	*first_line;
	char	*last_line;
	int		fd;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	first_line = line;
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		last_line = line;
		line = get_next_line(fd);
	}
	if (!firstnlast(first_line) || !firstnlast(last_line))
		return (0);
	return (1);
}
