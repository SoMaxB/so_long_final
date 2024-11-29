/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:43:19 by jorbarro          #+#    #+#             */
/*   Updated: 2024/11/28 19:43:22 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

int open_map_file(char *map)
{
    int fd = open(map, O_RDONLY);
    if (fd < 0)
    {
        perror("Error al abrir el archivo");
        return (-1); // Retornar -1 en caso de error
    }
    return (fd);
}

int count_lines_in_map(int fd)
{
    char *line;
    int count = 0;

    line = get_next_line(fd);
    while (line)
    {
        count++;
        free(line);
        line = get_next_line(fd);
    }
    return (count);
}

void allocate_map_memory(t_game *game, int line_count)
{
    game->map = malloc(sizeof(char *) * (line_count + 1)); // +1 para el NULL
    game->map_cpy = malloc(sizeof(char *) * (line_count + 1)); // +1 para el NULL
}

void read_lines_into_map(int fd, t_game *game)
{
    char *line;
    int i = 0;

    line = get_next_line(fd);
    while (line)
    {
        game->map[i] = ft_strdup(line);
        game->map_cpy[i] = ft_strdup(line);
        free(line);
        i++;
        line = get_next_line(fd);
    }
    game->line_y = i;
    game->map[i] = NULL; // Asegúrate de agregar el NULL al final
    game->map_cpy[i] = NULL; // Asegúrate de agregar el NULL al final
}

int check_map_line_lengths(t_game *game)
{
    int expected_length = ft_strlen(game->map[0]);
    int i = 0;
    while (game->map[i])
    {
        if ((int)ft_strlen(game->map[i]) != expected_length)
            return (write(1, "lineas dispares\n", 16), 1);
        i++;
    }
    game->line_x = expected_length; // Establecer line_x aquí
    return (0);
}
