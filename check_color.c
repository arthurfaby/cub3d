#include "includes/cub3.h"

int	check_value_color(char *color)
{
	char	**split_color;
	int		simple_color;
	int		i;

	i = 0;
	split_color = ft_split(color, ',');
	if (size_arr(split_color) < 3 || size_arr(split_color) > 3)
	{
		free_arr(split_color);
		return (1);
	}
	while (split_color[i] != NULL)
	{
		simple_color = ft_atoi(split_color[i]);
			if (simple_color > 255 || simple_color < 0)
			{
				free_arr(split_color);
				return (1);
			}
	}
	free_arr(split_color);
	return (0);

}
