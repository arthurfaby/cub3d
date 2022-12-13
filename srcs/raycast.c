#include "cub3d.h"

static int	choose_wall_color(int y, int height, t_textures *textures, t_wall *next_wall)
{
	(void)textures;
	(void)next_wall;
	(void)height;
	t_texture	txt;
	int			color;
	double		ratio;
	int			col;
	(void)col;

	if (next_wall->face == EAST)
		txt = textures->east;
	else if (next_wall->face == WEST)
		txt = textures->west;
	else if (next_wall->face == NORTH)
		txt = textures->north;
	else
		txt = textures->south;
	ratio = txt.height / height;
	if (next_wall->side == HORIZONTAL)
	{
		col = (next_wall->x - (int)next_wall->x) * txt.width;
	//	printf("x : %f, %f, %d\n", next_wall->x, (next_wall->x - (int)next_wall->x), txt.width);
	}
	else
	{
		col = (next_wall->y - (int)next_wall->y) * txt.width;
	//	printf("y : %f, %f, %d\n", next_wall->y, (next_wall->y - (int)next_wall->y), txt.width);
	}
	color = get_color_in_image(&txt, y * ratio, col);
	return (color);
}

void	print_ray(double ray, t_wall *next_wall, t_window *window, int i, t_textures *textures)
{
	int	y;
	int	height;
	int	start_wall;
	int	end_wall;
	int	color;
	double	distance;
	(void)textures;
	(void)next_wall;

	y = 0;
	distance = next_wall->distance;
	height = (64 / (distance * cos(ray)) * (RES_WIDTH / 2));	
	start_wall = RES_HEIGHT / 2 - height / 2;
	end_wall = RES_HEIGHT / 2 + height / 2;
	while (y < RES_HEIGHT)
	{
		if (y < start_wall) // CEILING
			color = 0x0000FF;
		else if (y > end_wall) // FLOOR
			color = 0x00FF00;
		else // WALL
			color = choose_wall_color(y - start_wall, height, textures, next_wall);
		img_pixel_put(window, y, i, color);
		y++;
	}
}


void	raycasting(t_map *map, t_window *window, t_textures *textures)
{
	double	inc;
	double	ray;
	//double	distance;
	t_wall	next_wall;
	int		i;
	
	inc = (double)FOV / (double)RES_WIDTH;
	ray = map->player.angle - FOV / 2.0;
	i = 0;
//	distance = -1;
	while (ray <= map->player.angle + (double)FOV / 2.0)
	{
		if (ray >= PI && ray < 3.0 * PI / 2.0)
			next_wall.distance = ray_no(&next_wall, map, ray);
		else if (ray < 0 || (ray > 3.0 * PI / 2.0 && ray < 2 * PI))
			next_wall.distance = ray_ne(&next_wall, map, ray);
		else if (ray > 2 * PI || (ray >= 0.0 && ray < 1.5708)) 
			next_wall.distance = ray_se(&next_wall, map, ray);
		else if(ray > 1.5708 && ray < 3.14159)
			next_wall.distance = ray_so(&next_wall, map, ray);
		ray = ray + inc;
		print_ray(ray - map->player.angle, &next_wall, window, i++, textures);	
	}	
}
