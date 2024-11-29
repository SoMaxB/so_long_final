/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:43:37 by jorbarro          #+#    #+#             */
/*   Updated: 2024/11/28 19:43:41 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int read_map(char *map, t_game *game)
{
    int fd = open_map_file(map);
    if (fd < 0)
        return (1);

    game->control = 2;
    game->line_y = 0;
    
    int line_count = count_lines_in_map(fd);
    close(fd);
    allocate_map_memory(game, line_count);
    fd = open_map_file(map);
    read_lines_into_map(fd, game);
    close(fd);
    if (check_map_line_lengths(game))
        return (1);
    if (is_map_closed(game))
        ft_printf("El mapa está cerrado.\n");
    else
        ft_printf("El mapa no está cerrado.\n");
    check_map_shape(game);
    check_exit_and_player(game);
    check_collectibles(game);
    if (check_accessibility(game))
        return (1);
    return (0);
}
