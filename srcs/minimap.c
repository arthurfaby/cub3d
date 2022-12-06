#include "cub3d.h"

static void	draw_player(t_window *window, t_map *map, int tile_border)
{
	t_point	center;
	t_point	end;
	int		i;
	int		j;

	center.x = (double)((double)MMAP_WIDTH / 2 * tile_border);
	center.y = center.x;
	end.x = 20 * sin(map->player.angle) + center.x;
	end.y = 20 * cos(map->player.angle) + center.y;
	draw_line(window, &center, &end, 0);
	i = -3;
	while (i < 4)
	{
		j = -3;
		while (j < 4)
		{
			img_pixel_put(window, center.y + j, center.x + i, MMAP_PCOLOR);
			j++;
		}
		i++;
	}
}

static int	is_in_circle(t_window *window, t_point here,
						int x_offset, int y_offset)
{
	int		tile_border;
	t_point	center;
	int		radius;
	int		distance;

	tile_border = window->width / MMAP_RATIO / MMAP_WIDTH;
	center.x = (int)(MMAP_WIDTH * tile_border / 2);
	center.y = (int)(MMAP_WIDTH * tile_border / 2);
	radius = center.x - 5;
	distance = sqrt(pow(center.x - here.x + x_offset, 2)
			+ pow(center.y - here.y + y_offset, 2));
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
	if (res == 3)
		return (0);
	return (res);
}

void	draw_minimap(t_window *window, t_map *map)
{
	t_point	here;
	int		x_offset;
	int		y_offset;
	int		tile_border;

	tile_border = window->width / MMAP_RATIO / MMAP_WIDTH;
	here.x = (map->player.pos.x - (double)(MMAP_WIDTH / 2)) * tile_border;
	x_offset = (int)((map->player.pos.x - (double)(MMAP_WIDTH / 2))
			* tile_border);
	y_offset = (int)((map->player.pos.y - (double)(MMAP_WIDTH / 2))
			* tile_border);
	while (here.x < ((map->player.pos.x + (double)(MMAP_WIDTH / 2))
		* tile_border))
	{
		here.y = (map->player.pos.y - (double)(MMAP_WIDTH / 2)) * tile_border;
		while (here.y < ((map->player.pos.y + (double)(MMAP_WIDTH / 2))
			* tile_border))
		{
			if (is_in_circle(window, here, x_offset, y_offset))
			{
				if (is_in_circle(window, here, x_offset, y_offset) == 2)
					img_pixel_put(window, (int)here.y - y_offset,
						(int)here.x - x_offset, MMAP_WCOLOR);
				else if (get_tile_type(map, here, tile_border) == 2)
					img_pixel_put(window, (int)here.y - y_offset,
						(int)here.x - x_offset, MMAP_DCOLOR);
				else if (get_tile_type(map, here, tile_border) == 0)
					img_pixel_put(window, (int)here.y - y_offset,
						(int)here.x - x_offset, MMAP_FCOLOR);
				else
					img_pixel_put(window, (int)here.y - y_offset,
						(int)here.x - x_offset, MMAP_WCOLOR);
			}
			here.y++;
		}
		here.x++;
	}
	draw_player(window, map, tile_border);
	mlx_put_image_to_window(window->mlx, window->win, window->image->img, 0, 0);
}
