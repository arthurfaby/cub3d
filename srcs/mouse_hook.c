#include "cub3d.h"

int	mouse_hook(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;

	if (button == 4)
		game->map.mmap_width += 1;
	if (button == 5)
		if (game->map.mmap_width > 2)
			game->map.mmap_width -= 1;
	draw_minimap(&game->window, &game->map);
	return (1);
}
