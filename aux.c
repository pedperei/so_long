/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 23:01:09 by pedperei          #+#    #+#             */
/*   Updated: 2022/12/29 20:08:19 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_if_game_finished(t_solong *so_long, int pos_l, int pos_c)
{
	if (so_long->map->game_map[pos_l][pos_c] == 'C')
		so_long->map->count_collect--;
	else if (so_long->map->game_map[pos_l][pos_c] == 'E'
			&& so_long->map->count_collect > 0)
		return (0);
	else if (so_long->map->count_collect == 0
		&& so_long->map->game_map[pos_l][pos_c] == 'E')
		exit(0);
	return (1);
}

int	key_press1(void)
{
	exit(0);
}

