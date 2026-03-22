#include "cub.h"

//valida un solo giocatore + salva la sua posizione
int	valid_player(t_map *map, t_player *player)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (is_player(map->map[i][j]))
			{
				map->n_players++;
				player->pos_y = i;
				player->pos_x = j;
				player->spawn_dir = map->map[i][j];
			}
			j++;
		}
		i++;
	}
	return (error_player(map));
}

int	error_player(t_map *map)
{
	if (map->n_players != 1)
	{
		printf("✧error must have exatly 1 player\n");
		return (0);
	}
	return (1);
}
