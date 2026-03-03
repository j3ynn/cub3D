#include "cub.h"

int	init_map(t_map *map)
{
	map->map = 0;
	map->width = 0;
	map->height = 0;
	map->n_players = 0;
	map->map_valid = true;
	return 1;
}
