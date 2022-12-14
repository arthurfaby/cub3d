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
		if (map->board[(int)next_wall->y/64][(int)next_wall->x/64] != 0)
		{
			printf("wall vert [%f][%f]\n", next_wall->y, next_wall->x);
		//	&& next_wall->x - wall_hori->x > 0 && next_wall->x - wall_hori->x < 1)
			//{
					//next_wall->y = wall_hori->y;
					//next_wall->x = wall_hori->x;
				//return (-1);
			//}
			distance = sqrt(pow((map->player.pos.x * 64) - ((int)next_wall->x), 2) + pow((map->player.pos.y * 64) - ((int)next_wall->y), 2));
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
	next_wall->y = (int)map->player.pos.y * 64.0 - 1.0;
	next_wall->x = (map->player.pos.x * 64.0 + (map->player.pos.y * 64.0 - next_wall->y) / tan(-ray));
	while (check_wall_in_map(map, next_wall))
	{
		if (map->board[(int)next_wall->y/64][(int)next_wall->x/64] != 0)
		{
			if (next_wall->x - wall_vert.x > 0 && next_wall->x - wall_vert.x < 1 )
				return (-1);
			printf("wall hori [%f][%f]\n", next_wall->y, next_wall->x);
			distance = sqrt(pow((map->player.pos.x * 64) - (next_wall->x), 2) + pow((map->player.pos.y * 64) - ((int)next_wall->y + 1), 2));
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
	printf("hori %d\n", (int)distance_hori);
	printf("vert %d\n", (int)distance_vert);
	//printf("vert %f\n", distance_vert);
//	if (next_wall->y - wall_hori->y > 0 && next_wall->y - wall_hori->y < 1 )
	if (distance_vert == -1)
	{
		next_wall->side = HORIZONTAL;
		next_wall->face = SOUTH;
		printf("hori %f\n", distance_hori);
		return (distance_hori);
	}
	if (next_wall->y - temp_wall.y > 0 && next_wall->y - temp_wall.y < 1 )
		distance_vert = -1;
	else if (distance_hori == -1 || (int)distance_vert <= (int)distance_hori)
	{
		next_wall->side = VERTICAL;
		next_wall->face = WEST;
		next_wall->x = temp_wall.x;
		next_wall->y = temp_wall.y;
		printf("vert %f\n", distance_vert);
		return (distance_vert);
	}
	next_wall->side = HORIZONTAL;
	next_wall->face = SOUTH;
	printf("hori %f\n", distance_hori);
	return (distance_hori);
}
