/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:39:40 by pedperei          #+#    #+#             */
/*   Updated: 2022/12/30 14:46:19 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_solong	*so_long;

	(void)argc;
	so_long = (t_solong *)ft_calloc(1, sizeof(t_solong));
	so_long->map = init_map(argv);
	if (!so_long->map)
	{
		free(so_long);
		return (0);
	}
	so_long->mlx_ptr = mlx_init();
	so_long->win_ptr = mlx_new_window(so_long->mlx_ptr, so_long->map->col
			* PX, so_long->map->lin * PX, "so_long");
	open_xpm_images(so_long);
	put_images_to_game(so_long);
	mlx_hook(so_long->win_ptr, 17, 1L << 17, free_mem_exit, so_long);
	mlx_hook(so_long->win_ptr, 2, 1L << 0, key_press, so_long);
	mlx_loop(so_long->mlx_ptr);
}

/* int	main(int argc, char **argv)
{
	(void)argc;
	init_so_long(argv);
}
 */