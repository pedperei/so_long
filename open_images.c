/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:52:39 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/05 00:22:06 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Open images of the different textures*/
int	open_xpm_images(t_solong *so_long)
{
	int			x;
	int			y;
	t_images	*image_type;

	image_type = (t_images *)ft_calloc(1, sizeof(t_images));
	if (!image_type)
		return (0);
	x = PX;
	y = PX;
	image_type->wall = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./textures/wall.xpm", &x, &y);
	image_type->player = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./textures/player.xpm", &x, &y);
	image_type->exit = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./textures/exit.xpm", &x, &y);
	image_type->collectible = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./textures/fish.xpm", &x, &y);
	image_type->empty = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./textures/water.xpm", &x, &y);
	so_long->img_ptr = image_type;
	return (1);
}

/*Select correct image and put int right place of mlx window*/
void	select_image(t_solong *so_long, int i, int j)
{
	if (so_long->map->game_map[i][j] == '1')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->img_ptr->wall, j * PX, i * PX);
	else if (so_long->map->game_map[i][j] == 'C')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->img_ptr->collectible, j * PX, i * PX);
	else if (so_long->map->game_map[i][j] == 'E')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->img_ptr->exit, j * PX, i * PX);
	else if (so_long->map->game_map[i][j] == 'P')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->img_ptr->player, j * PX, i * PX);
	else if (so_long->map->game_map[i][j] == '0')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->img_ptr->empty, j * PX, i * PX);
}

/*put images into the mlx window*/
void	put_images_to_game(t_solong *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->map->lin)
	{
		j = 0;
		while (j < so_long->map->col)
		{
			select_image(so_long, i, j);
			j++;
		}
		i++;
	}
}
