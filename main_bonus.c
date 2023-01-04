/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:12:00 by afaby             #+#    #+#             */
/*   Updated: 2023/01/04 16:12:03 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char *argv[])
{
	int	ret;

	if (argc != 2)
	{
		ft_print_error(ERROR": format must be [%s <map.cub>]\n", argv[0]);
		return (0);
	}
	ret = launch_game(argv);
	return (ret);
}
