/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:09:16 by afaby             #+#    #+#             */
/*   Updated: 2023/01/04 16:09:18 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	value_colors(char *str)
{
	if (ft_strcmp(str, "F") == 0)
		return (5);
	else if (ft_strcmp(str, "C") == 0)
		return (6);
	return (-1);
}

static int	error_color(char **split_color, char **split_line, int i)
{
	int	simple_color;
	int	j;

	j = -1;
	if (split_color[i][++j] == '-' || split_color[i][j] == '+')
		j++;
	while (split_color[i][j])
	{
		if (ft_isdigit(split_color[i][j++]) == 0)
		{
			ft_printf(ERROR": (%s) is not digital.\n", split_color[i]);
			free_arr_char(split_color);
			return (-1);
		}
	}
	simple_color = ft_atoi(split_color[i]);
	if (ft_strlen(split_color[i]) > 3 || simple_color > 255
		|| simple_color < 0)
	{
		ft_printf(ERROR": color (%s) out of range for [%s].\n",
			split_color[i], split_line[0]);
		free_arr_char(split_color);
		return (-1);
	}
	return (0);
}

int	check_value_color(char **split_line)
{
	char	**split_color;
	int		i;
	int		ret;

	i = 0;
	ret = value_colors(split_line[0]);
	split_color = ft_split(split_line[1], ',');
	if (size_arr(split_color) != 3)
	{
		ft_printf(ERROR": not 3 arguments for color [%s].\n", split_line[0]);
		free_arr_char(split_color);
		return (-1);
	}
	while (split_color[i] != NULL)
	{
		if (error_color(split_color, split_line, i) == -1)
			return (-1);
		i++;
	}
	free_arr_char(split_color);
	return (ret);
}
