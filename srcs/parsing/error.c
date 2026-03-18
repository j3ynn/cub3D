#include "cub.h"

void    ft_error(char *str)
{
    printf(ORCHID "%s" RESET, str);
    exit(1);
}

//importante non invertire l'ordine, o almeno penultimo win e utlimo process, senno segfault
void    exit_game(t_game *game, char *str)
{
    if (game->mlx.img_ptr)
        mlx_destroy_image(game->mlx.process, game->mlx.img_ptr);
    if (game->mlx.win)
    mlx_destroy_window(game->mlx.process, game->mlx.win);
    if (game->mlx.process)
    {
        mlx_destroy_display(game->mlx.process);
        free(game->mlx.process);
    }
    ft_error(str);
}
