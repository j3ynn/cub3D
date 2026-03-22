#ifndef CUBE3D_H
# define CUB3D_H

#include "libft.h"
#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/* **************************************************************************** */
/*                                  COLORS                                      */
/* **************************************************************************** */

#define LAVENDER   	"\033[1;38;2;230;190;255m"
#define ORCHID    	"\033[1;38;2;218;112;214m"
#define PLUM      	"\033[1;38;2;221;160;221m"
#define RED         "\033[1;31m"
#define GREEN       "\033[1;32m"
#define YELLOW      "\033[1;33m"
#define CYAN        "\033[1;36m"
#define MAGENTA     "\033[1;35m"
#define BLUE        "\033[1;34m"
#define WHITE       "\033[1;37m"
#define RED_S       "\033[31m"
#define GREEN_S     "\033[32m"
#define YELLOW_S    "\033[33m"
#define CYAN_S      "\033[36m"
#define MAGENTA_S   "\033[35m"
#define BLUE_S      "\033[34m"
#define WHITE_S     "\033[37m"
#define RESET       "\033[0m"

/* **************************************************************************** */
/*                                  STRUCT                                      */
/* **************************************************************************** */

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

typedef struct	s_tex
{
	char	*path; //path della texture di ogni muro
	void	*img;
	char	*data; //puntatore ai pixel
	int		w; //larghezza vera della texture (tramite mlx_xmp_file_to_image(...))
	int		h; //altezza vera della texture (tramite mlx_xmp_file_to_image(...))
	int		bpp; //bits per pixel
	int		line_len; //bytes per riga
	int 	endian; //ordine dei byte (credo non serva idk)
} 	t_tex;

typedef struct s_texture
{
	t_tex	no;
	t_tex	so;
	t_tex	ea;
	t_tex	we;
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

typedef struct s_mlx
{
	void	*process; //puntatore connesione MLX
	void	*win; //puntatore per la finestra (importante)
	void	*img_ptr; //puntatore immagine da renderizzare
	char	*img_data; //buffer dei pixel dell'immagine
	int		width; //larghezza finestra
	int		height; //altezza finestra
}	t_mlx;

typedef struct s_game
{
	t_texture	texture; //struttura per le texture
	t_colors	colors; //struttura per i colori
	t_map		map; //struttura per la mappa
	t_player	player; //struttura per il giocatore
	t_camera	camera; //struttura per la camera
	t_raycast	raycast; //struttura per il raycasting
	t_mlx		mlx; //struttura per MLX
}	t_game;

/* **************************************************************************** */
/*                                FUNZIONI                                      */
/* **************************************************************************** */

void	calc_map_width(t_map *map);
void	flood_fill(t_map *map, int x, int y);
void	ft_free(char **arr);

int		valid_char(char c);
int		is_player(char c);
int		finally_map(char *line);
int		error_player(t_map *map);
int		valid_texture(t_texture *texture, char *line);
int		valid_colors(t_colors *colors, char *line);
int		valid_map(t_map *map);
int		valid_player(t_map *map, t_player *player);
int		pars(t_game *game, char *file);
int		save_map(t_map *map, char *line);
int		heart_pars(t_game *game, char *line, int fd, int in_map);

/* ***************************************** */
/*                  INIT                     */
/* ***************************************** */
int		init_map(t_map *map);
void	init_struct(t_game *game);
void	init_texture(t_texture *texture);
void	init_colors(t_colors *colors);
void	init_player(t_player *player);
void	init_camera(t_camera *camera);
void 	init_raycast(t_raycast *raycast);
void 	init_mlx(t_mlx *mlx);

/* ****************************************** */
/*                  ERROR                     */
/* ****************************************** */
void    ft_error(char *str);
void    exit_game(t_game *game, char *str);

/* ****************************************** */
/*                  EXCUTE                    */
/* ****************************************** */
void    set_game(t_game *game);
void    set_texture(t_game *game);

void    load_texture(t_game *game, t_tex *tex);

#endif
