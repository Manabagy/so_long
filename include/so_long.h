/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:17:11 by mabaghda          #+#    #+#             */
/*   Updated: 2025/06/11 16:41:14 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "gnl.h"
# include <fcntl.h>
# include <stdlib.h>

# define SIZE 100

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
}				t_player;

typedef struct s_comp
{
	int			player_count;
	int			exit_count;
	int			coll_count;
}				t_comp;

typedef struct s_game
{
	char		**map;
	void		*mlx;
	void		*win;
	void		*img_wall;
	void		*img_enemy;
	void		*player_main_img;
	void		*img_player;
	void		*img_player_right;
	void		*img_player_left;
	void		*img_floor;
	void		*img_exit;
	void		*img_collective[5];
	void		*img_main_collective;
	int			index;
	int			width;
	int			height;
	t_player	player;
	t_comp		comps;
	int			collected;
	int			moves;
	int			counter;
}				t_game;

int				isvalid_map(int fd, t_comp *comp_list, t_game *data);
int				check_line(char *line, t_comp *comp_list);
void			count_components(char *line, t_comp *comp_list);
int				check_wall(char *line);
int				check_comp_count(t_comp *comp_list);
int				first_and_last_wall(int fd);
int				firstnlast(char *line);
int				width(char *line);
int				valid_characters(char *line);
int				check_map(char *filename, t_game *data);
void			init_game(t_game *data);
int				allocate_map(char *filename, t_game *data);
void			*free_array(char **array);
int				fill_map(char *line, t_game *data, int times);
void			find_p_pos(t_game *data);
char			**dup_map(char **map, int size);
int				check_path(t_game *data);
void			flood_fill_coll(char **map, int x, int y, int *found_c);
void			flood_fill_exit(char **map, int x, int y, int *exit);
void			init_images(t_game *data);
void			draw_map(t_game *data);
void			start_game(t_game *data);
void			draw_image(t_game *data, void *img, int i, int j);
int				close_window(t_game *data);
int				key_handler(int keycode, t_game *data);
void			move_player(t_game *data, int move_y, int move_x);
void			change_pos(t_game *data, int new_pos_y, int new_pos_x);
void			write_movements(t_game *data);

#endif