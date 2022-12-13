#include "cub3d.h"

int		get_color_in_image(void *img, int x, int y)
{
	t_image	image;
	int		i;
	//char	*pixel;

	image.img = img;
	image.addr = mlx_get_data_addr(img, &image.bpp, &image.line_len, &image.endian);
//	pixel = image.addr + (y * image.line_len) + x * (image.bpp / 8);
	i = (y * image.line_len) + x * (image.bpp / 8);
	printf("line_len : %d\n", image.line_len);
	printf("[%d][%d] -- RGB = [%d,%d,%d]\n", x, y, image.addr[i + 2], image.addr[i + 1], image.addr[i]);
	return (0);
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
