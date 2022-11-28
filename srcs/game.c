#include "cub3d.h"

int	launch_game(char *argv[])
{
	t_game	game;

	if (error(argv[1], &game.map) == 1)
		return (1);
	init_window(&game.window);
	if (parse_all(argv[1], &game) == -1)
		return (2);

	printf("info : \n");
	printf("\tpx = %f\n\tpy = %f\n\tpa = %f\n", game.map.player.pos.x, game.map.player.pos.y, game.map.player.angle);

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
