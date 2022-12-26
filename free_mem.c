/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 01:35:49 by pedperei          #+#    #+#             */
/*   Updated: 2022/12/24 19:14:22 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_map(char **map, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return (map);
}

t_map	*free_t_map(t_map *map, char error)
{
	free_map(map->game_map, map->lin);
	free(map);
	map = NULL;
	if (error == 'r')
		printf("Error\nMap is not a rectangule\n");
	if (error == 'w')
		printf("Error\nMap is not surrounded by walls\n");
	if (error == 'p')
		printf("Error\nMap does not have a valid path to conclude the game\n");
	return (map);
}
