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
# define MMAP_DOCOLOR 0x017000
# define MMAP_DCCOLOR 0x970300
# define PI 3.14159265358979323846
# define RES_WIDTH 1920
# define RES_HEIGHT 1080
# define FOV 1.0471975512

typedef enum e_face
{
	NORTH,
	SOUTH,
	EAST,
	WEST
} t_face;

typedef enum e_side
{
	HORIZONTAL = 12,
	VERTICAL
} t_side;

typedef enum e_type
{
	WALL = 42,
	DOOR = 43
} t_type;

# define ERROR "[\e[31mERROR\e[0m]"

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_wall
{
	double	x;
	double	y;
	double	distance;
	double	ray;
	t_side	side;
	t_face	face;
	t_type	type;
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
	int		inclination;
}	t_player;

typedef struct s_map
{
	int			**board;
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
	t_texture	door;
	t_texture	south_1;
	t_texture	south_2;
	t_texture	south_3;
	t_texture	south_4;
	t_texture	south_5;
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
int		check_value_texture(char **element);

//error.c
int		error(const char *path, t_map *map);

//check_error_element.c
int		check_error_element(int fd);

//raycast.c
void	raycasting(t_game *game);
double	get_distance(t_wall *next_wall, t_map *map);

// minimap.c
void	draw_minimap(t_window *window, t_map *map);

// game.c
int		launch_game(char *argv[]);

// window.c
void	init_window(t_window *window);

// drawing.c
void	img_pixel_put(t_window *window, int y, int x, int color);
void	draw_line(t_window *window, t_point *p1, t_point *p2, int color);
int		get_color_in_image(t_texture *texture, int x, int y);

// hook.c
int		key_hook(int keycode, t_game *game);

// check_color.c
int		check_value_color(char **split_line);

// check_map.c
int		check_map(int fd, t_map *map);
int		check_map_content(t_map *map);

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

// parsing.c
int		parse_all(const char *path, t_game *game);

// parse_elements.c
int		parse_elements(int fd, t_game *game);

// parse_map.c
int		parse_map(int fd, t_game *game);

#endif
