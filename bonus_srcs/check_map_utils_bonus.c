/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:09:41 by afaby             #+#    #+#             */
/*   Updated: 2023/01/04 16:09:43 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_valid_char(char c)
{
	if (c == ' ' || c == '1' || c == '0' || c == 'N' || c == '2'
		|| c == 'W' || c == 'E' || c == 'S' || c == '\n')
		return (1);
	ft_print_error(ERROR" : char [%c] is not valid in the map.\n", c);
	return (0);
}

void	replace_one(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->board[i][j] == -1)
				map->board[i][j] = 1;
			j++;
		}
		i++;
	}
}

int	get_map_dimension(int fd, char **line, t_map *map)
{
	int	i;
	int	j;
	int	map_width;

	j = 0;
	map_width = 0;
	while (*line && ft_strcmp(*line, "\n") != 0)
	{
		j++;
		i = -1;
		while ((*line)[++i])
		{
			if (!check_valid_char((*line)[i]))
				return (1);
		}
		if (i > map_width)
			map_width = i;
		free(*line);
		*line = get_next_line(fd, 1);
	}
	map->height = j;
	map->width = map_width;
	return (0);
}
