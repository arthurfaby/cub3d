#include "cub3d.h"

int	parse_elements_and_check_map(const char *map)
{
	int	fd;
	int	ret;

	ret = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error(ERROR" : open map failed.\n");
		return (1);
	}
	
}
