#include "includes/cub3d.h"

int	main(int argc, char *argv[])
{
<<<<<<< HEAD
	//t_map		map;
	//t_texture	texture;
	
	if (argc != 2)
	{
		ft_print_error(ERROR": format must be [%s <map.cub>]\n", argv[0]);
		return (0);
	}
	if (error(argv[1]) == 1)
		return (0);
=======
	(void) argc;

	printf("Welcome to cub3d :)\n");
	launch_game(argv);
>>>>>>> 45066660a60858ffaea68b3d706a8994a34ec3bf
	//cub3d here and its done
	return (0);
}
