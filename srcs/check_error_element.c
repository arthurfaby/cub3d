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
		free_arr_char(split_line);
		return (value);
	}
	split_line[1][ft_strlen(split_line[1]) - 1] = 0;
	if (!check_key_exists(split_line[0]))
	{
		ft_printf(ERROR": key [%s] is not valid.\n", split_line[0]);
		free_arr_char(split_line);
		return (-2);
	}
	if (ft_strlen(split_line[0]) == 2)
		value = check_value_texture(split_line);
	else if (ft_strlen(split_line[0]) == 1)
		value = check_value_color(split_line);
	free_arr_char(split_line);
	return (value);
}

static int	verif_check(int check, char *line, int elements[7])
{
	if (ft_strcmp(line, "\n") == 0)
		return (0);
	if (check < 0)
	{
		free(elements);
		free(line);
		if (check == -1)
			ft_printf(ERROR": double declaration somewhere.\n");
		return (1);
	}
	else if (elements[check] == 1)
	{
		free(elements);
		free(line);
		ft_printf(ERROR": double declaration somewhere.\n");
		return (1);
	}
	elements[check] = 1;
	return (0);
}

static int	*init_check_elements(void)
{
	int	*elements;
	int	i;

	i = 0;
	elements = malloc(sizeof(int) * 8);
	if (!elements)
	{
		ft_print_error("MALLOC FAILED");
		return (NULL);
	}
	while (i < 8)
	{
		elements[i] = 0;
		i++;
	}
	return (elements);
}

int	check_error_element(int fd, char *line)
{
	int		*elements;
	int		nb_elements;
	int		check;

	elements = init_check_elements();
	if (!elements)
		return (1);
	nb_elements = 0;
	while (line != NULL && nb_elements != 7)
	{
		check = -1;
		if (ft_strcmp(line, "\n") != 0)
			check = check_line_element(line);
		if (verif_check(check, line, elements) == 1)
			return (1);
		if (ft_strcmp(line, "\n") != 0)
			nb_elements++;
		free(line);
		line = get_next_line(fd, 1);
	}
	free(line);
	free(elements);
	return (0);
}
