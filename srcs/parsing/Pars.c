#include "cub.h"

int	pars(t_game *game, char *file)
{
	int		fd;
	int		in_map;
	char	*line;

	line = NULL;
	in_map = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_error("✧error open file\n");
		return (0);
	}
	heart_pars(game, line, fd, in_map);
	close(fd);
	calc_map_width(&game->map);
	valid_map(&game->map);
	valid_player(&game->map, &game->player);
	flood_fill(&game->map, game->player.pos_x, game->player.pos_y);
	return 1;
}

int	heart_pars(t_game *game, char *line, int fd, int in_map)
{
	while ((line = get_next_line(fd)) != NULL)
	{
		if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0 ||
			ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
			valid_texture(&game->texture, line);
		else if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
			valid_colors(&game->colors, line);
		else if (finally_map(line))
		{
			save_map(&game->map, line);
			in_map = 1;
		}
		else if (in_map == 1)
			ft_error("✧error is not the map\n");
	}
	return (1);
}


int	save_map(t_map *map, char *line)
{
	char	**arr;
	int		i;

	i = 0;
	arr = malloc(sizeof(char *) * (map->height + 2));
	if (!arr)
		return 0;
	while (i < map->height)
	{
		arr[i] = map->map[i];
		i++;
	}
	arr[map->height] = ft_strdup(line);
	arr[map->height + 1] = NULL;
	free(map->map);
	map->height++;
	map->map = arr;
	return 1;
}
