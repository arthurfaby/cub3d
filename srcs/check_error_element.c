#include "cub3d.h"

static int	check_key_exists(char *key)
{
	if (ft_strcmp(key, "NO") == 0)
		return (1);
	if (ft_strcmp(key, "SO") == 0)
		return (1);
	if (ft_strcmp(key, "WE") == 0)
		return (1);
	if (ft_strcmp(key, "EA") == 0)
		return (1);
	if (ft_strcmp(key, "F") == 0)
		return (1);
	if (ft_strcmp(key, "C") == 0)
		return (1);
	return (0);
}

static int	check_line_element(char *line)
{
	int		value;
	char	**split_line;

	value = -1;
	split_line = ft_split(line, ' ');
	if (size_arr(split_line) != 2)
	{
		ft_printf(ERROR": too much arguments for [%s].\n", split_line[0]);
		free_arr(split_line);
		return (value);
	}
	split_line[1][ft_strlen(split_line[1]) - 1] = 0;
	if (!check_key_exists(split_line[0]))
	{
		ft_printf(ERROR": key [%s] is not valid.\n", split_line[0]);
		free_arr(split_line);
		return (-1);
	}
	if (ft_strlen(split_line[0]) == 2)
		value = check_value_texture(split_line);
	else if (ft_strlen(split_line[0]) == 1)
		value = check_value_color(split_line);
	free_arr(split_line);
	return (value);
}


int	check_error_element(int fd)
{
	int		elements[6];
	int		nb_elements;
	char	*line;
	int		check;

	ft_memset(elements, 0, 6);	
	line = get_next_line(fd, 1);
	nb_elements = 0;
	while (line != NULL && nb_elements != 6)
	{
		check = -1;
		if (ft_strcmp(line, "\n") != 0)
			check = check_line_element(line);
		if (check == -1 || elements[check] == 1)
		{
			if (check != -1 && elements[check] == 1)
				ft_printf(ERROR": double declartion somewhere.\n"); // put where
			free(line);
			//ft_print_error("Error\nBad color or textures\n");
			return (1);
		}
		else
		{
			elements[check] = 1;
			++nb_elements;
		}
		free(line);
		line = get_next_line(fd, 1);
	}
	return (0);
}
