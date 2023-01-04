/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:55 by afaby             #+#    #+#             */
/*   Updated: 2023/01/04 16:10:55 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	**malloc_board(int width, int height)
{
	int	**board;
	int	i;
	int	j;

	board = malloc(sizeof(int *) * (height + 1));
	if (!board)
		return (NULL);
	i = 0;
	while (i < height)
	{
		board[i] = malloc(sizeof(int) * width);
		if (!board[i])
			return (NULL);
		j = -1;
		while (++j < width)
			board[i][j] = 1;
		i++;
	}
	board[i] = NULL;
	return (board);
}

static int	convert_tile_and_check_player(t_map *map, char c, int i, int j)
{
	if (c == ' ')
		return (-1);
	if (c == '1')
		return (1);
	if (c == '0')
		return (0);
	if (c == '2')
		return (2);
	if (map->player.pos.x != 0)
		return (-42);
	map->player.pos.x = j + 0.5;
	map->player.pos.y = i + 0.5;
	if (c == 'N')
		map->player.angle = 3.0 * PI / 2.0;
	if (c == 'S')
		map->player.angle = PI / 2.0;
	if (c == 'W')
		map->player.angle = PI;
	if (c == 'E')
		map->player.angle = 0;
	return (0);
}

static int	treat_lines(char **line, int fd, int **board, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (*line && ft_strcmp(*line, "\n") != 0)
	{
		j = -1;
		while (++j < map->width)
		{
			if (j > (int)ft_strlen(*line) - 1)
				board[i][j] = -1;
			else
			{
				board[i][j] = convert_tile_and_check_player(map,
						(*line)[j], i, j);
				if (board[i][j] == -42)
					return (0);
			}
		}
		i++;
		free(*line);
		*line = get_next_line(fd, 1);
	}
	return (1);
}

static int	fill_board(int fd, t_map *map, int **board, char *line)
{
	int		ret;

	map->player.pos.x = 0;
	map->player.pos.y = 0;
	map->player.angle = 0;
	map->player.inclination = 0;
	while (line && ft_strcmp(line, "\n") == 0)
	{
		free(line);
		line = get_next_line(fd, 1);
	}
	ret = treat_lines(&line, fd, board, map);
	if (ret == 0)
		free(line);
	return (ret);
}

int	parse_map(int fd, t_game *game, char *line)
{
	int	**board;
	int	check;

	check = 0;
	board = malloc_board(game->map.width, game->map.height);
	if (!board)
		check = -1;
	if (!fill_board(fd, &game->map, board, line))
	{
		ft_print_error(ERROR" : 2 or more players in the map.\n");
		check = -1;
	}
	game->map.board = board;
	if (check_map_content(&game->map) == 1)
		check = -1;
	if (check == -1)
	{
		close(fd);
		quit(game);
	}
	return (check);
}
