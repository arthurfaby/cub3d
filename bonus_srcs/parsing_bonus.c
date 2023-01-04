/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:59 by afaby             #+#    #+#             */
/*   Updated: 2023/01/04 16:10:59 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_all(const char *path, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error(ERROR" : open map failed.\n");
		return (1);
	}
	line = parse_elements(fd, game);
	if (parse_map(fd, game, line) == -1)
		return (-1);
	return (0);
}
