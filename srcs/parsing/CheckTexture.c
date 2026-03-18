#include "cub.h"

int	valid_texture(t_texture *texture, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		texture->N_path = ft_strdup(&line[3]);
	else if (ft_strncmp(line, "SO", 2) == 0)
		texture->S_path = ft_strdup(&line[3]);
	else if (ft_strncmp(line, "WE", 2) == 0)
		texture->W_path = ft_strdup(&line[3]);
	else if (ft_strncmp(line, "EA", 2) == 0)
		texture->E_path = ft_strdup(&line[3]);
	else
		return (0);
	return (1);
}
