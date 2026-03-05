#include "cub.h"

int	init_map(t_map *map)
{
	map->map = 0; //credo sia meglio metterlo NULL, visto che marp e' char 
	map->width = 0;
	map->height = 0;
	map->n_players = 0;
	map->map_valid = true;
	return 1;
}

// FUNZIONI PER INIZIALIZZARE TUTTE LE STRUTTURE

void	init_tex(t_tex *tex)
{
	tex->path = NULL;
	tex->img = NULL;
	tex->data = NULL;
	tex->w = 0;
	tex->h = 0;
	tex->bpp = 0;
	tex->line_len = 0;
	tex->endian = 0;
}

void	init_texture(t_texture *texture)
{
	init_tex(&texture->no);
	init_tex(&texture->so);
	init_tex(&texture->ea);
	init_tex(&texture->we);
}

// valori impostati a -1 perche' i colori sono compresi tra 0 e 255, se rimangono a -1 vuol dire che non sono stati impostati
void	init_colors(t_colors *colors)
{
	colors->floor_a = -1;
	colors->floor_b = -1;
	colors->floor_c = -1;
	colors->ceiling_a = -1;
	colors->ceiling_b = -1;
	colors->ceiling_c = -1;
	colors->floor_hex = 0;
	colors->ceiling_hex = 0;
}

void	init_player(t_player *player)
{
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->spawn_dir = 0; //(N, S, E, W)
	player->exists = 0; //se è 1 il giocatore è presente nella mappa
}

void	init_camera(t_camera *camera)
{
	camera->plane_x = 0.0;
	camera->plane_y = 0.0;
}

void 	init_raycast(t_raycast *raycast)
{
	raycast->pos_dir_x = 0.0;
	raycast->pos_dir_y = 0.0;
	raycast->ray_dir_x = 0.0;
	raycast->ray_dir_y = 0.0;
	raycast->dist_x = 0.0;
	raycast->dist_y = 0.0;
	raycast->side_dist_x = 0.0;
	raycast->side_dist_y = 0.0;
	raycast->map_x = 0;
	raycast->map_y = 0;
	//raycast->hit = 0; //se è 1 c'è stato un colpo
	//raycast->side = 0; //se è 1 il muro è verticale, se è 0 il muro è orizzontale
}

void init_mlx(t_mlx *mlx)
{
	mlx->process = NULL;
	mlx->win = NULL;
	mlx->img_ptr = NULL;
	mlx->img_data = NULL;
	mlx->width = 800;
	mlx->height = 600;
}

