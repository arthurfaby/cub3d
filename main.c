#include "includes/cub3d.h"

int	main(int argc, char *argv[])
{
	int	ret;

	if (argc != 2)
	{
		ft_print_error(ERROR": format must be [%s <map.cub>]\n", argv[0]);
		return (0);
	}
	printf("Welcome to cub3d :)\n");
	ret = launch_game(argv);
	//cub3d here and its done
	return (ret);
}
