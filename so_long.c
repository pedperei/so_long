/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:39:40 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/05 18:02:22 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Alloc memory to struct pointer (t_solong) 
where will be holded multiple information about the game.
Map is initialzated, if map is wrongly allocated
this struct pointer will be freed.
After this mlx library (mlx_ptr(void *) saved) will be initializated
and mlx window (win_ptr(void *) saved) will be initializated (size * pixels).
Then textures files are opened. Memory is freed if any problem occurs.
Then we put the textures files into the mlx window and define functions
to define behaviours to key presses (ESC, Movements)
and call function to loop over mlx pointer.*/
int	main(int argc, char **argv)
{
	t_solong	*so_long;

	(void)argc;
	so_long = (t_solong *)ft_calloc(1, sizeof(t_solong));
	if (!so_long)
		return (0);
	so_long->map = init_map(argv);
	if (!so_long->map)
	{
		free(so_long);
		return (0);
	}
	so_long->mlx_ptr = mlx_init();
	if (!so_long->mlx_ptr)
		return (free_mem_exit_error(so_long));
	so_long->win_ptr = mlx_new_window(so_long->mlx_ptr, so_long->map->col
			* PX, so_long->map->lin * PX, "so_long");
	if (!so_long->win_ptr)
		return (free_mem_exit_error(so_long));
	if (!open_xpm_images(so_long))
		return (free_mem_exit_error(so_long));
	put_images_to_game(so_long);
	mlx_hook(so_long->win_ptr, 17, 1L << 17, free_mem_exit, so_long);
	mlx_hook(so_long->win_ptr, 2, 1L << 0, key_press, so_long);
	mlx_loop(so_long->mlx_ptr);
}
