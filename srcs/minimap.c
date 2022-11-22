#include "cub3d.h"

static void	draw_player(t_window *window, t_map *map, int x_offset, int y_offset)
{
	t_point	center;
	t_point	end;
	int		i;
	int		j;
	int		player_border;

	player_border = window->width / map->mmap_ratio / 5;
	center.x = map->player.pos.x * window->width / map->mmap_ratio - x_offset;
	center.y = map->player.pos.y * window->width / map->mmap_ratio - y_offset;
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

	tile_border = window->width / map->mmap_ratio;
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

static int  check_wall(t_map *map, t_point here, int tile_border)
{
	int	res;

	res = map->board[(int)(here.y / tile_border)][(int)(here.x / tile_border)];
	return (res == 1);
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

void	draw_minimap(t_window *window, t_map *map)
{
	t_point	here;
	//int		mmap_size;
	int		x_offset;
	int		y_offset;
	int		tile_border;

	map->mmap_ratio = window->width / 8 / map->mmap_width;
	tile_border = window->width / map->mmap_ratio;
	printf("%f, %f, %d\n", map->mmap_width, map->mmap_ratio, tile_border);
	//mmap_size
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
				else if (check_in_map(map, here, tile_border))
					img_pixel_put(window, (int)here.y - y_offset, (int)here.x - x_offset, MMAP_WCOLOR);
				else if (!check_wall(map, here, tile_border))
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
