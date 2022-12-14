#include "cub3d.h"

static int	render(t_game *game)
{
	raycasting(&game->map, &game->window, &game->textures);
	draw_minimap(&game->window, &game->map);
	return (1);
}

static int	quit(t_game *game)
{
	// free all
	(void)game;
	exit(0);
	return (0);
}

int	launch_game(char *argv[])
{
	t_game	game;

	if (error(argv[1], &game.map) == 1)
		return (1);
	init_window(&game.window);
	if (parse_all(argv[1], &game) == -1)
		return (2);
	mlx_hook(game.window.win, DestroyNotify, StructureNotifyMask, &quit, &game);
	mlx_hook(game.window.win, KeyPress, KeyPressMask, &key_hook, &game);
	mlx_hook(game.window.win, MotionNotify, PointerMotionMask,
		mouse_move, &game);
	mlx_mouse_move(game.window.mlx, game.window.win,
		RES_WIDTH / 2, RES_HEIGHT / 2);
	mlx_mouse_hide(game.window.mlx, game.window.win);
	mlx_loop_hook(game.window.mlx, render, &game);
	mlx_loop(game.window.mlx);
	return (0);
}
