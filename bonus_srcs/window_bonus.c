/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:11:25 by afaby             #+#    #+#             */
/*   Updated: 2023/01/04 16:11:25 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_window(t_window *window)
{
	window->mlx = mlx_init();
	window->height = RES_HEIGHT;
	window->width = RES_WIDTH;
	window->win = mlx_new_window(
			window->mlx,
			window->width,
			window->height,
			"cub3d"
			);
	window->image = malloc(sizeof(t_image));
	if (!window->image)
	{
		ft_print_error("malloc failed");
		return (1);
	}
	window->image->img = mlx_new_image(window->mlx,
			window->width, window->height);
	window->image->addr = mlx_get_data_addr(window->image->img,
			&window->image->bpp, &window->image->line_len,
			&window->image->endian);
	return (0);
}
