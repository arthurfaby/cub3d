#include "cub3d.h"

void	raycasting(t_map *map, t_window *window)
{
	double	inc;
	double	ray;
	double	distance;
	t_wall	next_wall;
	int		index;

	index = 0;
	inc = (double)FOV / (double)RES_WIDTH;
	ray  = map->player.angle - FOV / 2.0;
	while (ray <= map->player.angle + (double)FOV / 2.0)
	{
		if (ray >= PI && ray < 3.0 * PI / 2.0)
			distance = ray_no(&next_wall, map, ray);
		else if (ray < 0 || (ray > 3.0 * PI / 2.0 && ray < 2 * PI))
			distance = ray_ne(&next_wall, map, ray);
		ray = ray + inc;
		print_ray(window, distance, index);
		index++;
	}	
}
