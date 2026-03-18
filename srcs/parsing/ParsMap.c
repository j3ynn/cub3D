#include "cub.h"

void	flood_fill(t_map *map, int x, int y)
{
	if (y < 0 || x < 0 || y >= map->height || x >= map->width)
		return (0);
	if (map->map[y][x] == '1' || map->map[y][x] == ' ' || map->map[y][x] == 'V')
		return (0);
	map->map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

//ci serve nel parsing per assicurarsi che la mappa sia in fondo al file
int	finally_map(char *line)
{
	int i = 0;

	while (line[i] != '\0')
	{
		if (!valid_char(line[i]))
			return (0);
		i ++;
	}
	return (1);
}
