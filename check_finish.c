/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 23:01:09 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/05 18:36:38 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*this function updates collectible count and stop exit when collectibles > 0
if all conditions are true to conclude the game message is printed 
and all memory is freed*/
int	check_if_game_finished(t_solong *so_long, int pos_l, int pos_c)
{
	if (so_long->map->game_map[pos_l][pos_c] == 'C')
		so_long->map->count_collect--;
	else if (so_long->map->game_map[pos_l][pos_c] == 'E'
			&& so_long->map->count_collect > 0)
		return (0);
	else if (so_long->map->count_collect == 0
		&& so_long->map->game_map[pos_l][pos_c] == 'E')
	{
		ft_printf("You won!! Game finished in %d moves!\n", so_long->n_moves);
		free_mem_exit(so_long);
	}
	return (1);
}
