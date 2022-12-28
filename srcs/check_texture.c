#include "cub3d.h"

static int	value_elements(char *str)
{
	if (ft_strcmp(str, "NO") == 0)
		return (0);
	if (ft_strcmp(str, "SO") == 0)
		return (1);
	if (ft_strcmp(str, "WE") == 0)
		return (2);
	if (ft_strcmp(str, "EA") == 0)
		return (3);
	if (ft_strcmp(str, "DO") == 0)
		return (4);
	return (-1);
}

static int	check_texture(char	*image, int width, int height, char	**element)
{
	if (image == NULL)
	{
		ft_print_error(ERROR": %s is not a valid path for [%s]\n",
			element[1], element[0]);
		return (1);
	}
	else if (width != height)
	{
		ft_print_error(ERROR": image of [%s] is not a square\n", element[0]);
		return (1);
	}
	return (0);
}

int	check_value_texture(char **element)
{
	void	*mlx;
	void	*image;
	int		width;
	int		height;
	int		return_value;

	mlx = mlx_init();
	image = mlx_xpm_file_to_image(mlx, element[1], &width, &height);
	return_value = value_elements(element[0]);
	if (check_texture(image, width, height, element) == 1)
		return_value = -1;
	mlx_destroy_image(mlx, image);
	mlx_destroy_display(mlx);
	free(mlx);
	return (return_value);
}
