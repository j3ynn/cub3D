#include "cub.h"

int	valid_colors(t_colors *colors, char *line)
{
	char	**rgb;

	if (ft_strncmp(line, "F", 1) == 0)
	{
		rgb = ft_split(&line[2], ',');
		colors->floor_a = ft_atoi(rgb[0]);
		colors->floor_b = ft_atoi(rgb[1]);
		colors->floor_c = ft_atoi(rgb[2]);
		ft_free(rgb);
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		rgb = ft_split(&line[2], ',');
		colors->ceiling_a = ft_atoi(rgb[0]);
		colors->ceiling_b = ft_atoi(rgb[1]);
		colors->ceiling_c = ft_atoi(rgb[2]);
		ft_free(rgb);
	}
	else
		return (0);
	return (1);
}

void	ft_free(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
