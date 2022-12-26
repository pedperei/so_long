/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:52:16 by pedperei          #+#    #+#             */
/*   Updated: 2022/12/25 00:14:43 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*cria um mapa vazio que irá ser utilizado para se gravar 
as posições onde já se fez check anteriormente e para saber se já 
se fez check a um collectible na função do check_possible_path*/
char	**blank_map(int lin, int col)
{
	char	**blank_map;
	int		i;

	blank_map = (char **)ft_calloc(lin, sizeof(char *));
	i = 0;
	while (i < lin)
	{
		blank_map[i] = (char *)calloc(col + 1, sizeof(char));
		i++;
	}
	return (blank_map);
}

/*aloca memória para gravar o mapa como array de strings (char **)
utiliza-se a funcao get_next_line para ir lendo as linhas 
passadas no ficheiro com a estrutura do mapa (.ber)*/
char	**read_map(char *str_map)
{
	int		fd;
	int		i;
	int		lines;
	char	**map;

	lines = count_lines(str_map);
	map = (char **)ft_calloc(lines, sizeof(char *));
	fd = open(str_map, O_RDONLY);
	i = -1;
	while (++i < lines)
		map[i] = get_next_line(fd);
	close(fd);
	return (map);
}

int	char_errors(t_map *map)
{
	if (map->check_chars != 1)
	{
		printf("Error\nInvalid characthers\n");
		return (0);
	}
	if (map->count_exit != 1)
	{
		printf("Error\nInvalid number of exits\n");
		return (0);
	}
	if (map->count_player != 1)
	{
		printf("Error\nInvalid number of players\n");
		return (0);
	}
	if (map->count_collect < 1)
	{
		printf("Error\nInvalid number of collectibles\n");
		return (0);
	}
	return (1);
}

t_map	*init_map(char **str_map)
{
	t_map	*map;
	char	**save_path;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	map->game_map = read_map(str_map[1]);
	map->lin = count_lines(str_map[1]);
	if (!is_rectangule(map))
		return (free_t_map(map, 'r'));
	if (!is_wall(map))
		return (free_t_map(map, 'w'));
	map->check_chars = check_chars(map);
	if (!char_errors(map))
		return (free_t_map(map, 'n'));
	save_path = blank_map(map->lin, map->col);
	is_path_doable(map, save_path, map->player_l, map->player_c);
	free_map(save_path, map->lin);
	if (!(map->check_path_exit)
		|| !(map->check_path_collect == map->count_collect))
		return (free_t_map(map, 'p'));
	printf("Map correct\n");
	return (map);
}
