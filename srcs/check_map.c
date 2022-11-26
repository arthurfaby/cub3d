#include "cub3d.h"

static int	line_contains_elem(char *line)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		return (1);
	if (ft_strnstr(line, "SO", ft_strlen(line)))
		return (1);
	if (ft_strnstr(line, "WE", ft_strlen(line)))
		return (1);
	if (ft_strnstr(line, "EA", ft_strlen(line)))
		return (1);
	if (ft_strnstr(line, "F", ft_strlen(line)))
		return (1);
	if (ft_strnstr(line, "C", ft_strlen(line)))
		return (1);
	return (0);
}

static int	check_valid_char(char c)
{
	if (c == ' ' || c == '1' || c == '0' || c == 'N'
		|| c == 'W' || c == 'E' || c== 'S' || c =='\n')
		return (1);
	ft_print_error(ERROR" : char [%c] is not valid in the map.\n", c);
	return (0);
}

int	check_map(const char *map)
{
	int		fd;
	int		map_width;
	int		map_height;
	char	*line;
	int		i;
	int		j;

	map_width = 0;
	map_height = 0;
	j = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error(ERROR" : open map failed.\n");
		return (1);
	}
	line = get_next_line(fd, 1);	
	while (line)
	{
		if (ft_strcmp(line, "\n") != 0 && !line_contains_elem(line))
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
	printf("width : %d\nheight : %d\n", map_width, map_height);
	if (line)
		free(line);
	return (0);
}
