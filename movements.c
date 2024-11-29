/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:43:08 by jorbarro          #+#    #+#             */
/*   Updated: 2024/11/28 19:43:10 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_boundaries(t_mlx_data *data, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= data->game->line_x
		|| new_y < 0 || new_y >= data->game->line_y)
	{
		ft_printf("Movimiento fuera de límites.\n");
		return ;
	}
}

bool	handle_exit(t_mlx_data *data, int new_x, int new_y)
{
	if (data->game->map[new_y][new_x] == 'E')
	{
		if (data->game->collectibles > 0)
		{
			ft_printf("No puedes pasar, aún hay coleccionables por recoger!\n");
			return (false);
		}
		else
		{
			ft_printf("¡Has ganado!\n");
			handle_close(data);
			return (true);
		}
	}
	return (false);
}

int	is_move_valid(t_mlx_data *data, int new_x, int new_y)
{
	return (data->game->map[new_y][new_x] != '1'
	&& data->game->map[new_y][new_x] != 'E');
}

void	update_player(t_mlx_data *data, int new_x, int new_y, t_pos *curr_pos)
{
	data->game->map[curr_pos->y][curr_pos->x] = '0';
	data->game->map[new_y][new_x] = 'P';
	data->game->player_x = new_x;
	data->game->player_y = new_y;
	data->game->moves++;
	ft_printf("Llevas %d movimientos\n", data->game->moves);
}

void	move_to_position(t_mlx_data *data, int new_x, int new_y, int current_x)
{
	t_pos		current_pos;

	current_pos.x = current_x;
	current_pos.y = data->game->player_y;
	if (is_move_valid(data, new_x, new_y))
	{
		update_player(data, new_x, new_y, &current_pos);
		draw_map(data, data->game->im, data->game->map, data->game->line_y);
	}
}
