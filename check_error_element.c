#include "includes/cub3d.h"

static int	value_elements(char *str)
{
	if (ft_strcmp(str, "NO") == 0)
		return (0);
	else if (ft_strcmp(str, "SO") == 0)
		return (1);
	else if (ft_strcmp(str, "WE") == 0)
		return (2);
	else if (ft_strcmp(str, "EA") == 0)
		return (3);
	else if (ft_strcmp(str, "F") == 0)
		return (4);
	else if (ft_strcmp(str, "C") == 0)
		return (5);

	else 
		return (-1);
}

static int	check_value_elements(char *element)
{
	int	fd;

	element[ft_strlen(element)] = 0;
	fd = open(element, O_RDONLY);
	if (fd == -1)
		return (1);
	close (fd);
	return (0);
}

static int check_value_color(char *color)
{
	char	**split_color;
	int		simple_color;
	int	i;

	i = 0;
	split_color = ft_split(color, ',');
	if (size_arr(split_color) < 3 || size_arr(split_color) > 3)
	{
		free_arr(split_color);
		return (1);
	}
	while (split_color[i] != NULL)
	{
		simple_color = ft_atoi(split_color[i]);
			if (simple_color > 255 || simple_color < 0)
			{
				free_arr(split_color);
				return (1);
			}
	}
	free_arr(split_color);
	return (0);
}

static int	check_line_element(char *line)
{
	int		value;
	char	**split_line;

	value = -1;
	split_line = ft_split(line, ' ');
	if (size_arr(split_line) < 1 || size_arr(split_line) > 2)
	{
		free_arr(split_line);
		return (value);
	}
	value = value_elements(split_line[0]);
	if (ft_strlen(split_line[0]) == 2)
	{
		if (check_value_elements(split_line[1]) == 1)
			value = -1;
	}
	else if (ft_strlen(split_line[0]) == 1)
	{
		if (value == -1 && check_value_color(split_line[1]) == 1)
			value = -1;
	}
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
			free(line);
			ft_print_error("Error\nBad elements\n");
			return (1);
		}
		else
			elements[check] = 1;
		++nb_elements;
		line = get_next_line(fd, 1);
	}
	return (0);
}
