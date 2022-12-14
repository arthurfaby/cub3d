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
			return (NULL); // free all before
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

static int	fill_board(int fd, t_map *map, int **board)
{
	int		i;
	int		j;
	char	*line;
	int		line_len;

	i = 0;
	line = get_next_line(fd, 1);
	while (line && ft_strcmp(line, "\n") == 0)
	{
		free(line);
		line = get_next_line(fd, 1);
	}
	while (line && ft_strcmp(line, "\n") != 0)
	{
		j = -1;
		line_len = ft_strlen(line);
		while (++j < map->width)
		{
			if (j > line_len - 2)
				board[i][j] = -1;
			else
			{
				board[i][j] = convert_tile_and_check_player(map, line[j], i, j);
				if (board[i][j] == -42)
					return (0);
			}
		}
		i++;
		free(line);
		line = get_next_line(fd, 1);
	}
	return (1);
}

int	parse_map(int fd, t_game *game)
{
	int	**board;

	board = malloc_board(game->map.width, game->map.height);
	if (!board)
		return (-1);
	if (!fill_board(fd, &game->map, board))
	{
		ft_print_error(ERROR" : 2 or more players in the map.\n");
		return (-1);
	}
	game->map.board = board;
	if (check_map_content(&game->map) == 0)
	{
		ft_print_error(ERROR" : map is not surrounded by walls.\n");
		// free everything
		return (-1);
	}
	return (0);
}
