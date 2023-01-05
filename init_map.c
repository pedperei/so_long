/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:52:16 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/05 00:07:52 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*cria um mapa vazio que irá ser utilizado para se gravar 
as posições onde já se fez check anteriormente e para saber se já 
se fez check a um collectible na função is_path_doable*/
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

/*Aloca memória para gravar o mapa como array de strings (char **)
utiliza-se a funcao get_next_line para ir lendo as linhas 
passadas no ficheiro com a estrutura do mapa (.ber)*/
char	**read_map(char *str_map)
{
	int		fd;
	int		i;
	int		lines;
	char	**map;

	lines = count_lines(str_map);
	if (!lines)
		return (0);
	map = (char **)ft_calloc(lines, sizeof(char *));
	if (!map)
		return (0);
	fd = open(str_map, O_RDONLY);
	if (fd < 0 || fd > 4096)
		return (0);
	i = -1;
	while (++i < lines)
		map[i] = get_next_line(fd);
	close(fd);
	return (map);
}

/*Different messages in case of error invalid chars*/
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

/*This function initializate the map struct (str_map is argv)
The map is read and the result is put into the map struct and
free map struct pointer and char**(allocated in read_map) if error occurs.
Info about lines of the map is written into the struct and
map checkers are called (rectangule, wall, invalid chars). If some error happens
memory is freed and message(3 msg) with the description of the error is printed.
Next there is a function to check if there is a valid path to conclude the game.
Memory used in this function is freed and a message is printed in case of error.
Map struct is returned in case of success.
*/
t_map	*init_map(char **str_map)
{
	t_map	*map;
	char	**save_path;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (0);
	map->game_map = read_map(str_map[1]);
	if (!map->game_map)
		return (free_pointers_maps(map, map->game_map));
	map->lin = count_lines(str_map[1]);
	if (!is_rectangule(map))
		return (free_t_map(map, 'r'));
	if (!is_wall(map))
		return (free_t_map(map, 'w'));
	map->check_chars = check_chars(map);
	if (!char_errors(map))
		return (free_t_map(map, ' '));
	save_path = blank_map(map->lin, map->col);
	is_path_doable(map, save_path, map->player_l, map->player_c);
	free_map(save_path, map->lin);
	if (!(map->check_path_exit)
		|| !(map->check_path_collect == map->count_collect))
		return (free_t_map(map, 'p'));
	return (map);
}
