/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:06:05 by jorbarro          #+#    #+#             */
/*   Updated: 2024/11/15 05:26:53 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include "ft_printf.h"
# include "get_next_line.h"

/*Define constants*/
# define MLX_ERROR 1
# define MAP_MAX_SIZE 999
# define IMG_SIZE 32
# define ESC 53
# define W 119
# define A 97
# define S 115
# define D 100
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1
# define WALL '1'
# define EMPTY_SPACE '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define INITIAL_POS 'P'

/*Define structures*/

typedef struct s_images
{
	int		size;
	void	*mlx;
	void	*floor;
	void	*wall;
	void	*coll;
	void	*exit;
	void	*player;
}	t_images;

typedef struct s_game
{
	char		**map;
	char		**map_cpy;
	char		**map_lines;
	void		*object;
	int			line_x;
	int			line_y;
	int			control;
	char		*joinline;
	int			x;
	int			y;
	int			collectibles;
	int			player_control;
	int			player_x;
	int			player_y;
	int			moves;
	t_images	*im;
}	t_game;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_game	*game;
}	t_mlx_data;

typedef struct s_draw_params
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_images	*im;
}	t_draw_params;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

int		read_map(char *map, t_game *game_element);
void	draw_map(t_mlx_data *data,
			t_images *im, char **map, int rows);

void	move_player(t_mlx_data *data, int new_x, int new_y);
int		check_accessibility(t_game *game);
int		handle_close(t_mlx_data *data);
void	destroy_images(t_mlx_data *data);
int		handle_input(int keysym, t_mlx_data *data);

int		is_map_closed(t_game *game);
int		check_map_shape(t_game *game);
void	check_exit_and_player(t_game *game);
void	check_collectibles(t_game *game);
void	check_break(char *line, t_game *game);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);

/*------------------pre_read_map.c-------------------*/
int		open_map_file(char *map);
int		count_lines_in_map(int fd);
void	allocate_map_memory(t_game *game, int line_count);
void	read_lines_into_map(int fd, t_game *game);
int		check_map_line_lengths(t_game *game);
/*---------------------------------------------------*/

/*-------------code main_func_one.c------------------*/
int		handle_close(t_mlx_data *data);
void	init_imgs(t_images *im);
int		check_images(t_images *im);
bool	validate_arguments(int argc);
int		open_file(char *filename);
/*---------------------------------------------------*/

/*-------------code main_func_two.c------------------*/
bool	read_and_validate_map(char *filename, t_game *game, int fd);
bool	initialize_graphics(t_mlx_data *data, t_images *im, t_game *game);
bool	load_images(t_images *im, t_mlx_data *data);
void	setup_hooks(t_mlx_data *data);
/*---------------------------------------------------*/

/*-------------------movements.c---------------------*/
void	check_boundaries(t_mlx_data *data, int new_x, int new_y);
bool	handle_exit(t_mlx_data *data, int new_x, int new_y);
int		is_move_valid(t_mlx_data *data, int new_x, int new_y);
void	update_player(t_mlx_data *data, int new_x, int new_y, t_pos *curr_pos);
void	move_to_position(t_mlx_data *data, int new_x, int new_y, int current_x);
/*---------------------------------------------------*/

#endif