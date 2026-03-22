#include "cub.h"

//valida i caratteri della mappa
int	valid_map(t_map *map)
{
	int	i = 0;
	int	j;

	while (i < map->height)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!valid_char(map->map[i][j]))
			{
				printf("✧error invalid char: %c\n", map->map[i][j]);
				return 0;
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	flood_fill(t_map *map, int x, int y)
{
	if (y < 0 || x < 0 || y >= map->height || x >= map->width)
		ft_error("✧error map is not closed\n");
	if (map->map[y][x] == '1' || map->map[y][x] == 'V')
		return ;
	if (map->map[y][x] == ' ')
		ft_error("✧error map not closed\n");
	map->map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

//ci serve nel parsing per assicurarsi che la mappa sia in fondo al file
int	finally_map(char *line)
{
	int i;

	i = 0;
	if (line[0] == '\n' || line[0] == '\0')
		return (0);
	while (line[i] != '\0')
	{
		if (!valid_char(line[i]))
			return (0);
		i ++;
	}
	return (1);
}
