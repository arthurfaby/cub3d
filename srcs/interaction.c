#include "cub3d.h"

void	open_door(t_window *window, t_map *map)
{
	t_point		pointing;
	t_player	player;
	(void)window;

	player = map->player;
	pointing.x = player.pos.x;
	pointing.y = player.pos.y;
	if (player.angle >= 7.0 * PI / 4.0 || player.angle < PI / 4.0)
		pointing.x += 1;
	if (player.angle >= PI / 4.0 && player.angle < 3.0 * PI / 4.0)
		pointing.y += 1;
	if (player.angle >= 3.0 * PI / 4.0 && player.angle < 5.0 * PI / 4.0)
		pointing.x -= 1;
	if (player.angle >= 5.0 * PI / 4.0 && player.angle < 7.0 * PI / 4.0)
		pointing.y -= 1;
	if (map->board[(int)pointing.y][(int)(pointing.x)] == 2)
		map->board[(int)pointing.y][(int)(pointing.x)] = 0;
/*		
	draw_line(window, &player.pos, &pointing, 0xFF00);
	if (*/
}
