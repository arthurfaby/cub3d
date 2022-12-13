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
# define RES_WIDTH 1920
# define RES_HEIGHT 1080
# define FOV PI/3 

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_wall
{
	double	x;
	double	y;
}	t_wall;

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
	int		last_x;
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
}	t_game;

//print_wall.c
void	print_wall(t_wall next_wall, int find_wall_y, int find_wall_x, t_map *map, double ray, int i, t_window *window);

//raycasting.c
void	raycasting(t_map *map, t_window *window);

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

// interaction.c
void	open_door(t_map *map);
int		mouse_move(int x, int y, t_game *game);

// utils.c
void	change_angle(t_player *player, double speed);
int		check_wall_in_map(t_map *map, t_wall *next_wall);

// ray_no.c
double	ray_no(t_wall *next_wall, t_map *map, double ray);

// ray_ne.c
double	ray_ne(t_wall *next_wall, t_map *map, double ray);

// ray_se.c
double	ray_se(t_wall *next_wall, t_map *map, double ray);

// ray_so.c
double	ray_so(t_wall *next_wall, t_map *map, double ray);

#endif
