#include "cub.h"

//qui "sistemiamo" tutte le nostre strutture
void    ft_init_struct(t_game *game)
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
    t_game game;

    if (ac != 2)
        ft_exit_error("Usage: ./cub3d <map.cub>\n");
    ft_init_struct(&game);
    //parte del parsing
    init_game(&game);
}