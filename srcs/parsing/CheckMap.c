#include "cub.h"

//calcola la larghezza massima della mappa
void	calc_map_width(t_map *map)
{
	int	i = 0;
	int	len;

	while (i < map->height)
	{
		len = ft_strlen(map->map[i]);
		if (len > map->width)
			map->width = len;
		i++;
	}
}

//controllo se i caratteri della mappa sono validi
int	valid_char(char c)
{
	if (c == '1' || c == '0' || c == ' ' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W')
		return 1;
	else
		return 0;
}

//controllo se è un giocatore
int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return 1;
	else
		return 0;
}

int	init_map(t_map *map)
{
	map->map = 0;
	map->width = 0;
	map->height = 0;
	map->n_players = 0;
	map->map_valid = true;
	return 1;
}