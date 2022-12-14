/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:23 by afaby             #+#    #+#             */
/*   Updated: 2023/01/04 16:27:55 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_up(t_map *map)
{
	t_point	next_pos;
	t_point	check_col;

	next_pos.x = map->player.pos.x + cos(map->player.angle) * 0.1;
	next_pos.y = map->player.pos.y + sin(map->player.angle) * 0.1;
	check_col.x = map->player.pos.x + cos(map->player.angle) * 0.3;
	check_col.y = map->player.pos.y + sin(map->player.angle) * 0.3;
	if (map->board[(int)(check_col.y)][(int)(map->player.pos.x)] == 0)
		map->player.pos.y = next_pos.y;
	if (map->board[(int)(map->player.pos.y)][(int)(check_col.x)] == 0)
		map->player.pos.x = next_pos.x;
}

static void	move_down(t_map *map)
{
	t_point	next_pos;
	t_point	check_col;

	next_pos.x = map->player.pos.x - cos(map->player.angle) * 0.1;
	next_pos.y = map->player.pos.y - sin(map->player.angle) * 0.1;
	check_col.x = map->player.pos.x - cos(map->player.angle) * 0.3;
	check_col.y = map->player.pos.y - sin(map->player.angle) * 0.3;
	if (map->board[(int)(check_col.y)][(int)(map->player.pos.x)] == 0)
		map->player.pos.y = next_pos.y;
	if (map->board[(int)(map->player.pos.y)][(int)(check_col.x)] == 0)
		map->player.pos.x = next_pos.x;
}

static void	move_left(t_map *map)
{
	t_point	next_pos;
	t_point	check_col;

	next_pos.x = map->player.pos.x + sin(map->player.angle) * 0.1;
	next_pos.y = map->player.pos.y - cos(map->player.angle) * 0.1;
	check_col.x = map->player.pos.x + sin(map->player.angle) * 0.3;
	check_col.y = map->player.pos.y - cos(map->player.angle) * 0.3;
	if (map->board[(int)(check_col.y)][(int)(map->player.pos.x)] == 0)
		map->player.pos.y = next_pos.y;
	if (map->board[(int)(map->player.pos.y)][(int)(check_col.x)] == 0
		|| map->board[(int)(map->player.pos.y)][(int)(check_col.x)] == 3)
		map->player.pos.x = next_pos.x;
}

static void	move_right(t_map *map)
{
	t_point	next_pos;
	t_point	check_col;

	next_pos.x = map->player.pos.x - sin(map->player.angle) * 0.1;
	next_pos.y = map->player.pos.y + cos(map->player.angle) * 0.1;
	check_col.x = map->player.pos.x - sin(map->player.angle) * 0.3;
	check_col.y = map->player.pos.y + cos(map->player.angle) * 0.3;
	if (map->board[(int)(check_col.y)][(int)(map->player.pos.x)] == 0)
		map->player.pos.y = next_pos.y;
	if (map->board[(int)(map->player.pos.y)][(int)(check_col.x)] == 0)
		map->player.pos.x = next_pos.x;
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		quit(game);
	if (keycode == 'a')
		move_left(&game->map);
	if (keycode == 'd')
		move_right(&game->map);
	if (keycode == 'w')
		move_up(&game->map);
	if (keycode == 's')
		move_down(&game->map);
	if (keycode == XK_Left)
		change_angle(&game->map.player, -PI / 64);
	if (keycode == XK_Right)
		change_angle(&game->map.player, +PI / 64);
	return (0);
}
