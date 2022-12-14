/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:48 by afaby             #+#    #+#             */
/*   Updated: 2023/01/04 16:20:51 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_texture(t_texture *texture, void *mlx, char **splitted)
{
	int		width;
	int		height;

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
	color |= ft_atoi(splitted_colors[2]);
	free_arr_char(splitted_colors);
	return (color);
}

static int	parse_one_elem(char **splitted, t_game *game)
{
	if (!splitted || !*splitted || ft_strcmp(splitted[0], "\n") == 0)
		return (0);
	if (ft_strcmp(splitted[0], "NO") == 0)
		init_texture(&game->textures.north, game->window.mlx, splitted);
	if (ft_strcmp(splitted[0], "WE") == 0)
		init_texture(&game->textures.west, game->window.mlx, splitted);
	if (ft_strcmp(splitted[0], "EA") == 0)
		init_texture(&game->textures.east, game->window.mlx, splitted);
	if (ft_strcmp(splitted[0], "SO") == 0)
		init_texture(&game->textures.south, game->window.mlx, splitted);
	if (ft_strcmp(splitted[0], "F") == 0)
		game->textures.floor = get_rgb_color(splitted[1]);
	if (ft_strcmp(splitted[0], "C") == 0)
		game->textures.ceiling = get_rgb_color(splitted[1]);
	return (1);
}

char	*parse_elements(int fd, t_game *game)
{
	char	*line;
	char	**splitted;
	int		nb_elem;

	nb_elem = 0;
	line = get_next_line(fd, 1);
	while (line && nb_elem != 6)
	{
		splitted = ft_split(line, ' ');
		nb_elem += parse_one_elem(splitted, game);
		free_arr_char(splitted);
		free(line);
		line = get_next_line(fd, 1);
	}
	return (line);
}
