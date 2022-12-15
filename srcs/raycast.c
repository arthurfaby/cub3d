#include "cub3d.h"

static int	choose_wall_color(int y, int height,
	t_textures *textures, t_wall *next_wall)
{
	t_texture	txt;
	int			color;
	double		ratio;
	int			col;

	if (next_wall->type == DOOR)
		txt = textures->door;
	else if (next_wall->face == EAST)
		txt = textures->east;
	else if (next_wall->face == WEST)
		txt = textures->west;
	else if (next_wall->face == NORTH)
		txt = textures->north;
	else
		txt = textures->south;
	ratio = (double)txt.height / (double)height;
	if (next_wall->side == HORIZONTAL)
		col = (next_wall->x / 64 - (int)next_wall->x / 64) * txt.width;
	else
		col = (next_wall->y / 64 - (int)next_wall->y / 64) * txt.width;
	color = get_color_in_image(&txt, y * ratio, col);
	return (color);
}

void	print_ray(double ray, t_wall *next_wall, int i, t_game *game)
{
	int	y;
	int	height;
	int	start_wall;
	int	end_wall;
	int	color;

	y = 0;
	height = (64 / (next_wall->distance * cos(ray)) * (RES_WIDTH / 2));
	start_wall = RES_HEIGHT / 2 - height / 2 + game->map.player.inclination;
	end_wall = RES_HEIGHT / 2 + height / 2 + game->map.player.inclination;
	while (y < RES_HEIGHT)
	{
		if (y <= start_wall)
			color = game->textures.ceiling;
		else if (y >= end_wall)
			color = game->textures.floor;
		else
			color = choose_wall_color(y - start_wall,
					height, &game->textures, next_wall);
		img_pixel_put(&game->window, y, i, color);
		y++;
	}
}

double	get_distance(t_wall *next_wall, t_map *map)
{
	double	distance;

	next_wall->type = WALL;
	if (map->board[(int)next_wall->y / 64][(int)next_wall->x / 64] == 2)
		next_wall->type = DOOR;
	distance = sqrt(pow((map->player.pos.x * 64) - next_wall->x, 2)
			+ pow((map->player.pos.y * 64) - next_wall->y, 2));
	if (distance < 0)
		distance = -distance;
	return (distance);
}

void	raycasting(t_game *game)
{
	double	inc;
	double	ray;
	t_wall	next_wall;
	int		i;

	inc = (double)FOV / (double)RES_WIDTH;
	ray = game->map.player.angle - FOV / 2.0;
	i = 0;
	while (ray <= game->map.player.angle + (double)FOV / 2.0)
	{
		next_wall.ray = ray;
		if (ray >= PI && ray < 3.0 * PI / 2.0)
			next_wall.distance = ray_no(&next_wall, &game->map, ray);
		else if (ray < 0 || (ray > 3.0 * PI / 2.0 && ray < 2 * PI))
			next_wall.distance = ray_ne(&next_wall, &game->map, ray);
		else if (ray > 2 * PI || (ray >= 0.0 && ray < 1.5708))
			next_wall.distance = ray_se(&next_wall, &game->map, ray);
		else if (ray > 1.5708 && ray < 3.14159)
			next_wall.distance = ray_so(&next_wall, &game->map, ray);
		ray = ray + inc;
		print_ray(ray - game->map.player.angle, &next_wall, i++, game);
	}	
}
