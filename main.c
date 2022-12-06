#include "includes/cub3d.h"

int	main(int argc, char *argv[])
{
	int	ret;

	if (argc != 2)
	{
		ft_print_error(ERROR": format must be [%s <map.cub>]\n", argv[0]);
		return (0);
	}
	ret = launch_game(argv);
	return (ret);
}
