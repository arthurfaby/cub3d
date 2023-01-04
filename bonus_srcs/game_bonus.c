/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:18 by afaby             #+#    #+#             */
/*   Updated: 2023/01/04 16:10:18 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(t_game *game)
{
	static int	i = 0;

	if (i < 5)
		game->textures.south = game->textures.south_1;
	else if (i < 10)
		game->textures.south = game->textures.south_2;
	else if (i < 15)
		game->textures.south = game->textures.south_3;
	else if (i < 20)
		game->textures.south = game->textures.south_4;
	else if (i < 25)
		game->textures.south = game->textures.south_5;
	else
		i = 0;
	i++;
	raycasting(game);
	draw_minimap(game);
	return (1);
}

void	destroy_textures(void *mlx, t_textures textures)
{
	mlx_destroy_image(mlx, textures.north.texture);
	mlx_destroy_image(mlx, textures.west.texture);
	mlx_destroy_image(mlx, textures.east.texture);
	mlx_destroy_image(mlx, textures.south_1.texture);
	mlx_destroy_image(mlx, textures.south_2.texture);
	mlx_destroy_image(mlx, textures.south_3.texture);
	mlx_destroy_image(mlx, textures.south_4.texture);
	mlx_destroy_image(mlx, textures.south_5.texture);
	mlx_destroy_image(mlx, textures.door.texture);
}

int	quit(t_game *game)
{
	free_arr_int(game->map.board, game->map.height);
	destroy_textures(game->window.mlx, game->textures);
	mlx_destroy_image(game->window.mlx, game->window.image->img);
	mlx_destroy_window(game->window.mlx, game->window.win);
	mlx_destroy_display(game->window.mlx);
	free(game->window.mlx);
	free(game->window.image);
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
	mlx_loop_hook(game.window.mlx, render, &game);
	mlx_loop(game.window.mlx);
	return (0);
}
