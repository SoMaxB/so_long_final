/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:41:23 by jorbarro          #+#    #+#             */
/*   Updated: 2024/11/28 19:41:27 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_floodfill_path(t_game *vmap, int y, int x)
{
	if (!vmap->map_cpy[y][x] || vmap->map_cpy[y][x] == '1'
		|| vmap->map_cpy[y][x] == 'X')
		return ;
	vmap->map_cpy[y][x] = 'X';
	map_floodfill_path(vmap, y, x + 1);
	map_floodfill_path(vmap, y + 1, x);
	map_floodfill_path(vmap, y, x - 1);
	map_floodfill_path(vmap, y - 1, x);
}

int	flood_loop(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->line_y)
	{
		x = 0;
		while (x < game->line_x)
		{
			write(1, &game->map_cpy[y][x], 1);
			if (game->map_cpy[y][x] == 'C')
			{
				ft_printf("Coleccionable en (%d, %d) no es accesible\n", x, y);
				return (1);
			}
			if (game->map_cpy[y][x] == 'E')
			{
				ft_printf("Salida en (%d, %d) no es accesible\n", x, y);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_accessibility(t_game *game)
{
	int	i;

	i = -1;
	map_floodfill_path(game, game->player_y, game->player_x);
	flood_loop(game);
	while (game->map_cpy[++i])
		free(game->map_cpy[i]);
	free(game->map_cpy);
	return (0);
}
