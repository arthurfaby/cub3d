#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "libft.h"
# include <fcntl.h>
# include "mlx.h"
# include "mlx_int.h"
# include <math.h>


# define MMAP_WIDTH 9.0
# define MMAP_RATIO 6.0
# define MMAP_FCOLOR 0xe6e603
# define MMAP_WCOLOR 0x101040
# define MMAP_PCOLOR 0x582900
# define MMAP_DCOLOR 0x017000
# define PI 3.1415926535

# define ERROR "[\e[31mERROR\e[0m]"

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
	t_player	player;
}	t_map;

typedef struct s_texture
{
	void	*texture;
	int		width;
	int		height;
}	t_texture;

typedef struct s_textures
{
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	int			floor;
	int			ceiling;
}	t_textures;

typedef struct s_game
{
	t_map		map;
	t_window	window;
	t_textures	textures;
}	t_game;

//check_texture.c
int	check_value_texture(char **element);

//error.c
int		error(const char *map);

//check_error_element.c
int		check_error_element(int fd);

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

// check_color.c
int	check_value_color(char **split_line);

// check_map.c
int	check_map(const char *map);


#endif
