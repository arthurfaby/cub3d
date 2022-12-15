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
	if (ft_strcmp(key, "DO") == 0)
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
		ft_printf(ERROR": not two arguments for [%s].\n", split_line[0]);
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

static int	valid_element(int check, int nb_elements, int elements[7])
{
	elements[check] = 1;
	return (nb_elements + 1);
}

static char	*free_and_gnl(char *line, int fd)
{
	free(line);
	return (get_next_line(fd, 1));
}

int	check_error_element(int fd)
{
	int		elements[7];
	int		nb_elements;
	char	*line;
	int		check;

	ft_memset(elements, 0, 7);
	line = get_next_line(fd, 1);
	nb_elements = 0;
	while (line != NULL && nb_elements != 7)
	{
		check = -1;
		if (ft_strcmp(line, "\n") != 0)
			check = check_line_element(line);
		if (ft_strcmp(line, "\n") != 0 && (check == -1 || elements[check] == 1))
		{
			if (check != -1 && elements[check] == 1)
				ft_printf(ERROR": double declaration somewhere.\n");
			free(line);
			return (1);
		}
		else if (ft_strcmp(line, "\n") != 0)
			nb_elements = valid_element(check, nb_elements, elements);
		line = free_and_gnl(line, fd);
	}
	return (0);
}
