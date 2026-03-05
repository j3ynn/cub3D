#include "cub.h"

void    set_game(t_game *game)
{
    game->mlx.process = mlx_init();
    if (!game->mlx.process)
        ft_error("mlx error");
    game->mlx.win = mlx_new_window(game->mlx.process, game->mlx.width, game->mlx.height, "cub3d");
    if (!game->mlx.win)
        exit_game(game, "win error");
    //set_texture(game);
    //set_img(game);
}
