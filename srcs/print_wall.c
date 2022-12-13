/*#include "cub3d.h"

int	wall_cmp(int find_wall_x, int find_wall_y, double distance_x, double distance_y, t_wall next_wall)
{
	if (find_wall_x == 1)
	{	
		//printf("0 : wall_h : y:%f, x:%f\n", next_wall.v_y, next_wall.v_x);
		return (distance_y);
	}
	if (find_wall_y == 1)
	{
		//printf(" 1 : wall_v : y:%f, x:%f\n", next_wall.h_y, next_wall.h_x);
		return (distance_x);
	}
	if (distance_x < distance_y)
	{
		printf(" 2 : wall_h : y:%f, x:%f\n", next_wall.h_y, next_wall.h_x);
		return (distance_x);
	}
	//printf(" 3 : wall_h : y:%f, x:%f\n", next_wall.h_y, next_wall.h_x);
	//printf(" 3 : wall_v : y:%f, x:%f\n", next_wall.v_y, next_wall.v_x);
	return (distance_y);
}
void	print_wall(t_wall next_wall, int find_wall_y, int find_wall_x, t_map *map, double ray, int i,t_window *window)
{

	double distance_final;
	double distance_projection;
	int	y;
	int	k;
	double	distance1;
	double	distance2;
	int	hauteur_final;
	
	//hauteur1 = -1;
	//hauteur2 = -1;
	(void)ray;
	distance1 = -1;
	distance2 = -1;
	y = RES_HEIGHT / 2;
	distance_projection = (RES_WIDTH/2)*0.5;
	if (find_wall_x == 0)
	{
		//printf("find_wall_x : next_wall.h_x : %f next_wall.h_y : %f\n", next_wall.h_x, next_wall.h_y);
		int i = 0;
		i = i;
		distance2 = sqrt(pow((map->player.pos.x * 64) - (next_wall.h_x * 64), 2) + pow((map->player.pos.y * 64) - (next_wall.h_y * 64), 2));
		if (distance2< 0)
			distance2 = -distance2; 
		distance2 = distance2 * cos(ray);
		//printf("h_y : %f, h_x : %f, distance : %f\n", next_wall.h_y, next_wall.h_x, distance2);
		//hauteur1 = (64/distance * distance_projection)/2;
	}
	if (find_wall_y == 0)
	{
	//	printf("find_wall_y : next_wall.v_x : %f next_wall.v_y : %f\n", next_wall.v_x, next_wall.v_y);
		distance1 = sqrt(pow((map->player.pos.x * 64) - (next_wall.v_x * 64), 2) + pow((map->player.pos.y * 64) - (next_wall.v_y * 64), 2));
		if (distance1 < 0)
			distance1 = -distance1; 
		distance1 = distance1 * cos(ray);
		//printf("v_y : %f, v_x : %f, distance : %f\n", next_wall.v_y, next_wall.v_x, distance1);
		//hauteur = (64/distance * distance_projection)/2;
	}
	distance_final = wall_cmp(find_wall_x, find_wall_y, distance2, distance1, next_wall);
	if (distance_final == -1)
		return ;
	hauteur_final = (64/distance_final * distance_projection)/2;
	//printf("distance : %d\n", hauteur_final);
	//hauteur_final = wall_cmp(hauteur1, hauteur2);
	k = 0;
	while (k != hauteur_final && hauteur_final < RES_WIDTH && hauteur_final > 0)
	{
		mlx_pixel_put(window->mlx, window->win, i, y--, MMAP_WCOLOR);
		k++;
	}
	y = RES_HEIGHT / 2;
	//printf("y : %d\n", y); 
	while (hauteur_final >= 0)
	{
		mlx_pixel_put(window->mlx, window->win, i, y++, MMAP_WCOLOR);
		hauteur_final--;
	}
	return ;

}*/
