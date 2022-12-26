/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 23:01:09 by pedperei          #+#    #+#             */
/*   Updated: 2022/12/26 17:20:07 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_if_game_finished(t_solong *so_long, int pos_l, int pos_c)
{
	if (so_long->map->game_map[pos_l][pos_c] == 'C')
		so_long->map->count_collect--;
	if (so_long->map->count_collect == 0
		&& so_long->map->game_map[pos_l][pos_c] == 'E')
		exit(0);
}

int	key_press1(void)
{
	exit(0);
}

