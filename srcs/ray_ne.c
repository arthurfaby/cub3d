#include "cub3d.h"

static double	wall_vert_ne(t_wall *next_wall, t_wall *wall_hori, t_map *map, double ray)
{
	double	inc_x;
	double	inc_y;
	double	distance;

	(void)wall_hori;
	inc_x = 64.0;
	inc_y = 64.0 * tan(-ray);	
	next_wall->x = (int)map->player.pos.x * 64.0 + 64.0;
	next_wall->y = (map->player.pos.y * 64.0 + (map->player.pos.x * 64 - next_wall->x) * tan(-ray));
	while (check_wall_in_map(map, next_wall))
	{
		if (map->board[(int)next_wall->y/64][(int)next_wall->x/64] != 0
			&& map->board[(int)next_wall->y/64][(int)next_wall->x/64] != 3)
		{
			distance = sqrt(pow((map->player.pos.x * 64.0) - (next_wall->x), 2) + pow((map->player.pos.y * 64.0) - next_wall->y, 2));
			if (distance < 0)
				distance = -distance;
			return (distance);
		}
			next_wall->y = next_wall->y - inc_y;
			next_wall->x = next_wall->x + inc_x;
	}
	return (-1);
}

static double	wall_hori_ne(t_wall *next_wall, t_wall wall_vert, t_map *map, double ray)
{
	double	inc_x;
	double	inc_y;
	double	distance;

	(void) wall_vert;
	inc_y = 64.0;
	inc_x = 64.0 / tan(-ray);	
	next_wall->y = (int)map->player.pos.y * 64.0 - 0.0000001;
	next_wall->x = (map->player.pos.x * 64.0 + (map->player.pos.y * 64.0 - next_wall->y) / tan(-ray));
	while (check_wall_in_map(map, next_wall))
	{
		if (map->board[(int)next_wall->y/64][(int)next_wall->x/64] != 0
			&& map->board[(int)next_wall->y/64][(int)next_wall->x/64] != 3)
		{
			distance = sqrt(pow((map->player.pos.x * 64.0) - (int)(next_wall->x), 2) + pow((map->player.pos.y * 64.0) - (next_wall->y), 2));
			if (distance < 0)
				distance = -distance;
			return (distance);
		}
		next_wall->x = next_wall->x + inc_x;
		next_wall->y = next_wall->y - inc_y;
	}
	return (-1);
}

double	ray_ne(t_wall *next_wall, t_map *map, double ray)
{
	double	distance_vert;
	double	distance_hori;
	t_wall	temp_wall;

	distance_vert = wall_vert_ne(&temp_wall, next_wall, map, ray);
	distance_hori = wall_hori_ne(next_wall, temp_wall, map, ray);
	if (distance_vert == -1)
	{
		next_wall->side = HORIZONTAL;
		next_wall->face = SOUTH;
		return (distance_hori);
	}
	else if (distance_hori == -1 || distance_vert <= distance_hori)
	{
		next_wall->side = VERTICAL;
		next_wall->face = WEST;
		next_wall->x = temp_wall.x;
		next_wall->y = temp_wall.y;
		return (distance_vert);
	}
	next_wall->side = HORIZONTAL;
	next_wall->face = SOUTH;
	return (distance_hori);
}
