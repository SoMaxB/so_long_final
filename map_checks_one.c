/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:42:43 by jorbarro          #+#    #+#             */
/*   Updated: 2024/11/28 19:42:47 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_first_row(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->line_x)
	{
		if (game->map_cpy[0][i] != WALL && game->map_cpy[0][i] != '\n')
		{
			ft_printf("Error en la primera línea en la posición %d\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_last_row(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->line_x)
	{
		if (game->map_cpy[game->line_y - 1][i] != WALL
		&& game->map_cpy[game->line_y - 1][i] != '\n')
		{
			ft_printf("Error en la última línea en la posición %d\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_first_column(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->line_y)
	{
		if (game->map_cpy[i][0] != WALL)
		{
			ft_printf("Error en el primer carácter de la línea %d\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_last_column(t_game *game)
{
	int	i;
	int	last_pos;

	i = 0;
	while (i < game->line_y)
	{
		last_pos = strlen(game->map_cpy[i]) - 1;
		if (game->map_cpy[i][last_pos] == '\n')
			last_pos--;
		if (game->map_cpy[i][last_pos] != WALL)
		{
			ft_printf("Error en el último carácter de la línea %d\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_map_closed(t_game *game)
{
	if (!check_first_row(game))
		return (0);
	if (!check_last_row(game))
		return (0);
	if (!check_first_column(game))
		return (0);
	if (!check_last_column(game))
		return (0);
	return (1);
}
