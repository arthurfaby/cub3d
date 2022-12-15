#include "cub3d.h"

static int	move_x(int x, t_game *game)
{
	int	reset;

	reset = 0;
	if (x > RES_WIDTH / 2 + 50)
	{
		reset = 1;
		change_angle(&game->map.player, PI / 128);
	}
	else if (x < RES_WIDTH / 2 - 50)
	{
		reset = 1;
		change_angle(&game->map.player, -PI / 128);
	}
	return (reset);
}

static int	move_y(int y, t_game *game)
{
	int	reset;

	reset = 0;
	if (y > RES_HEIGHT / 2 + 20)
	{
		reset = 1;
		if (game->map.player.inclination > -RES_HEIGHT / 2)
			game->map.player.inclination -= 10;
	}
	else if (y < RES_HEIGHT / 2 - 20)
	{
		reset = 1;
		if (game->map.player.inclination < RES_HEIGHT / 2)
			game->map.player.inclination += 10;
	}
	return (reset);
}

int	mouse_move(int x, int y, t_game *game)
{
	int			reset_x;
	int			reset_y;

	reset_x = move_x(x, game);
	reset_y = move_y(y, game);
	if (reset_x)
		mlx_mouse_move(game->window.mlx, game->window.win, RES_WIDTH / 2, y);
	if (reset_y)
		mlx_mouse_move(game->window.mlx, game->window.win, x, RES_HEIGHT / 2);
	return (0);
}

void	open_door(t_map *map)
{
	t_point		pointing;
	t_player	player;

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
		map->board[(int)pointing.y][(int)(pointing.x)] = 3;
	else if (map->board[(int)pointing.y][(int)(pointing.x)] == 3)
		map->board[(int)pointing.y][(int)(pointing.x)] = 2;
}
