#include "cub3d.h"

int	parse_all(const char *path, t_game *game)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error(ERROR" : open map failed.\n");
		return (1);
	}
	if (parse_elements(fd, game) == -1)
		return (-1);
	if (parse_map(fd, game) == -1)
		return (-1);
	return (0);
}
