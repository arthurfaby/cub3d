#include "cub3d.h"

void	print_ray(double distance, t_window *window, int i)
{
	int	hauteur;
	int	k;
	int	y;
	
	if (distance == -1)
		return ;
	hauteur = (64/distance * (RES_WIDTH/2)*0.5) / 2;
	k = 0;
	y = RES_HEIGHT/2;
	while (k != hauteur)
	{
		mlx_pixel_put(window->mlx, window->win, i, y--, MMAP_WCOLOR);
		k++;
	}
	y = RES_HEIGHT/2;
	while (k > 0)
	{
		mlx_pixel_put(window->mlx, window->win, i, y++, MMAP_WCOLOR);
		k--;
	}
}	

void	raycasting(t_map *map, t_window *window)
{
	double	inc;
	double	ray;
	double	distance;
	t_wall	next_wall;
	t_point	center;
	t_point	end;
	int		i;
	
	center.x = 157.5;
	center.y = 157.5;
	inc = (double)FOV / (double)RES_WIDTH;
	ray  = map->player.angle - FOV / 2.0;
	i = 0;
	while (ray <= map->player.angle + (double)FOV / 2.0)
	{
		if (ray >= PI && ray < 3.0 * PI / 2.0)
			distance = ray_no(&next_wall, map, ray);
		else if (ray < 0 || (ray > 3.0 * PI / 2.0 && ray < 2 * PI))
			distance = ray_ne(&next_wall, map, ray);
		if (ray > 0.0 && ray < 1.5708) 
			distance = ray_se(&next_wall, map, ray);
		else if(ray > 1.5708 && ray < 3.14159)
			distance = ray_so(&next_wall, map, ray);
		ray = ray + inc;
		end.x = distance / 2 * sin(ray) + center.x;
		end.y = distance / 2 * cos(ray) + center.y;
		draw_line(window, &center, &end, 0xFF00FF);	
		print_ray(distance, window, i++);	
	}	
}
