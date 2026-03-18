#ifndef CUBE3D_H
# define CUB3D_H

/* GUARDARE LE LIBRERIE DA INCLUDERE */

#include "libft/libft.h"
//#include "mlx"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/* AGGIUNGERE I COLORI */

typedef struct s_map
{
	char	**map; //mappa, array di stringhe
	int		width; //larghezza mappa
	int		height; //altezza mappa
	int		n_players; //numeri giocatori (deve essere 1)
	bool	map_valid; //booleano per verificare che la mappa sia valida
}	t_map;

typedef struct s_player
{
	//double per posizione precisa nella cella, movimento fluido
	double	pos_x; //posizione x
	double	pos_y; //posizione y
	double	dir_x; //direzione x
	double	dir_y; //direzione y
	char	spawn_dir; //direzione di spawn (N, S, E, W)
	int		exists; //se il giocatore è nella mappa
}	t_player;

/* MODIFICARE LE STRUCT TEXTURE */

typedef struct s_texture
{
	char	*N_path; //texture muro Nord
	char	*S_path; //texture muro Sud
	char	*E_path; //texture muro Est
	char	*W_path; //texture muro Ovest
	//struttura immagine
	void	*N_img; //puntatore immagine Nord
	void	*S_img; //puntatore immagine Sud
	void	*E_img; //puntatore immagine Est
	void	*W_img; //puntatore immagine Ovest
	int		tex_width; //larghezza texture
	int		tex_height; //altezza texture
}	t_texture;

typedef struct s_colors
{
	int				floor_a; //colori pavimento (0 - 255)
	int				floor_b;
	int				floor_c;
	int				ceiling_a; //colori soffitto (0 - 255)
	int				ceiling_b;
	int				ceiling_c;
	unsigned int	floor_hex; //colore pavimento in formato HEX
	unsigned int	ceiling_hex; //colore soffitto in formato HEX
}	t_colors;

//rosa pastello = 255,182,193 HEX = 0xFFB6C1
//azzurro pastello = 173,216,230 HEX = 0xADD8E6
//lilla = 221,160,221 HEX = 0xDDA0DD
//pesca = 255,218,185 HEX = 0xFFDAB9

/* AGGIUNGERE STRUCT A T_GAME */
typedef struct s_game
{
	t_map		map;
	t_player	player;
	t_texture	texture;
	t_colors	colors;
}	t_game;

typedef struct s_camera
{
	double	plane_x; //piano camera x
	double	plane_y; //piano camera y
}	t_camera;

typedef struct s_raycast
{
	double	pos_dir_x; //posizione x del raggio
	double	pos_dir_y; //posizione y del raggio
	double	ray_dir_x; //direzione raggio x
	double	ray_dir_y; //direzione raggio y
	double	dist_x; //distanza percorsa lungo l’asse X per arrivare al prossimo lato
	double	dist_y; //distanza percorsa lungo l’asse y per arrivare al prossimo lato
	double	side_dist_x; //distanza dal punto iniziale del raggio al prossimo lato verticale
	double	side_dist_y; //distanza dal punto iniziale del raggio al prossimo lato orizzontale
	int		map_x; //cella mappa x
	int		map_y; //cella mappa y
}	t_raycast;

/* MODIFICHE IN T_MLX */
typedef struct s_mlx
{
	void	*mlx_ptr; //puntatore connesione MLX
	void	*win_ptr; //puntatore per la finestra (importante)
	void	*img_ptr; //puntatore immagine da renderizzare
	char	*img_data; //buffer dei pixel dell'immagine
	int		window_width; //larghezza finestra
	int		window_height; //altezza finestra
}	t_mlx;

void	calc_map_width(t_map *map);
void	flood_fill(t_map *map, int x, int y);
void	ft_free(char **arr);

int		valid_char(char c);
int		is_player(char c);
int		init_map(t_map *map);
int		finally_map(char *line);
int		error_player(t_map *map);
int		valid_texture(t_texture *texture, char *line);
int		valid_colors(t_colors *colors, char *line);
int		valid_map(t_map *map);
int		valid_player(t_map *map, t_player *player);

#endif
