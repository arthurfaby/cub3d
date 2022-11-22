#include "cub3d.h"

void	init_window(t_window *window)
{
	window->mlx = mlx_init();
	window->height = 1080;
	window->width = 1920;
	window->win = mlx_new_window(
		window->mlx,
		window->width,
		window->height,
		"cub3d"
		);
	window->image = malloc(sizeof(t_image)); 
	// check malloc
	window->image->img = mlx_new_image(window->mlx, window->width, window->height);
	window->image->addr = mlx_get_data_addr(window->image->img, &window->image->bpp, &window->image->line_len, &window->image->endian);
}
