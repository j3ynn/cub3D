#include "cub.h"

int	valid_texture(t_texture *texture, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		texture->no.path = ft_strdup(&line[3]);
	else if (ft_strncmp(line, "SO", 2) == 0)
		texture->so.path = ft_strdup(&line[3]);
	else if (ft_strncmp(line, "WE", 2) == 0)
		texture->we.path = ft_strdup(&line[3]);
	else if (ft_strncmp(line, "EA", 2) == 0)
		texture->ea.path = ft_strdup(&line[3]);
	else
		return (0);
	return (1);
}
