/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:04:50 by jorbarro          #+#    #+#             */
/*   Updated: 2024/11/15 04:29:08 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->map = NULL;
	game->map = NULL;
	game->object = NULL;
	game->line_x = 0;
	game->line_y = 0;
	game->control = 0;
	game->joinline = NULL;
	game->x = 0;
	game->y = 0;
	game->collectibles = 0;
	game->player_control = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->moves = 0;
}

void	destroy_images(t_mlx_data *data)
{
	if (data->game->im->coll)
	{
		mlx_destroy_image(data->mlx_ptr, data->game->im->coll);
		data->game->im->coll = NULL;
	}
	if (data->game->im->exit)
	{
		mlx_destroy_image(data->mlx_ptr, data->game->im->exit);
		data->game->im->exit = NULL;
	}
	if (data->game->im->floor)
	{
		mlx_destroy_image(data->mlx_ptr, data->game->im->floor);
		data->game->im->floor = NULL;
	}
	if (data->game->im->player)
	{
		mlx_destroy_image(data->mlx_ptr, data->game->im->player);
		data->game->im->player = NULL;
	}
	if (data->game->im->wall)
	{
		mlx_destroy_image(data->mlx_ptr, data->game->im->wall);
		data->game->im->wall = NULL;
	}
}

void	destroy_game(t_game *game)
{
	int	i;

	if (game == NULL)
		return ;
	if (game->map)
	{
		i = 0;
		while (i < game->line_y)
		{
			free(game->map[i]);
			free(game->map_cpy[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
		free(game->map_cpy);
	}
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_mlx_data	data;
	t_game		game;
	t_images	im;

	init_game(&game);
	im.size = IMG_SIZE;
	if (!validate_arguments(argc))
		return (1);
	fd = open_file(argv[1]);
	if (fd == -1)
		return (1);
	if (!read_and_validate_map(argv[1], &game, fd))
		return (1);
	if (!initialize_graphics(&data, &im, &game))
		return (MLX_ERROR);
	if (!load_images(&im, &data))
		return (1);
	data.game = &game;
	data.game->im = &im;
	draw_map(&data, &im, game.map, game.line_y);
	setup_hooks(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

void	move_player(t_mlx_data *data, int new_x, int new_y)
{
	int	current_x;
	int	current_y;

	current_x = data->game->player_x;
	current_y = data->game->player_y;
	check_boundaries(data, new_x, new_y);
	if (handle_exit(data, new_x, new_y))
		return ;
	move_to_position(data, new_x, new_y, current_x);
}
