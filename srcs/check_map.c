#include "cub3d.h"

static int	check_valid_char(char c)
{
	if (c == ' ' || c == '1' || c == '0' || c == 'N'
		|| c == 'W' || c == 'E' || c== 'S' || c =='\n')
		return (1);
	ft_print_error(ERROR" : char [%c] is not valid in the map.\n", c);
	return (0);
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
		if (ft_strcmp(line, "\n") != 0/* && !line_contains_elem(line)*/)
			break;	
		free(line);
		line = get_next_line(fd, 1);
	}
	ft_printf("LINE : %s\n", line);
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
