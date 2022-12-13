#include "cub3d.h"

int	launch_game(char *argv[])
{
	t_game	game;

	if (error(argv[1], &game.map) == 1)
		return (1);
	init_window(&game.window);
	if (parse_all(argv[1], &game) == -1)
		return (2);
	raycasting(&game.map, &game.window);
	draw_minimap(&game.window, &game.map);
	mlx_hook(game.window.win, KeyPress, KeyPressMask, &key_hook, &game);
	mlx_hook(game.window.win, MotionNotify, PointerMotionMask,
		mouse_move, &game);
	mlx_mouse_move(game.window.mlx, game.window.win,
		RES_WIDTH / 2, RES_HEIGHT / 2);
	mlx_mouse_hide(game.window.mlx, game.window.win);
	mlx_loop(game.window.mlx);
	return (0);
}
