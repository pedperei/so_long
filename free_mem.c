/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 01:35:49 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/05 00:09:09 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*free pointers*/
t_map	*free_pointers_maps(t_map *map, char **map_str)
{
	free(map);
	free(map_str);
	return (0);
}

/*free map char** */
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

/*free map memory (char**, map struct pointer)
print error message depending on tehtype of error*/
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

/*free char** map,, images and pointers in struct*/
int	free_mem_exit(t_solong *so_long)
{
	free_map(so_long->map->game_map, so_long->map->lin);
	mlx_destroy_image(so_long->mlx_ptr, so_long->img_ptr->collectible);
	mlx_destroy_image(so_long->mlx_ptr, so_long->img_ptr->empty);
	mlx_destroy_image(so_long->mlx_ptr, so_long->img_ptr->exit);
	mlx_destroy_image(so_long->mlx_ptr, so_long->img_ptr->player);
	mlx_destroy_image(so_long->mlx_ptr, so_long->img_ptr->wall);
	mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
	free(so_long->img_ptr);
	free(so_long->map);
	free(so_long->mlx_ptr);
	free(so_long);
	exit(0);
	return (1);
}

/*Free memory in case of error (mlx_ptr, win_ptr, open images)
images memory is not freed because is only allocated after
free char** map and pointers in struct*/
int	free_mem_exit_error(t_solong *so_long)
{
	free_map(so_long->map->game_map, so_long->map->lin);
	if (!so_long->mlx_ptr && !so_long->win_ptr)
		mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
	free(so_long->img_ptr);
	free(so_long->map);
	free(so_long->mlx_ptr);
	free(so_long);
	exit(0);
	return (1);
}
