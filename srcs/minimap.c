#include "cub3d.h"

static void	draw_player(t_window *window, t_map *map, int x_offset, int y_offset)
{
	t_point	center;
	t_point	end;
	int		i;
	int		j;
	int		player_border;

	player_border = window->width / MMAP_RATIO / 5;
	center.x = map->player.pos.x * window->width / MMAP_RATIO - x_offset;
	center.y = map->player.pos.y * window->width / MMAP_RATIO - y_offset;
	end.x =  10 * sin(map->player.angle) + center.x;
	end.y = 10 * cos(map->player.angle) + center.y;
	draw_line(window, &center, &end, 0);
	center.x -= player_border / 2;
	center.y -= player_border / 2;
	i = 0;
	while (i < player_border)
	{
		j = 0;	
		while (j < player_border)
		{
				img_pixel_put(window, center.y + j, center.x + i, MMAP_PCOLOR);
				j++;
		}
		i++;
	}
}

static int	is_in_circle(t_window *window, t_map *map, t_point here, int x_offset, int y_offset)
{
	int		tile_border;
	t_point	center;
	int		radius;
	int		distance;

	tile_border = window->width / MMAP_RATIO;
	center.x = (int)(map->mmap_width * tile_border / 2);
	center.y = (int)(map->mmap_width * tile_border / 2);
	radius = center.x - 5;
	distance = sqrt(pow(center.x - here.x + x_offset, 2) + pow(center.y - here.y + y_offset, 2));
	if (distance < radius)
		return (1);
	else if (distance == radius)
		return (2);
	return (0);
}

void	draw_minimap(t_window *window, t_map *map)
{
	t_point	here;
	int		x_offset;
	int		y_offset;
	int		tile_border;

	tile_border = window->width / MMAP_RATIO;
	here.x = (map->player.pos.x - (double)(map->mmap_width / 2)) * tile_border;
	x_offset = (int)((map->player.pos.x - (double)(map->mmap_width / 2)) * tile_border);
	y_offset = (int)((map->player.pos.y - (double)(map->mmap_width / 2)) * tile_border);
	while (here.x < (map->player.pos.x + (double)(map->mmap_width / 2)) * tile_border - 1)
	{
		here.y = (map->player.pos.y - (double)(map->mmap_width / 2)) * tile_border;
		while (here.y < (map->player.pos.y + (double)(map->mmap_width / 2)) * tile_border - 1)
		{
			if (is_in_circle(window, map, here, x_offset, y_offset))
			{
				if (is_in_circle(window, map, here, x_offset, y_offset) == 2)
					img_pixel_put(window, (int)here.y - y_offset, (int)here.x - x_offset, 0xFF0000);
				else if ((int)(here.y / tile_border) < 0 || (int)(here.x / tile_border) < 0 || (int)(here.y / tile_border) >= map->height || (int)(here.x / tile_border) >= map->width)
					img_pixel_put(window, (int)here.y - y_offset, (int)here.x - x_offset, MMAP_WCOLOR);
				else if (map->board[(int)(here.y / tile_border)][(int)(here.x / tile_border)] == 0)
					img_pixel_put(window, (int)here.y - y_offset, (int)here.x - x_offset, MMAP_FCOLOR);
				else
					img_pixel_put(window, (int)here.y - y_offset, (int)here.x - x_offset, MMAP_WCOLOR);
			}
			here.y++;
		}
		here.x++;
	}
	draw_player(window, map, x_offset, y_offset);
	mlx_put_image_to_window(window->mlx, window->win, window->image->img, 0, 0);
}
