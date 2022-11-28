#include "includes/cub3d.h"

int	main(int argc, char *argv[])
{
	//t_map		map;
	//t_texture	texture;
	
	if (argc != 2)
	{
		ft_print_error(ERROR": format must be [%s <map.cub>]\n", argv[0]);
		return (0);
	}
	if (error(argv[1]) == 1)
		return (0);
	printf("Welcome to cub3d :)\n");
	launch_game(argv);
	//cub3d here and its done
	return (0);
}
