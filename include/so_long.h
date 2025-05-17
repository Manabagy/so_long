/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:17:11 by mabaghda          #+#    #+#             */
/*   Updated: 2025/05/17 19:15:07 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl.h"
# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;

}			t_game;

typedef struct s_comp
{
	int count;
	char type;
	struct s_comp *next;
}	t_comp;

int			isvalid_map(char *filename);

#endif