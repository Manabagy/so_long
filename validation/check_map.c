/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:10:06 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/17 19:17:59 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int check_wall(char *line)
{ 
    if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
        return (0);
    
    return (1);
}

void count_components(char *line, t_comp *comp_list)
{
    int i = 0;
	t_comp current;
    
    while (line[i])
    {
        if (line[i] == 'P')
		{
            comp_list->player_count++;
		}
        
        i++;
    }
}


int	check_line(char *line, t_game data, t_comp comp_list)
{
	count_components(line);
}

int	isvalid_map(char *filename)
{
	int fd;
	char *line;
	t_comp comp_list;
	t_game data;

	comp_list = NULL;
	data = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!check_line(line, data, comp_list))
		{
			ft_printf("Error");
			return (0);
		}
		line = get_next_line(fd);
	}
	check_comp_count(t_comp comp_list);
	return (1);
}