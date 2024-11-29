/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:40:45 by jorbarro          #+#    #+#             */
/*   Updated: 2024/11/28 19:40:55 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	p_image(t_draw_params *pars, void *image, int screen_x, int screen_y)
{
	mlx_put_image_to_window
	(
		pars->mlx_ptr,
		pars->win_ptr,
		image,
		screen_x,
		screen_y
	);
}

void	cells(t_draw_params *pars, char cell, int screen_x, int screen_y)
{
	if (cell == '1')
		p_image(pars, pars->im->wall, screen_x, screen_y);
	else if (cell == 'C')
		p_image(pars, pars->im->coll, screen_x, screen_y);
	else if (cell == 'E')
		p_image(pars, pars->im->exit, screen_x, screen_y);
	else if (cell == 'P')
		p_image(pars, pars->im->player, screen_x, screen_y);
	else if (cell == '0')
		p_image(pars, pars->im->floor, screen_x, screen_y);
}

void	process_cell(t_draw_params *pars, char cell, int x, int y)
{
	int	screen_x;
	int	screen_y;

	screen_x = x * pars->im->size;
	screen_y = y * pars->im->size;
	cells(pars, cell, screen_x, screen_y);
}

void	draw_map(t_mlx_data *data, t_images *im, char **map, int rows)
{
	int				y;
	int				x;
	t_draw_params	pars;

	pars.mlx_ptr = data->mlx_ptr;
	pars.win_ptr = data->win_ptr;
	pars.im = im;
	y = 0;
	while (y < rows)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			process_cell(&pars, map[y][x], x, y);
			if (map[y][x] == 'P')
			{
				data->game->player_x = x;
				data->game->player_y = y;
			}
			x++;
		}
		y++;
	}
}
