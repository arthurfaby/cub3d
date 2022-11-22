#include "cub3d.h"

void	launch_game(char *argv[])
{
	t_game	game;
	//t_map		map;
	//t_window	window;
	(void)argv;

	{ // init_map(&map)
		game.map.width = 13;
		game.map.height = 10;
		game.map.board[0][0] = 1; // 1111111111111
		game.map.board[0][1] = 1; // 1010000111111
		game.map.board[0][2] = 1; // 1000000000001
		game.map.board[0][3] = 1; // 1001011111101 
		game.map.board[0][4] = 1; // 1001110000101
		game.map.board[0][5] = 1; // 1000100110101
		game.map.board[0][6] = 1; // 1010100000101
		game.map.board[0][7] = 1; // 1010100110001
		game.map.board[0][8] = 1; // 1011100110001
		game.map.board[0][9] = 1; // 1111111111111
		game.map.board[0][10] = 1;
		game.map.board[0][11] = 1;
		game.map.board[0][11] = 1;
		game.map.board[0][12] = 1;
		game.map.board[1][0] = 1;
		game.map.board[1][1] = 0;
		game.map.board[1][2] = 1;
		game.map.board[1][3] = 0;
		game.map.board[1][4] = 0;
		game.map.board[1][5] = 0;
		game.map.board[1][6] = 0;
		game.map.board[1][7] = 1;
		game.map.board[1][8] = 1;
		game.map.board[1][9] = 1;
		game.map.board[1][10] = 1;
		game.map.board[1][11] = 1;
		game.map.board[1][12] = 1;
		game.map.board[2][0] = 1;
		game.map.board[2][1] = 0;
		game.map.board[2][2] = 0;
		game.map.board[2][3] = 0;
		game.map.board[2][4] = 0;
		game.map.board[2][5] = 0;
		game.map.board[2][6] = 0;
		game.map.board[2][7] = 0;
		game.map.board[2][8] = 0;
		game.map.board[2][9] = 0;
		game.map.board[2][10] = 0;
		game.map.board[2][11] = 0;
		game.map.board[2][12] = 1;
		game.map.board[3][0] = 1;
		game.map.board[3][1] = 0;
		game.map.board[3][2] = 0;
		game.map.board[3][3] = 1;
		game.map.board[3][4] = 0;
		game.map.board[3][5] = 1;
		game.map.board[3][6] = 1;
		game.map.board[3][7] = 1;
		game.map.board[3][8] = 1;
		game.map.board[3][9] = 1;
		game.map.board[3][10] = 1;
		game.map.board[3][11] = 0;
		game.map.board[3][12] = 1;
		game.map.board[4][0] = 1;
		game.map.board[4][1] = 0;
		game.map.board[4][2] = 0;
		game.map.board[4][3] = 1;
		game.map.board[4][4] = 1;
		game.map.board[4][5] = 1;
		game.map.board[4][6] = 0;
		game.map.board[4][7] = 0;
		game.map.board[4][8] = 0;
		game.map.board[4][9] = 0;
		game.map.board[4][10] = 1;
		game.map.board[4][11] = 0;
		game.map.board[4][12] = 1;
		game.map.board[5][0] = 1;
		game.map.board[5][1] = 0;
		game.map.board[5][2] = 0;
		game.map.board[5][3] = 0;
		game.map.board[5][4] = 1;
		game.map.board[5][5] = 0;
		game.map.board[5][6] = 0;
		game.map.board[5][7] = 1;
		game.map.board[5][8] = 1;
		game.map.board[5][9] = 0;
		game.map.board[5][10] = 1;
		game.map.board[5][11] = 0;
		game.map.board[5][12] = 1;
		game.map.board[6][0] = 1;
		game.map.board[6][1] = 0;
		game.map.board[6][2] = 1;
		game.map.board[6][3] = 0;
		game.map.board[6][4] = 1;
		game.map.board[6][5] = 0;
		game.map.board[6][6] = 0;
		game.map.board[6][7] = 0;
		game.map.board[6][8] = 0;
		game.map.board[6][9] = 0;
		game.map.board[6][10] = 1;
		game.map.board[6][11] = 0;
		game.map.board[6][12] = 1;
		game.map.board[7][0] = 1;
		game.map.board[7][1] = 0;
		game.map.board[7][2] = 1;
		game.map.board[7][3] = 0;
		game.map.board[7][4] = 1;
		game.map.board[7][5] = 0;
		game.map.board[7][6] = 0;
		game.map.board[7][7] = 1;
		game.map.board[7][8] = 1;
		game.map.board[7][9] = 0;
		game.map.board[7][10] = 0;
		game.map.board[7][11] = 0;
		game.map.board[7][12] = 1;
		game.map.board[8][0] = 1;
		game.map.board[8][1] = 0;
		game.map.board[8][2] = 1;
		game.map.board[8][3] = 1;
		game.map.board[8][4] = 1;
		game.map.board[8][5] = 0;
		game.map.board[8][6] = 0;
		game.map.board[8][7] = 1;
		game.map.board[8][8] = 1;
		game.map.board[8][9] = 0;
		game.map.board[8][10] = 0;
		game.map.board[8][11] = 0;
		game.map.board[8][12] = 1;
		game.map.board[9][0] = 1;
		game.map.board[9][1] = 1;
		game.map.board[9][2] = 1;
		game.map.board[9][3] = 1;
		game.map.board[9][4] = 1;
		game.map.board[9][5] = 1;
		game.map.board[9][6] = 1;
		game.map.board[9][7] = 1;
		game.map.board[9][8] = 1;
		game.map.board[9][9] = 1;
		game.map.board[9][10] = 1;
		game.map.board[9][11] = 1;
		game.map.board[9][12] = 1;

		game.map.player.pos.x = 1.5;
		game.map.player.pos.y = 1.5;
		game.map.player.angle = 0.0;
		game.map.mmap_width = 9.0;
	}
	
	init_window(&game.window);
	draw_minimap(&game.window, &game.map);
	mlx_hook(game.window.win, KeyPress, KeyPressMask, &key_hook, &game);
  	mlx_mouse_hook(game.window.win, mouse_hook, &game);
	mlx_loop(game.window.mlx);
}

