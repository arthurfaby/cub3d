#include "includes/cub3d.h"

int	main(int argc, char *argv[])
{
	//t_map		map;
	//t_texture	texture;
	
	if (argc != 2)
	{
		ft_print_error("Error\n");
		ft_print_error("not the right number of arguments\n");
		return (0);
	}
	if (error(argv[1]) == 1)
		return (0);
	//cub3d here and its done
	return (0);
}
