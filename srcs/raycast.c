#include "cub3d.h"

int		wall_vert_so(t_wall *next_wall, t_map *map, double	ray)
{
	double	inc_x;
	double	inc_y;

	inc_x = 64.0;
	inc_y = 64.0 * tan(ray);
	next_wall->x = (int)map->player.pos.x * 64.0 + 64.0;
	next_wall->y = (map->player.pos.y * 64.0 + (map->player.pos.x * 64 - next_wall->x) * tan(-ray));
	while (next_wall->x <= RES_WIDTH && next_wall->y <= RES_HEIGHT)
	{
		if (map->board[(int)next_wall->y/64][(int)next_wall->x/64] == 1)
		{
			printf("next wall [%f][%f]\n", next_wall->y, next_wall->x);
			return (1);
		}
		next_wall->x = next_wall->x + inc_x;
		next_wall->y = next_wall->y + inc_y;
	}
	return (0);
}

void	ray_so(t_wall *next_wall, t_map *map, double ray)
{
//	int	find_wall_ver;
//	int	find_wall_hor;
	
	wall_vert_so(next_wall, map, ray);
}

void	raycasting(t_map *map, t_window *window)
{
	double	inc;
	double	ray;
	t_wall	next_wall;
	
	(void)window;
	inc = (double)FOV / (double)RES_WIDTH;
	ray  = map->player.angle - FOV / 2.0;
	while (ray <= map->player.angle + (double)FOV / 2.0)
	{
		printf("ray : %f\n", ray);
		if (ray > 0.0 && ray < 1.5708) 
			ray_so(&next_wall, map, ray);
		ray = ray + inc;
	}	
}
