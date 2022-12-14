#include "cub3d.h"

int	mouse_move(int x, int y, t_game *game)
{
	static int	clock = 0;
	int			new_x;
	int			new_y;
	int			render;

	if (clock < 2)
	{
		clock++;		
	return (1);
	}
	clock = 0;
	render = 0;
	if (x > RES_WIDTH / 2 + 10)
	{
		render = 1;
		change_angle(&game->map.player, PI / 64);
	}
	else if (x < RES_WIDTH / 2 - 10)
	{
		render = 1;
		change_angle(&game->map.player, -PI / 64);	
	}
	//if (x > game->map.player.last_x + 10)
	//	change_angle(&game->map.player, PI / 32);
	//if (x < game->map.player.last_x - 10)
	//	change_angle(&game->map.player, -PI / 32);
	//if (x < 50 || x > RES_WIDTH - 50)
	//	mlx_mouse_move(game->window.mlx, game->window.win, RES_WIDTH / 2, y);
	if (y < 200 || y > RES_HEIGHT - 200)
		mlx_mouse_move(game->window.mlx, game->window.win, x, RES_HEIGHT / 2);
	mlx_mouse_get_pos(game->window.mlx, game->window.win, &new_x, &new_y);
	//if (x > game->map.player.last_x + 10 || x < game->map.player. last_x - 10)
	if (render)
	{
		mlx_mouse_move(game->window.mlx, game->window.win, RES_WIDTH / 2, y);
	//	raycasting(&game->map, &game->window, &game->textures);
	//	draw_minimap(&game->window, &game->map);
	}
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
		map->board[(int)pointing.y][(int)(pointing.x)] = 0;
}
