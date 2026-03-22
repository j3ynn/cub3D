#include "cub.h"

//qui "sistemiamo" tutte le nostre strutture
void	init_struct(t_game *game)
{
	init_texture(&game->texture);
	init_colors(&game->colors);
	init_map(&game->map);
	init_player(&game->player);
	init_camera(&game->camera);
	init_raycast(&game->raycast);
	init_mlx(&game->mlx);
}

//funzione per gli error/exit e' da implementare
int main(int ac, char **av)
{
	//(void)av; //senza mi da problemi con il compilatore perche ancora non lo usiamo
	t_game game;

	if (ac != 2)
		ft_error("Usage: ./cub3d 'map.cub'\n");
	init_struct(&game);
	//parte del parsing
	if (!pars(&game, av[1]))
		ft_error("✧error parsing fallito (come me)\n");
	set_game(&game);
}
