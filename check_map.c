/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:54:29 by pedperei          #+#    #+#             */
/*   Updated: 2022/12/25 00:09:33 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

/*conta linhas existentes no mapa passado no ficheiro .ber
nºlinhas = nº de strings que irão ser alocadas + 1 (NULL terminator)*/
int	count_lines(char *map)
{
	int		fd;
	char	*str;
	int		i;

	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	i = 0;
	while (str != NULL)
	{
		i++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	is_path_doable(t_map *map, char **save_path, int pos_l, int pos_c)
{
	if (!(pos_l >= 0 && pos_l < map->lin && pos_c >= 0 && pos_c < map->col))
		return ;
	if (!(map->game_map[pos_l][pos_c] != '1'))
		return ;
	if (save_path[pos_l][pos_c] == '1')
		return ;
	if (map->game_map[pos_l][pos_c] == 'E')
		map->check_path_exit = 1;
	if (map->game_map[pos_l][pos_c] == 'C' && save_path[pos_l][pos_c] != '1')
		map->check_path_collect++;
	save_path[pos_l][pos_c] = '1';
	is_path_doable(map, save_path, pos_l + 1, pos_c);
	is_path_doable(map, save_path, pos_l, pos_c + 1);
	is_path_doable(map, save_path, pos_l - 1, pos_c);
	is_path_doable(map, save_path, pos_l, pos_c - 1);
	return ;
}

/*Vê se os caracteres pelos quais o mapa é composto são 
('0'- empty '1'- wall 'C' - collectible 'E' - exit 'P' - player)
grava as posicoes do player para se utilizar na função do check_possible_path,
conta nº de players (têm que ser = 1),
conta nº de collectables (têm que ser > 1) 
e conta nº de exits (têm que ser = 1)*/
int	check_chars(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->lin)
	{
		j = 0;
		while (map->game_map[i][j] != '\n' && map->game_map[i][j] != '\0')
		{
			if (map->game_map[i][j] == 'P')
			{
				map->count_player++;
				map->player_c = j;
				map->player_l = i;
			}
			else if (map->game_map[i][j] == 'C')
				map->count_collect++;
			else if (map->game_map[i][j] == 'E')
				map->count_exit++;
			else if (map->game_map[i][j] != '1' && map->game_map[i][j] != '0')
				return (0);
			j++;
		}
	}
	return (1);
}

/* Vê se o mapa passado corresponde a um rectângulo 
e grava nº de linhas e nº de colunas*/
int	is_rectangule(t_map *map)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(map->game_map[i]);
	while (i < map->lin)
	{
		if (ft_strlen(map->game_map[i]) != len)
			return (0);
		i++;
	}
	map->col = len;
	map->check_rectangule = 1;
	return (1);
}

/*Vê se as extremidades do mapa são todas caracter '1' (parede)*/
int	is_wall(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lin)
	{
		j = 0;
		while (map->game_map[i][j] != '\n' && map->game_map[i][j] != '\0')
		{
			if (i == 0 || i == (map->lin - 1))
			{
				if (map->game_map[i][j] != '1')
					return (0);
			}
			if (j == 0 || j == (map->col - 1))
			{
				if (map->game_map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	map->check_wall = 1;
	return (1);
}
