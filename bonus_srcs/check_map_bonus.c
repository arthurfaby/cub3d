/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:09:29 by afaby             #+#    #+#             */
/*   Updated: 2023/01/04 16:09:38 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_wall_border(t_map *map, int i, int j)
{
	if (i == map->height - 1 || i == 0)
		return (0);
	if (j == map->width - 1 || j == 0)
		return (0);
	if (map->board[i - 1][j] == -1)
		return (0);
	if (map->board[i + 1][j] == -1)
		return (0);
	if (map->board[i][j - 1] == -1)
		return (0);
	if (map->board[i][j + 1] == -1)
		return (0);
	return (1);
}

static int	check_if_there_player(t_map *map)
{
	if (map->player.pos.x == 0
		&& map->player.pos.y == 0
		&& map->player.angle == 0)
		return (-1);
	return (1);
}

int	check_map_content(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	if (check_if_there_player(map) == -1)
	{
		ft_print_error(ERROR" : there is no player in the map.\n");
		return (1);
	}
	while (i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if ((map->board[i][j] == 0 || map->board[i][j] == 2)
			&& check_wall_border(map, i, j) == 0)
			{
				ft_print_error(ERROR" : map is not surrounded by walls.\n");
				return (1);
			}
		}
		i++;
	}
	replace_one(map);
	return (0);
}

int	check_map(int fd, t_map *map, char *line)
{
	while (line)
	{
		if (ft_strcmp(line, "\n") != 0)
			break ;
		free(line);
		line = get_next_line(fd, 1);
	}
	if (get_map_dimension(fd, &line, map))
	{
		free(line);
		return (1);
	}
	if (line)
	{
		ft_print_error(ERROR" : empty line inside or after map.\n");
		free(line);
		return (1);
	}
	free(line);
	return (0);
}
