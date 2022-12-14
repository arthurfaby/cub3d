#include "cub3d.h"

static int	check_valid_char(char c)
{
	if (c == ' ' || c == '1' || c == '0' || c == 'N' || c == '2'
		|| c == 'W' || c == 'E' || c== 'S' || c =='\n')
		return (1);
	ft_print_error(ERROR" : char [%c] is not valid in the map.\n", c);
	return (0);
}

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

static void	replace_one(t_map *map)
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
		return (0);
	}
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->board[i][j] == 0 || map->board[i][j] == 2)
				if (check_wall_border(map, i, j) == 0)
					return (0);
			j++;
		}
		i++;
	}
	replace_one(map);
	return (1);
}

int	check_map(int fd, t_map *map)
{
	int		map_width;
	int		map_height;
	char	*line;
	int		i;
	int		j;

	map_width = 0;
	map_height = 0;
	j = 0;
	line = get_next_line(fd, 1);
	while (line)
	{
		if (ft_strcmp(line, "\n") != 0)
			break;	
		free(line);
		line = get_next_line(fd, 1);
	}
	while (line && ft_strcmp(line, "\n") != 0)
	{
		j++;
		i = 0;
		while (line[i])
		{
			if (!check_valid_char(line[i]))
				return (1);
			i++;
		}
		if (i - 1 > map_width)
			map_width = i - 1;
		free(line);
		line = get_next_line(fd, 1);
	}
	map_height = j; 
	if (line)
	{
		ft_print_error(ERROR" : empty line inside or after map.\n");
		return (1);
	}
	free(line);
	map->width = map_width;
	map->height = map_height;
	return (0);
}
