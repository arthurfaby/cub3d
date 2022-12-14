#include "cub3d.h"

static int	value_colors(char *str)
{
	if (ft_strcmp(str, "F") == 0)
		return (5);
	else if (ft_strcmp(str, "C") == 0)
		return (6);
	return (-1);
}

int	check_value_color(char **split_line)
{
	char	**split_color;
	int		simple_color;
	int		i;
	int		ret;

	i = 0;
	ret = value_colors(split_line[0]);
	split_color = ft_split(split_line[1], ',');
	if (size_arr(split_color) != 3)
	{
		ft_printf(ERROR": not 3 arguments for color [%s].\n", split_line[0]);
		free_arr(split_color);
		return (-1);
	}
	while (split_color[i] != NULL)
	{
		simple_color = ft_atoi(split_color[i]);
		if (ft_strlen(split_color[i]) > 3 || simple_color > 255 || simple_color < 0)
		{
			ft_printf(ERROR": color (%d) out of range for [%s].\n", simple_color, split_line[0]);
			free_arr(split_color);
			return (-1);
		}
		i++;
	}
	free_arr(split_color);
	return (ret);
}
