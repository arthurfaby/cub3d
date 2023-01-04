/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:07 by afaby             #+#    #+#             */
/*   Updated: 2023/01/04 16:10:09 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_window *window, t_map *map, int tile_border)
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

int	get_color_in_image(t_texture *texture, int y, int x)
{
	t_image	image;
	int		i;
	int		color;

	color = 0;
	image.img = texture->texture;
	image.addr = mlx_get_data_addr(image.img, &image.bpp,
			&image.line_len, &image.endian);
	i = ((y * texture->width) + x) * 4;
	color = color | (unsigned char)(image.addr[i + 2]);
	color = color << 8;
	color = color | (unsigned char)(image.addr[i + 1]);
	color = color << 8;
	color = color | (unsigned char)(image.addr[i]);
	return (color);
}

void	img_pixel_put(t_window *window, int y, int x, int color)
{
	char	*pixel;
	int		i;

	if (y >= window->height || y < 0)
		return ;
	if (x >= window->width || x < 0)
		return ;
	i = window->image->bpp - 8;
	pixel = window->image->addr + (y * window->image->line_len)
		+ x * (window->image->bpp / 8);
	while (i >= 0)
	{
		if (window->image->endian)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (window->image->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}	
}

void	draw_line(t_window *window, t_point *p1, t_point *p2, int color)
{
	double	dx;
	double	dy;
	int		pixels;
	double	x;
	double	y;

	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	pixels = sqrt((dx * dx) + (dy * dy));
	dx /= pixels;
	dy /= pixels;
	x = p1->x;
	y = p1->y;
	while (pixels)
	{
		img_pixel_put(window, x, y, color);
		x += dx;
		y += dy;
		--pixels;
	}
}
