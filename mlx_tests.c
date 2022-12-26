/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:39:40 by pedperei          #+#    #+#             */
/*   Updated: 2022/12/25 23:44:42 by pedperei         ###   ########.fr       */
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
		return 0;
	so_long->mlx_ptr = mlx_init();
	so_long->win_ptr = mlx_new_window(so_long->mlx_ptr, so_long->map->col * 64,
			so_long->map->lin * 64, "so_long");
	open_xpm_images(so_long);
	put_images_to_game(so_long);
	mlx_hook(so_long->win_ptr, 17, 1L << 17, key_press1, so_long);
	mlx_hook(so_long->win_ptr, 2, 1L << 0, key_press, so_long);
	mlx_loop(so_long->mlx_ptr);
}

/* int	main(int argc, char **argv)
{
	(void)argc;
	init_so_long(argv);
}
 */