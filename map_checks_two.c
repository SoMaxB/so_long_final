/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:42:52 by jorbarro          #+#    #+#             */
/*   Updated: 2024/11/28 19:42:55 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_shape(t_game *game)
{
	if (game->line_y == 0)
	{
		ft_printf("Error: El mapa no tiene líneas.\n");
		return (0);
	}
	if (game->line_x == game->line_y)
	{
		ft_printf("El mapa es cuadrado.\n");
		return (1);
	}
	else
	{
		ft_printf("El mapa es rectangular.\n");
		return (1);
	}
}

// Function to count exits and player positions
void	count_exits_and_players(t_game *game, int *count_e, int *count_p)
{
	int		i;
	int		j;
	char	current_char;

	*count_e = 0;
	*count_p = 0;
	i = 0;
	while (i < game->line_y)
	{
		j = 0;
		while (j < game->line_x)
		{
			current_char = game->map_cpy[i][j];
			if (current_char == EXIT)
				(*count_e)++;
			else if (current_char == INITIAL_POS)
			{
				game->player_x = j;
				game->player_y = i;
				(*count_p)++;
			}
			j++;
		}
		i++;
	}
}

// Function to check exits and player positions
void	check_exit_and_player(t_game *game)
{
	int	count_e;
	int	count_p;

	count_exits_and_players(game, &count_e, &count_p);
	if (count_e != 1)
	{
		ft_printf("Error: Debe haber solo una 'E'. Encontradas: %d\n", count_e);
		exit(EXIT_FAILURE);
	}
	if (count_p != 1)
	{
		ft_printf("Error: Debe haber solo una 'P'. Encontradas: %d\n", count_p);
		exit(EXIT_FAILURE);
	}
	ft_printf("Hay %i salidas y %i posiciones inicial.\n", count_e, count_p);
}

void	check_collectibles(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->line_y)
	{
		j = 0;
		while (j < game->line_x)
		{
			if (game->map_cpy[i][j] == COLLECTIBLE)
				game->collectibles++;
			j++;
		}
		i++;
	}
	if (game->collectibles < 1)
	{
		ft_printf("Error: Debe haber al menos una 'C'");
		exit(EXIT_FAILURE);
	}
	else
		ft_printf("Número de 'C' encontrados: %d\n", game->collectibles);
}

void	check_break(char *line, t_game *game)
{
	int	i;

	i = 0;
	game->control = 1;
	while (line[i])
	{
		if (line[i] == '\n')
			game->control = 0;
		i++;
	}
}
