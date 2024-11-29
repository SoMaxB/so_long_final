/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_func_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:42:26 by jorbarro          #+#    #+#             */
/*   Updated: 2024/11/28 19:42:28 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	read_and_validate_map(char *filename, t_game *game, int fd)
{
	game->line_x = 0;
	game->line_y = 0;
	if (read_map(filename, game) != 0)
	{
		ft_printf("Error reading map\n", stderr);
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}

bool	initialize_graphics(t_mlx_data *data, t_images *im, t_game *game)
{
	int	win_width;
	int	win_height;
	int	adj_w;

	win_width = game->line_x * im->size;
	adj_w = win_width - im->size;
	win_height = game->line_y * im->size;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (false);
	data->win_ptr = mlx_new_window(data->mlx_ptr, adj_w, win_height, "SL");
	if (data->win_ptr == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (false);
	}
	return (true);
}

bool	load_images(t_images *im, t_mlx_data *data)
{
	im->mlx = data->mlx_ptr;
	im->player = NULL;
	init_imgs(im);
	if (check_images(im) != 0)
	{
		ft_printf("Error loading images\n", stderr);
		return (false);
	}
	return (true);
}

void	setup_hooks(t_mlx_data *data)
{
	mlx_key_hook(data->win_ptr, handle_input, data);
	mlx_hook(data->win_ptr, 17, 0, handle_close, data);
}
