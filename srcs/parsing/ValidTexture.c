#include "cub.h"

int	valid_texture(t_texture *texture, t_game *game, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		game->texture.no.path = ft_strdup(&line[3]);
	else if (ft_strncmp(line, "SO", 2) == 0)
		game->texture.so.path = ft_strdup(&line[3]);
	else if (ft_strncmp(line, "WE", 2) == 0)
		game->texture.we.path = ft_strdup(&line[3]);
	else if (ft_strncmp(line, "EA", 2) == 0)
		game->texture.ea.path = ft_strdup(&line[3]);
	else
		return (0);
	return (1);
}//controllare se va bene
