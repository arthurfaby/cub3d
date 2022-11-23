#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "libft.h"
# include <fcntl.h>


typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
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
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	int		floor;
	int		ceiling;
}	t_texture;

// error.c
int	error(const char *map);

// check_error_element.c
int	check_error_element(int fd);

#endif
