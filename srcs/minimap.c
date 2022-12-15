#include "cub3d.h"

static int	is_in_circle(t_window *window, t_point here,
	t_point offset)
{
	int		tile_border;
	t_point	center;
	int		radius;
	int		distance;

	tile_border = window->width / MMAP_RATIO / MMAP_WIDTH;
	center.x = (int)(MMAP_WIDTH * tile_border / 2);
	center.y = (int)(MMAP_WIDTH * tile_border / 2);
	radius = center.x - 5;
	distance = sqrt(pow(center.x - here.x + offset.x, 2)
			+ pow(center.y - here.y + offset.y, 2));
	if (distance < radius)
		return (1);
	else if (distance == radius)
		return (2);
	return (0);
}

static int	check_in_map(t_map *map, t_point here, int tile_border)
{
	int	x_neg;
	int	x_out;
	int	y_neg;
	int	y_out;

	x_neg = (int)(here.x / tile_border) < 0;
	x_out = (int)(here.x / tile_border) >= map->width;
	y_neg = (int)(here.y / tile_border) < 0;
	y_out = (int)(here.y / tile_border) >= map->height;
	return (x_neg || x_out || y_neg || y_out);
}

static int	get_tile_type(t_map *map, t_point here, int tile_border)
{
	int	res;

	if (check_in_map(map, here, tile_border))
		return (-1);
	res = map->board[(int)(here.y / tile_border)][(int)(here.x / tile_border)];
	return (res);
}

static void	choose_and_draw_color(t_game *game, t_point here,
	t_point offset, int tile_border)
{
	int	is_in;

	is_in = is_in_circle(&game->window, here, offset);
	if (!is_in)
		return ;
	if (is_in == 2)
		img_pixel_put(&game->window, (int)here.y - offset.y,
			(int)here.x - offset.x, MMAP_WCOLOR);
	else if (get_tile_type(&game->map, here, tile_border) == 2)
		img_pixel_put(&game->window, (int)here.y - offset.y,
			(int)here.x - offset.x, MMAP_DCCOLOR);
	else if (get_tile_type(&game->map, here, tile_border) == 0)
		img_pixel_put(&game->window, (int)here.y - offset.y,
			(int)here.x - offset.x, MMAP_FCOLOR);
	else if (get_tile_type(&game->map, here, tile_border) == 3)
		img_pixel_put(&game->window, (int)here.y - offset.y,
			(int)here.x - offset.x, MMAP_DOCOLOR);
	else
		img_pixel_put(&game->window, (int)here.y - offset.y,
			(int)here.x - offset.x, MMAP_WCOLOR);
}

void	draw_minimap(t_game *game)
{
	t_point	here;
	t_point	offset;
	int		tile_border;

	tile_border = game->window.width / MMAP_RATIO / MMAP_WIDTH;
	here.x = (game->map.player.pos.x - (double)(MMAP_WIDTH / 2)) * tile_border;
	offset.x = (int)((game->map.player.pos.x - (double)(MMAP_WIDTH / 2))
			* tile_border);
	offset.y = (int)((game->map.player.pos.y - (double)(MMAP_WIDTH / 2))
			* tile_border);
	while (here.x < ((game->map.player.pos.x + (double)(MMAP_WIDTH / 2))
		* tile_border))
	{
		here.y = (game->map.player.pos.y - (MMAP_WIDTH / 2.0)) * tile_border;
		while (here.y < ((game->map.player.pos.y + (double)(MMAP_WIDTH / 2))
			* tile_border))
		{
			choose_and_draw_color(game, here, offset, tile_border);
			here.y++;
		}
		here.x++;
	}
	draw_player(&game->window, &game->map, tile_border);
	mlx_put_image_to_window(game->window.mlx, game->window.win,
		game->window.image->img, 0, 0);
}
