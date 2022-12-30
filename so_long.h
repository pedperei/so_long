/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:54:09 by pedperei          #+#    #+#             */
/*   Updated: 2022/12/30 14:46:00 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define PX 64

typedef struct s_map
{
	int			col;
	int			lin;
	int			check_wall;
	int			check_rectangule;
	int			check_chars;
	int			count_player;
	int			count_exit;
	int			count_collect;
	int			check_path_exit;
	int			check_path_collect;
	int			player_l;
	int			player_c;
	char		**game_map;
	char		**save_path;

}				t_map;

typedef struct s_images
{
	void		*wall;
	void		*player;
	void		*exit;
	void		*collectible;
	void		*empty;

}				t_images;

typedef struct s_solong
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_images	*img_ptr;
	int			n_moves;
	t_map		*map;

}				t_solong;

size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t nitems, size_t size);
t_map			*init_map(char **str_map);
int				count_lines(char *map);
int				is_wall(t_map *map);
int				is_rectangule(t_map *map);
int				check_chars(t_map *map);
void			is_path_doable(t_map *map, char **save_path, int pos_l,
					int pos_c);
char			**free_map(char **map, int lines);
t_map			*free_t_map(t_map *map, char error);
void			open_xpm_images(t_solong *so_long);
void			select_image(t_solong *so_long, int i, int j);
void			put_images_to_game(t_solong *so_long);
int				check_if_game_finished(t_solong *so_long, int pos_l, int pos_c);
int				key_press(int key_code, t_solong *param);
int				free_mem_exit(t_solong *so_long);

#endif
