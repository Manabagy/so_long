/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:17:11 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/19 18:07:30 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
// # include "../minilibx-linux/mlx.h"
# include "gnl.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
}			t_game;

typedef struct s_comp
{
	int		player_count;
	int		exit_count;
	int		coll_count;
}			t_comp;

typedef struct s_player
{
	int		count;
	int		pos_x;
	int		pos_y;
}			t_player;

typedef struct s_collect
{
	int		count;
}			t_collect;

int			isvalid_map(char *filename);
int	check_comp_count(t_comp *comp_list);
int	width_height_count(int fd, t_game *data);

#endif