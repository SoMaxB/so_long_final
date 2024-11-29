/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:41:42 by jorbarro          #+#    #+#             */
/*   Updated: 2024/11/28 19:41:45 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_w(int keysym, t_mlx_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->game->player_x;
	new_y = data->game->player_y;
	if (keysym == W)
	{
		if (new_y > 0)
		{
			new_y--;
			if (data->game->map[new_y][new_x] != '1')
			{
				if (data->game->map[new_y][new_x] == COLLECTIBLE)
				{
					data->game->collectibles--;
					ft_printf("¡Coleccionable recogido!\n");
				}
				move_player(data, new_x, new_y);
			}
		}
	}
}

void	handle_s(int keysym, t_mlx_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->game->player_x;
	new_y = data->game->player_y;
	if (keysym == S)
	{
		if (new_y < data->game->line_y - 1)
		{
			new_y++;
			if (data->game->map[new_y][new_x] != '1')
			{
				if (data->game->map[new_y][new_x] == COLLECTIBLE)
				{
					data->game->collectibles--;
					ft_printf("¡Coleccionable recogido!\n");
				}
				move_player(data, new_x, new_y);
			}
		}
	}
}

void	handle_a(int keysym, t_mlx_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->game->player_x;
	new_y = data->game->player_y;
	if (keysym == A)
	{
		if (new_x > 0)
		{
			new_x--;
			if (data->game->map[new_y][new_x] != '1')
			{
				if (data->game->map[new_y][new_x] == COLLECTIBLE)
				{
					data->game->collectibles--;
					ft_printf("¡Coleccionable recogido!\n");
				}
				move_player(data, new_x, new_y);
			}
		}
	}
}

void	handle_d(int keysym, t_mlx_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->game->player_x;
	new_y = data->game->player_y;
	if (keysym == D)
	{
		if (new_x < data->game->line_x - 1)
		{
			new_x++;
			if (data->game->map[new_y][new_x] != '1')
			{
				if (data->game->map[new_y][new_x] == COLLECTIBLE)
				{
					data->game->collectibles--;
					ft_printf("¡Coleccionable recogido!\n");
				}
				move_player(data, new_x, new_y);
			}
		}
	}
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	handle_w(keysym, data);
	handle_s(keysym, data);
	handle_a(keysym, data);
	handle_d(keysym, data);
	if (data->game->collectibles == 0)
		ft_printf("Coleccionables recogidos! La salida está activa.\n");
	return (0);
}
