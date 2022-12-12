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
	t_wall	next_wall;
	double	distance;
	int		i;
	
	(void)window;
	inc = (double)FOV / (double)RES_WIDTH;
	ray  = map->player.angle - FOV / 2.0;
	i = 0;
	while (ray <= map->player.angle + (double)FOV / 2.0)
	{
		printf("ray : %f\n", ray);
		if (ray > 0.0 && ray < 1.5708) 
			distance = ray_se(&next_wall, map, ray);
		else if(ray > 1.5708 && ray < 3.14159)
			distance = ray_so(&next_wall, map, ray);
		print_ray(distance, window, i++);	
		ray = ray + inc;
	}	
}
