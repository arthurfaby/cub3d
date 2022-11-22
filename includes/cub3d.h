#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "libft.h"
# include <fcntl.h>
# include "mlx.h"
# include "mlx_int.h"
# include <math.h>

# define MMAP_RATIO 80.0
# define MMAP_FCOLOR 0xe6e603
# define MMAP_WCOLOR 0x101040
# define MMAP_PCOLOR 0x582900
# define PI 3.1415926535

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_image
{
	int		bpp;
	int		line_len;
	int		endian;
	char	*addr;
	void	*img;
}	t_image;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	t_image	*image;
	int		width;
	int		height;
}	t_window;

typedef struct s_player
{
	t_point	pos;
	double	angle;
}	t_player;

typedef struct s_map
{
	int			board[10][13];
	int			width;
	int			height;
	double		mmap_width;
	t_player	player;
}	t_map;

typedef struct s_texture
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	int		floor;
	int		ceiling;
}	t_texture;

typedef struct s_game
{
	t_map		map;
	t_window	window;
}	t_game;

// minimap.c
void	draw_minimap(t_window *window, t_map *map);

// game.c
void	launch_game(char *argv[]);

// window.c
void	init_window(t_window *window);

// image.c
void	img_pixel_put(t_window *window, int y, int x, int color);
void	draw_line(t_window *window, t_point *p1, t_point *p2, int color);

// hook.c
int		key_hook(int keycode, t_game *game);

// mouse_hook.c
int		mouse_hook(int button, int x, int y, t_game *game);

#endif
