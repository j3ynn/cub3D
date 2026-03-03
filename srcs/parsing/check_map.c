#include "cub.h"

//calcola la lunghezza della mappa
void	calc_map_width(t_map *map)
{
	int	i = 0;
	int	len;

	while (i < map->height)
	{
		len = ft_strlen(map->map[i]);
		if (len < map->width)
			map->width = len;
		i++;
	}
}

//controllo se i caratteri sono validi
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

//valida i caratteri della mappa e controlla che ci sia un solo giocatore
int	check_map_char(t_map *map)
{
	int	i = 0;
	int	j = 0;

	while (i < map->height)
	{
		while (map->map[i][j])
		{
			if (!valid_char(map->map[i][j]))
			{
				printf("Error invalid char: %c\n", map->map[i][j]);
				return 0;
			}
			if (is_player(map->map[i][j]))
				map->n_players++;
			j++;
		}
		i++;
	}
	if (map->n_players != 1)
	{
		printf("Error must have exatly 1 player\n");
		return 0;
	}

}
