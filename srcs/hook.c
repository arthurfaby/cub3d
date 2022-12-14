#include "cub3d.h"

static void	move_up(t_map *map)
{
	t_point	next_pos;

	next_pos.x = map->player.pos.x + cos(map->player.angle) * 0.1;
	next_pos.y = map->player.pos.y + sin(map->player.angle) * 0.1;
	if (map->board[(int)(next_pos.y)][(int)(map->player.pos.x)] == 0
		|| map->board[(int)(next_pos.y)][(int)(map->player.pos.x)] == 3)
		map->player.pos.y = next_pos.y;
	if (map->board[(int)(map->player.pos.y)][(int)(next_pos.x)] == 0
		|| map->board[(int)(map->player.pos.y)][(int)(next_pos.x)] == 3)
		map->player.pos.x = next_pos.x;
}

static void	move_down(t_map *map)
{
	t_point	next_pos;

	next_pos.x = map->player.pos.x - cos(map->player.angle) * 0.1;
	next_pos.y = map->player.pos.y - sin(map->player.angle) * 0.1;
	if (map->board[(int)next_pos.y][(int)map->player.pos.x] == 0
		|| map->board[(int)(next_pos.y)][(int)(map->player.pos.x)] == 3)
		map->player.pos.y = next_pos.y;
	if (map->board[(int)(map->player.pos.y)][(int)(next_pos.x)] == 0
		|| map->board[(int)(map->player.pos.y)][(int)(next_pos.x)] == 3)
		map->player.pos.x = next_pos.x;
}

static void	move_left(t_map *map)
{
	t_point	next_pos;

	next_pos.x = map->player.pos.x + sin(map->player.angle) * 0.1;
	next_pos.y = map->player.pos.y - cos(map->player.angle) * 0.1;
	if (map->board[(int)next_pos.y][(int)map->player.pos.x] == 0
		|| map->board[(int)(next_pos.y)][(int)(map->player.pos.x)] == 3)
		map->player.pos.y = next_pos.y;
	if (map->board[(int)(map->player.pos.y)][(int)(next_pos.x)] == 0
		|| map->board[(int)(map->player.pos.y)][(int)(next_pos.x)] == 3)
		map->player.pos.x = next_pos.x;
}

static void	move_right(t_map *map)
{
	t_point	next_pos;

	next_pos.x = map->player.pos.x - sin(map->player.angle) * 0.1;
	next_pos.y = map->player.pos.y + cos(map->player.angle) * 0.1;
	if (map->board[(int)next_pos.y][(int)map->player.pos.x] == 0
		|| map->board[(int)(next_pos.y)][(int)(map->player.pos.x)] == 3)
		map->player.pos.y = next_pos.y;
	if (map->board[(int)(map->player.pos.y)][(int)(next_pos.x)] == 0
		|| map->board[(int)(map->player.pos.y)][(int)(next_pos.x)] == 3)
		map->player.pos.x = next_pos.x;
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		exit(1);
	if (keycode == 'a')
		move_left(&game->map);
	if (keycode == 'd')
		move_right(&game->map);
	if (keycode == 'w')
		move_up(&game->map);
	if (keycode == 's')
		move_down(&game->map);
	if (keycode == 'e')
		open_door(&game->map);
	if (keycode == XK_Left)
		change_angle(&game->map.player, -PI / 64);
	if (keycode == XK_Right)
		change_angle(&game->map.player, +PI / 64);
	return (0);
}
