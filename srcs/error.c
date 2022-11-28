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

static int	error_parsing_fd(int fd)
{
	if (check_error_element(fd) == 1)
		return (1);
	if (check_map(fd))
		return (1);
	return (0);
}

int error(const char *map)
{
	int	fd;

	if (check_extension(map) == 1)
		return (1);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error(ERROR" : open map failed.\n");
		return (1);
	}
	if (error_parsing_fd(fd) == 1)
	{
		close(fd);
		return (1);
	}
	close (fd);
	return (0);
}
