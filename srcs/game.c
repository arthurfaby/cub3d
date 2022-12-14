/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:18 by afaby             #+#    #+#             */
/*   Updated: 2023/01/04 16:16:20 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(t_game *game)
{
	raycasting(game);
	return (1);
}

void	destroy_textures(void *mlx, t_textures textures)
{
	mlx_destroy_image(mlx, textures.north.texture);
	mlx_destroy_image(mlx, textures.west.texture);
	mlx_destroy_image(mlx, textures.east.texture);
	mlx_destroy_image(mlx, textures.south.texture);
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
	mlx_loop_hook(game.window.mlx, render, &game);
	mlx_loop(game.window.mlx);
	return (0);
}
