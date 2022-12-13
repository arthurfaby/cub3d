#include "cub3d.h"

int		get_color_in_image(t_texture *texture, int y, int x)
{
	t_image	image;
	int		i;
	int		color;

	color = 0;
	image.img = texture->texture;
	image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.line_len, &image.endian);
	i = ((y * texture->width) + x) * 4;
	//printf("[%d][%d] -- RGB = [%d,%d,%d]\n", x, y, (unsigned char)image.addr[i + 2], (unsigned char)image.addr[i + 1], (unsigned char)image.addr[i]);
//	printf("\tcolor : %d\n", color);
	color = color | (unsigned char)(image.addr[i + 2]);
//	printf("\tcolor : %d\n", color);
//	printf("\taddr : %d\n", image.addr[i] + 128);
	color = color << 8;
	color = color | (unsigned char)(image.addr[i + 1]);
//	printf("\tcolor : %d\n", color);
	//printf("\taddr : %d\n", image.addr[i + 1] + 128);
	color = color << 8;
	color = color | (unsigned char)(image.addr[i]);
//	printf("\tcolor : %d\n", color);
	//printf("\taddr : %d\n", image.addr[i + 2] + 128);
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
