#include "cub3d.h"

double	inc_y(double ray, double inter, double inc)
{
	if (ray < PI && ray > 0)
		return (inter += inc);
	else
		return (inter -= inc);
}

double	inc_x(double ray, double inter, double inc)
{
	if (ray < PI / 2 && ray > -(PI / 2))
		return (inter -= inc);
	else
		return (inter += inc);
}

int	ray_up(t_wall *next_wall, t_map *map, double ray)
{
	double	ya;
	double	xa;
	double	inter_y;
	double	inter_x;

	//ray = -ray;
	ya = 64.0;
	xa = 64.0 / tan(ray);
	inter_y = (int)(map->player.pos.y) * 64.0 - 1.0;
	inter_x = map->player.pos.x * 64.0 + (map->player.pos.y * 64.0 - inter_y) / tan(ray); 
	next_wall->h_y = inter_y/64.0;
	next_wall->h_x = inter_x/64.0;
//	printf("xa : %f\n", xa/64);
//	printf("ray up first -> x : %d, y : %d, ray : %f\n",(int)next_wall->h_x , (int)next_wall->h_y, ray);
	while (next_wall->h_y < map->height && next_wall->h_x < map->width) 
	{
//	 	printf("ray up touched -> x : %d, y : %d, ray : %f\n",(int)next_wall->h_x , (int)next_wall->h_y, ray);
		if (next_wall->h_y >= 0 && next_wall->h_x >= 0 
				&& map->board[(int)next_wall->h_y][(int)next_wall->h_x] == 1)
		{
			//printf("ray up touched -> x : %f, y : %f, ray : %f\n",next_wall->h_x , next_wall->h_y, ray);
			return (0);
		}
	//	next_wall->h_x = (inter_x + xa) / 64.0;
	//	next_wall->h_y = (inter_y + ya) / 64.0;
		inter_y += ya;
		inter_x += xa;
		//inter_x = inc_x(ray, inter_x, xa);
		next_wall->h_y = inter_y/64.0;
		next_wall->h_x = inter_x/64.0;
	}
	return (1);
}

int	ray_right(t_wall *next_wall, t_map *map, double ray)
{
		double	ya;
		double	xa;
		double	inter_x;
		double	inter_y;
		
		ya = 64.0 * tan(ray);
		xa = 64.0;
		inter_x = (int)map->player.pos.x * 64.0 + 64.0;
		inter_y = (map->player.pos.y * 64.0) + (map->player.pos.x * 64.0 - inter_x) * tan(ray);
		next_wall->v_x = inter_x/64.0;
		next_wall->v_y = inter_y/64.0;
		printf("ray right first -> x : %d, y : %d, ray : %f\n",(int)next_wall->v_x , (int)next_wall->v_y, ray);
		while(next_wall->v_y < map->height && next_wall->v_x < map->width)
		{
			printf("ray right touched -> x : %d, y : %d, ray : %f\n",(int)next_wall->v_x , (int)next_wall->v_y, ray);
			if(next_wall->v_y >= 0 && next_wall->v_x >= 0 
				&& map->board[(int)next_wall->v_y][(int)next_wall->v_x])
				return (0);
			inter_x += xa;
			inter_y = inc_y(ray, inter_y, ya);
			next_wall->v_y = inter_y/64.0;
			next_wall->v_x = inter_x/64.0;
		}	
		return (1);
}

int	ray_left(t_wall *next_wall, t_map *map, double ray)
{
		double	ya;
		double	xa;
		double	inter_x;
		double	inter_y;
		
		ya = 64.0 * tan(ray);
		xa = 64.0;
		inter_x = (int)map->player.pos.x * 64.0 - 1.0;
		inter_y = (map->player.pos.y * 64.0) + (map->player.pos.x * 64.0 - inter_x) * tan(ray);
		next_wall->v_x = inter_x/64.0;
		next_wall->v_y = inter_y/64.0;
		while((int)(inter_x/64.0) < map->height && (int)(inter_y/64.0) < map->width)
		{
			if(inter_x/64.0 >= 0.0 && inter_y/64.0 >= 0.0 
				&& map->board[(int)(inter_y/64.0)][(int)(inter_x/64.0)])
				return (0);
			inter_x -= xa;
			inter_y = inc_y(ray, inter_y, ya);
			next_wall->v_y = inter_y/64.0;
			next_wall->v_x = inter_x/64.0;
		}	
		return (1);
}

int	ray_down(t_wall *next_wall, t_map *map, double ray)
{
	double	ya;
	double	xa;
	double	inter_y;
	double	inter_x;

	//ray = 2 * PI - ray;
	ya = 64.0;
	xa = 64.0 / tan(ray);
	inter_y = (int)(map->player.pos.y) * 64.0 + 64.0;
	inter_x = (map->player.pos.x * 64.0 + (map->player.pos.y * 64.0 - inter_y) / tan(ray)); 
	next_wall->h_y = inter_y/64.0;
	next_wall->h_x = inter_x/64.0;
//	printf("inter_x : %f\n", next_wall->h_x);
//	printf("xa : %f\n", xa);
	//printf("ray : %f\n", ray);
	//printf("ray down touched start -> x : %f, y : %f, ray : %f\n",next_wall->h_x , next_wall->h_y, ray);
	while (next_wall->h_y < map->height && next_wall->h_x < map->width) 
	{
			//printf("ray down touched -> x : %f, y : %f, ray : %f\n",next_wall->h_x , next_wall->h_y, ray);
		if (next_wall->h_y >= 0 && next_wall->h_x > 0 
			&& map->board[(int)next_wall->h_y][(int)next_wall->h_x] == 1)
		{
			return (0);
		}
		inter_y += ya;
		//inter_x += xa;
		inter_x = inc_x(ray, inter_x, xa);
		next_wall->h_y = inter_y/64.0;
		next_wall->h_x = inter_x/64.0;
	}
	return (1);
}

void	calcule(t_map *map, t_window *window)
{
	double	inc;
	double	ray;
	t_wall	next_wall;
	int		find_wall_x;
	int		find_wall_y;
	int		i;

	inc = (double)FOV / (double)RES_WIDTH;
	ray = map->player.angle - FOV / 2.0;
	i = 0;
	while (ray <= map->player.angle + (double)FOV / 2.0)
	{
		find_wall_x = 1;
		find_wall_y = 1;
		if (ray < 0.0) 
			find_wall_x = ray_up(&next_wall, map, -ray);
		else 
			find_wall_x = ray_down(&next_wall, map, -ray);
		if	(ray < 1.5708 || ray > 4.71239)
			find_wall_y = ray_right(&next_wall, map, -ray);
		else
			find_wall_y = ray_left(&next_wall, map, -ray);
		printf("ray : %f\n", ray);
		//printf("find_wall_y : %d\n", find_wall_y);
		print_wall(next_wall, find_wall_y, find_wall_x, map, ray, i, window);
		i++;
		ray += inc;
	}
}
