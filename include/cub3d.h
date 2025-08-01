/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:57:57 by seruff            #+#    #+#             */
/*   Updated: 2025/08/01 15:29:21 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../minilibx-linux/mlx.h"

# define TILE_SIZE 64

# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_ESC	65307
# define CLOSE_BTN	17
# define IMG_NO		0
# define IMG_SO		1
# define IMG_WE		2
# define IMG_EA		3

typedef struct s_data		t_data;
typedef struct s_content	t_content;
typedef struct s_file		t_file;
typedef struct s_ray		t_ray;
typedef struct s_img		t_img;
typedef struct s_player		t_player;
typedef struct s_texture	t_texture;

//Textures of each elements (NO SO WE EA)
//[0]NO [1]SO [2]EA [3]WE
typedef struct s_texture
{
	void	*img;
	char	*img_addr;
	int	height;
	int	width;
	int	bits;
	int	line_length;
	int	endian;
}		t_texture;

// Main struct with link to parsing(file), init(player/content)
typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*av_file;
	t_file		*infile;
	t_player	*player;
	t_content	*content;
	t_texture	texture[4];
	t_texture	img;
}		t_data;

// Content of the file (extract map and textures)
typedef struct s_file
{
	int	nb_element;	
	int	line_end_element;
	char	**file;
	int	*floor;
	int	*ceiling;
	char	**elements; //1 NO 2 SO 3 WE 4 EA 5 F 6 C /* Could/Should be char ***elements */
	char	**map_bloc;
	int	nb_player;
}		t_file;

// Content of the map
typedef struct s_content
{
	int		width;
	int		height;
	double		x_player;
	double		y_player;
	char		dir_player;
}			t_content;

// Player information(position/view)
typedef struct s_player
{
	double	x_view;
	double	y_view;
	double	x_player;
	double	y_player;
	double	x_plane;
	double	y_plane;
}		t_player;


// UTILS
int		max_width_map(char *file); // Largeur de la ligne la plus grande de la char **map
int		get_width_map(char *line); // Largeur de la ligne sans \n
int		empty_string(char *line); // Verifie que la ligne est vide == 0 sinon == 1
void	print_error(char *mess); // Affiche le mess d'erreur avec le "Error\n" demande
void	exit_win(t_data *data, int code); // Exit le programme et free le programme
void	free_file(t_file *infile);

//MOVE
int	key_event(int key, t_data *data);

//RAYCASTER
int		get_pos_player(t_data *data);
int		fill_data(t_data *data);
void	build(t_data *data);

//PARSING
int		line_is_map(char *line); //Verifie si c'est une ligne de la map (avec 0/1/W/N/S/W)
int		is_element(char *line); // Verifie si l'element est un valide (return 0) sinon (return 1)
int		check_and_extract_map(t_file *infile);
int		check_element_value(t_file *in, char **element);
int		check_content_map(t_file *in, char **map_bloc);
int		split_element_map(t_file *infile); // Separe les elements de la carte rempli (char **elements, char **map_bloc)
int		copy_file(t_file *infile, char *av_file); // Copy le fichier (av[1]) dans le char **file
int		check_infile(t_file *infile); // Verifie l'ordre et la nature des elements de char **elements
void		init_file(t_data *data); // Main de l'initialisation.

//GAME
int	load_images(t_data *data, t_file *in);
void	stock_map_size(t_data *data, t_file *in);
void	init_window(t_data *data);
void	init_game(t_data *data);



#endif
