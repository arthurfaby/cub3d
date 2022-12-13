#include "cub3d.h"

void	print_ray(double ray, double distance, t_wall *next_wall, t_window *window, int i)
{
	int	height;
	int	k;
	int	y;
	int	cpt;
	(void)next_wall;
	
	if (distance == -1)
		return ;
	height = (64/(distance * cos(ray)) * (RES_WIDTH/2));
	if (height < 0 || height > RES_HEIGHT)
		height = RES_HEIGHT;
	k = 0;
	y = RES_HEIGHT/2;
	cpt = RES_HEIGHT;
	while (cpt != height)
		img_pixel_put(window, cpt--, i, 0x00FF00);
	while (k != height)
	{
		img_pixel_put(window, y--, i, 0xFF0000);
		k++;
	}
	while (y >= 0)
		img_pixel_put(window, y--, i, 0x0000FF);
	y = RES_HEIGHT/2;
	while (k > 0)
	{
		img_pixel_put(window, y++, i, 0xFF0000);
		k--;
	}
}	

void	raycasting(t_map *map, t_window *window)
{
	double	inc;
	double	ray;
	double	distance;
	t_wall	next_wall;
	int		i;
	
	inc = (double)FOV / (double)RES_WIDTH;
	ray  = map->player.angle - FOV / 2.0;
	i = 0;
	distance = -1;
	while (ray <= map->player.angle + (double)FOV / 2.0)
	{
		if (ray >= PI && ray < 3.0 * PI / 2.0)
			distance = ray_no(&next_wall, map, ray);
		else if (ray < 0 || (ray > 3.0 * PI / 2.0 && ray < 2 * PI))
			distance = ray_ne(&next_wall, map, ray);
		if (ray > 2 * PI || (ray >= 0.0 && ray < 1.5708)) 
			distance = ray_se(&next_wall, map, ray);
		else if(ray > 1.5708 && ray < 3.14159)
			distance = ray_so(&next_wall, map, ray);
		ray = ray + inc;
		print_ray(ray - map->player.angle, distance, &next_wall, window, i++);	
	}	
}
