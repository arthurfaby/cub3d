#include "cub3d.h"

static int	check_extension(const char *map)
{
	int	i;

	i = 0;
	if (ft_strlen(map) < 5)
	{
		ft_print_error(ERROR" : wrong extension.\n");
		return (1);
	}
	while (map[i + 4] != 0)
		i++;
	if (ft_strcmp(&map[i], ".cub") != 0)
	{
		ft_print_error(ERROR" : wrong extension.\n");
		return (1);
	}
	return (0);
}

static int	error_parsing_fd(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd, 1);
	while (line != NULL && ft_strcmp(line, "\n") == 0)
	{
		free(line);
		line = get_next_line(fd, 1);
	}
	if (line == NULL)
	{
		ft_printf(ERROR":empty file\n");
		return (1);
	}
	if (check_error_element(fd, line) == 1)
		return (1);
	if (check_map(fd, map))
		return (1);
	return (0);
}

int	error(const char *path, t_map *map)
{
	int	fd;

	if (check_extension(path) == 1)
		return (1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error(ERROR" : open map failed.\n");
		return (1);
	}
	if (error_parsing_fd(fd, map) == 1)
	{
		close(fd);
		return (1);
	}
	close (fd);
	return (0);
}
