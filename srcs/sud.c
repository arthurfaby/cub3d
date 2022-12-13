#include "cub3d.h"

double	wall_vert_se(t_wall *next_wall, t_map *map, double	ray)
{
	double	inc_x;
	double	inc_y;
	double	distance;

	inc_x = 64.0;
	inc_y = 64.0 * tan(ray);
	next_wall->x = (int)map->player.pos.x * 64.0 + 64.0;
	next_wall->y = (map->player.pos.y * 64.0 + (map->player.pos.x * 64 - next_wall->x) * tan(-ray));
	while (check_wall_in_map(map, next_wall))
	{
		if (map->board[(int)next_wall->y/64][(int)next_wall->x/64] != 0)
		{
			distance = sqrt(pow((map->player.pos.x * 64.0) - next_wall->x, 2) + pow((map->player.pos.y * 64.0) - next_wall->y, 2));
			if (distance < 0)
				distance = -distance;
			return (distance);
		}
		next_wall->x = next_wall->x + inc_x;
		next_wall->y = next_wall->y + inc_y;
	}
	return (-1);
}

double	wall_hori_se(t_wall *next_wall, t_map *map, double	ray)
{
	double	inc_x;
	double	inc_y;
	double	distance;

	inc_x = 64.0 / tan(ray);
	inc_y = 64.0;
	next_wall->y = (int)map->player.pos.y * 64.0 + 64.0;
	next_wall->x = (map->player.pos.x * 64.0 + (map->player.pos.y * 64 - next_wall->y) / tan(-ray));
	while (check_wall_in_map(map, next_wall))
	{
		if (map->board[(int)next_wall->y/64][(int)next_wall->x/64] != 0)
		{
			distance = sqrt(pow((map->player.pos.x * 64.0) - next_wall->x, 2) + pow((map->player.pos.y * 64.0) - next_wall->y, 2));
			if (distance < 0)
				distance = -distance;
			return (distance);
		}
		next_wall->x = next_wall->x + inc_x;
		next_wall->y = next_wall->y + inc_y;
	}
	return (-1);
}

double	ray_se(t_wall *next_wall, t_map *map, double ray)
{
	double	distance_vert;
	double	distance_hori;
	
	distance_vert = wall_vert_se(next_wall, map, ray);
	distance_hori = wall_hori_se(next_wall, map, ray);
	if (distance_vert == -1)
		return (distance_hori);
	if (distance_hori == -1)
		return (distance_vert);
	else if (distance_vert < distance_hori)
		return (distance_vert);
	else
		return (distance_hori);
}

double	wall_vert_so(t_wall *next_wall, t_map *map, double	ray)
{
	double	inc_x;
	double	inc_y;
	double	distance;

	inc_x = 64.0;
	inc_y = 64.0 * tan(-ray);
	next_wall->x = (int)map->player.pos.x * 64.0 - 1.0;
	next_wall->y = (map->player.pos.y * 64.0 + (map->player.pos.x * 64 - next_wall->x) * tan(-ray));
	while (check_wall_in_map(map, next_wall))
	{
		if (map->board[(int)next_wall->y/64][(int)next_wall->x/64] != 0)
		{
			distance = sqrt(pow((map->player.pos.x * 64.0) - next_wall->x, 2) + pow((map->player.pos.y * 64.0) - next_wall->y, 2));
			if (distance < 0)
				distance = -distance;
			return (distance);
		}
		next_wall->x = next_wall->x - inc_x;
		next_wall->y = next_wall->y + inc_y;
	}
	return (-1);
}

double	wall_hori_so(t_wall *next_wall, t_map *map, double	ray)
{
	double	inc_x;
	double	inc_y;
	double	distance;

	inc_x = 64.0 / tan(-ray);
	inc_y = 64.0;
	next_wall->y = (int)map->player.pos.y * 64.0 + 64.0;
	next_wall->x = (map->player.pos.x * 64.0 + (map->player.pos.y * 64 - next_wall->y) / tan(-ray));
	while (check_wall_in_map(map, next_wall))
	{
		if (map->board[(int)next_wall->y/64][(int)next_wall->x/64] != 0)
		{
			distance = sqrt(pow((map->player.pos.x * 64.0) - next_wall->x, 2) + pow((map->player.pos.y * 64.0) - next_wall->y, 2));
			if (distance < 0)
				distance = -distance;
			return (distance);
		}
		next_wall->x = next_wall->x - inc_x;
		next_wall->y = next_wall->y + inc_y;
	}
	return (-1);
}

double	ray_so(t_wall *next_wall, t_map *map, double ray)
{
	double	distance_vert;
	double	distance_hori;
	
	distance_vert = wall_vert_so(next_wall, map, ray);
	distance_hori = wall_hori_so(next_wall, map, ray);
	if (distance_vert == -1)
		return (distance_hori);
	if (distance_hori == -1)
		return (distance_vert);
	else if (distance_vert < distance_hori)
		return (distance_vert);
	else
		return (distance_hori);
}


