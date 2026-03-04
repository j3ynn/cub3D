#include "cub.h"

void    set_game(t_game *game)
{
    game->mlx.process = mlx_init();
    //mettere i check "if (!game->mlx.process)"
    game->mlx.width = 1024;
    game->mlx.height = 768;
    game->mlx.win = mlx_new_window(game->mlx.process, game->mlx.width, game->mlx.height, "cub3d");
    //stesso check
    //COSA IMPORTANTE DA FARE
    //mlx.width e mlx.height non sono inizializzati, impostare i valori a 1024 e 768 (momentanemente per i test)
    //set_img(game);
}
