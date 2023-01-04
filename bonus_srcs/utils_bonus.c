/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:11:21 by afaby             #+#    #+#             */
/*   Updated: 2023/01/04 16:11:22 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_wall_in_map(t_map *map, t_wall *next_wall)
{
	int	nwx;
	int	nwy;

	nwx = (int)next_wall->x / 64;
	nwy = (int)next_wall->y / 64;
	if (nwx < 0)
		return (0);
	if (nwy < 0)
		return (0);
	if (nwx >= map->width)
		return (0);
	if (nwy >= map->height)
		return (0);
	return (1);
}

void	change_angle(t_player *player, double speed)
{
	player->angle += speed;
	if (player->angle >= 2 * PI)
		player->angle -= 2 * PI;
	else if (player->angle < 0)
		player->angle += 2 * PI;
}
