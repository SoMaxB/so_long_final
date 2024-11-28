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

void init_game(t_game *game)
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

/*void    destroy_images(t_mlx_data *data) // desactivada temporal por segfault
{
    mlx_destroy_image(data->mlx_ptr, data->game->im->collectible);
    mlx_destroy_image(data->mlx_ptr, data->game->im->exit);
    mlx_destroy_image(data->mlx_ptr, data->game->im->floor);
    mlx_destroy_image(data->mlx_ptr, data->game->im->mlx);
    mlx_destroy_image(data->mlx_ptr, data->game->im->player);
    mlx_destroy_image(data->mlx_ptr, data->game->im->wall);
}*/

int main(int argc, char *argv[]) {
    t_mlx_data data;
    t_game game;
    t_images im;

    init_game(&game);
    im.size = IMG_SIZE;

    if (!validate_arguments(argc))
        return (1);

    int fd = open_file(argv[1]);
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
    draw_map(&data, &im, game.map, game.line_y, game.line_x);
    setup_hooks(&data);

    mlx_loop(data.mlx_ptr);
    return (0);
}