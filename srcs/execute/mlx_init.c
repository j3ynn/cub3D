#include "cub.h"

void    load_texture(t_game *game, t_tex *tex)
{
    tex->img = mlx_xpm_file_to_image(game->mlx.process, tex->path, &tex->w, &tex->h);
    if (!tex->img)
        exit_game(game, "texture load error");
    tex->data = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len, &tex->endian);
}

void    set_texture(t_game *game)
{
    load_texture(game, &game->texture.no);
    load_texture(game, &game->texture.so);
    load_texture(game, &game->texture.ea);
    load_texture(game, &game->texture.we);
}

void    set_game(t_game *game)
{
    game->mlx.process = mlx_init();
    if (!game->mlx.process)
        ft_error("mlx error");
    game->mlx.win = mlx_new_window(game->mlx.process, game->mlx.width, game->mlx.height, "cub3d");
    if (!game->mlx.win)
        exit_game(game, "win error");
    set_texture(game);
    //set_img(game);
}
