/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:36:59 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/05 00:20:39 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Move up:
Update player and collect positions, check limits and walls
update images in mlx window
print n_moves in terminal*/
void	move_up(t_solong *so_long)
{
	int	i;
	int	j;

	i = so_long->map->player_l;
	j = so_long->map->player_c;
	if ((i - 1 > 0) && (so_long->map->game_map[i - 1][j] != '1'))
	{
		if (!check_if_game_finished(so_long, i - 1, j))
			return ;
		so_long->map->player_l--;
		so_long->map->game_map[i - 1][j] = 'P';
		so_long->map->game_map[i][j] = '0';
		select_image(so_long, i, j);
		select_image(so_long, i - 1, j);
		so_long->n_moves++;
		printf("MOVES:%d\n", so_long->n_moves);
	}
}

/*Move down:
Update player and collect positions, check limits and walls
update images in mlx window
print n_moves in terminal*/
void	move_down(t_solong *so_long)
{
	int	i;
	int	j;

	i = so_long->map->player_l;
	j = so_long->map->player_c;
	if ((i + 1 < so_long->map->lin) && (so_long->map->game_map[i
				+ 1][j] != '1'))
	{
		if (check_if_game_finished(so_long, i + 1, j) == 0)
			return ;
		so_long->map->player_l++;
		so_long->map->game_map[i + 1][j] = 'P';
		so_long->map->game_map[i][j] = '0';
		select_image(so_long, i, j);
		select_image(so_long, i + 1, j);
		so_long->n_moves++;
		printf("MOVES:%d\n", so_long->n_moves);
	}
}

/*Move left:
Update player and collect positions, check limits and walls
update images in mlx window
print n_moves in terminal*/
void	move_left(t_solong *so_long)
{
	int	i;
	int	j;

	i = so_long->map->player_l;
	j = so_long->map->player_c;
	if ((j - 1 > 0) && (so_long->map->game_map[i][j - 1] != '1'))
	{
		if (check_if_game_finished(so_long, i, j - 1) == 0)
			return ;
		so_long->map->player_c--;
		so_long->map->game_map[i][j - 1] = 'P';
		so_long->map->game_map[i][j] = '0';
		select_image(so_long, i, j);
		select_image(so_long, i, j - 1);
		so_long->n_moves++;
		printf("MOVES:%d\n", so_long->n_moves);
	}
}

/*Move right:
Update player and collect positions, check limits and walls
update images in mlx window
print n_moves in terminal*/
void	move_right(t_solong *so_long)
{
	int	i;
	int	j;

	i = so_long->map->player_l;
	j = so_long->map->player_c;
	if ((j + 1 < so_long->map->col) && (so_long->map->game_map[i][j
			+ 1] != '1'))
	{
		if (check_if_game_finished(so_long, i, j + 1) == 0)
			return ;
		so_long->map->player_c++;
		so_long->map->game_map[i][j + 1] = 'P';
		so_long->map->game_map[i][j] = '0';
		select_image(so_long, i, j);
		select_image(so_long, i, j + 1);
		so_long->n_moves++;
		printf("MOVES:%d\n", so_long->n_moves);
	}
}

/*keypress treatment*/
int	key_press(int key_code, t_solong *param)
{
	if (key_code == KEY_ESC)
		free_mem_exit(param);
	if (key_code == KEY_UP || key_code == KEY_W)
		move_up(param);
	if (key_code == KEY_DOWN || key_code == KEY_S)
		move_down(param);
	if (key_code == KEY_LEFT || key_code == KEY_A)
		move_left(param);
	if (key_code == KEY_RIGHT || key_code == KEY_D)
		move_right(param);
	return (1);
}
