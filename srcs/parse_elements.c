#include "cub3d.h"

static void	init_texture(t_texture *texture, void *mlx, char **splitted)
{
	int		width;
	int		height;

	splitted[1][ft_strlen(splitted[1]) - 1] = 0;
	texture->texture = mlx_xpm_file_to_image(mlx, splitted[1], &width, &height);
	texture->width = width;
	texture->height = height;
}

static int	get_rgb_color(char *colors)
{
	char	**splitted_colors;
	int		color;

	splitted_colors = ft_split(colors, ',');
	color = 0;
	color |= ft_atoi(splitted_colors[0]);
	color <<= 8;
	color |= ft_atoi(splitted_colors[1]);
	color <<= 8;
	splitted_colors[2][ft_strlen(splitted_colors[2]) - 1] = 0;
	color |= ft_atoi(splitted_colors[2]);
	return (color);
}

static int	parse_one_elem(char **splitted, t_game *game)
{
	if (!splitted || !*splitted || ft_strcmp(splitted[0], "\n") == 0)
		return (0);
	if (ft_strcmp(splitted[0], "NO") == 0)
		init_texture(&game->textures.north, game->window.mlx, splitted);
	if (ft_strcmp(splitted[0], "SO") == 0)
		init_texture(&game->textures.south, game->window.mlx, splitted);
	if (ft_strcmp(splitted[0], "WE") == 0)
		init_texture(&game->textures.west, game->window.mlx, splitted);
	if (ft_strcmp(splitted[0], "EA") == 0)
		init_texture(&game->textures.east, game->window.mlx, splitted);
	if (ft_strcmp(splitted[0], "DO") == 0)
		init_texture(&game->textures.door, game->window.mlx, splitted);
	if (ft_strcmp(splitted[0], "F") == 0)
		game->textures.floor = get_rgb_color(splitted[1]);
	if (ft_strcmp(splitted[0], "C") == 0)
		game->textures.ceiling = get_rgb_color(splitted[1]);
	return (1);
}

static void	init_animated_textures(t_game *game)
{
	game->textures.south_1.texture = mlx_xpm_file_to_image(
			game->window.mlx, "textures/cobblestone.xpm",
			&game->textures.south_1.width, &game->textures.south_1.height);
	game->textures.south_2.texture = mlx_xpm_file_to_image(
			game->window.mlx, "textures/cobblestone2.xpm",
			&game->textures.south_2.width, &game->textures.south_2.height);
	game->textures.south_3.texture = mlx_xpm_file_to_image(
			game->window.mlx, "textures/cobblestone3.xpm",
			&game->textures.south_3.width, &game->textures.south_3.height);
	game->textures.south_4.texture = mlx_xpm_file_to_image(
			game->window.mlx, "textures/cobblestone4.xpm",
			&game->textures.south_4.width, &game->textures.south_4.height);
	game->textures.south_5.texture = mlx_xpm_file_to_image(
			game->window.mlx, "textures/cobblestone5.xpm",
			&game->textures.south_5.width, &game->textures.south_5.height);
}

int	parse_elements(int fd, t_game *game)
{
	char	*line;
	char	**splitted;
	int		nb_elem;

	nb_elem = 0;
	line = get_next_line(fd, 1);
	while (line && nb_elem != 7)
	{
		splitted = ft_split(line, ' ');
		nb_elem += parse_one_elem(splitted, game);
		free_arr(splitted);
		free(line);
		line = get_next_line(fd, 1);
	}
	init_animated_textures(game);
	return (0);
}
