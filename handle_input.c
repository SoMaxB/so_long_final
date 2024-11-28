#include "so_long.h"

void handle_w(int keysym, t_mlx_data *data)
{
    int new_x = data->game->player_x; // Usa la referencia
    int new_y = data->game->player_y;

    if (keysym == W)
    {
        if (new_y > 0) // Verificar límite superior
        {
            new_y--; // Mover hacia arriba
            if (data->game->map[new_y][new_x] != '1') // Verifica si no hay pared
            {
                if (data->game->map[new_y][new_x] == COLLECTIBLE) // Verificar si es un coleccionable
                {
                    data->game->collectibles--; // Descontar coleccionable
                    ft_printf("¡Coleccionable recogido! Quedan %d coleccionables.\n", data->game->collectibles);
                }
                move_player(data, new_x, new_y); // Llama a move_player
            }
        }
    }
}
void handle_s(int keysym, t_mlx_data *data)
{
    int new_x = data->game->player_x; // Usa la referencia
    int new_y = data->game->player_y;

    if (keysym == S)
    {
        if (new_y < data->game->line_y - 1) // Verificar límite inferior
        {
            new_y++; // Mover hacia abajo
            if (data->game->map[new_y][new_x] != '1') // Verifica si no hay pared
            {
                if (data->game->map[new_y][new_x] == COLLECTIBLE) // Verificar si es un coleccionable
                {
                    data->game->collectibles--; // Descontar coleccionable
                    ft_printf("¡Coleccionable recogido! Quedan %d coleccionables.\n", data->game->collectibles);
                }
                move_player(data, new_x, new_y); // Llama a move_player
            }
        }
    }
}
void handle_a(int keysym, t_mlx_data *data)
{
    int new_x = data->game->player_x; // Usa la referencia
    int new_y = data->game->player_y;

    if (keysym == A)
    {
        if (new_x > 0) // Verificar límite izquierdo
        {
            new_x--; // Mover hacia la izquierda
            if (data->game->map[new_y][new_x] != '1') // Verifica si no hay pared
            {
                if (data->game->map[new_y][new_x] == COLLECTIBLE) // Verificar si es un coleccionable
                {
                    data->game->collectibles--; // Descontar coleccionable
                    ft_printf("¡Coleccionable recogido! Quedan %d coleccionables.\n", data->game->collectibles);
                }
                move_player(data, new_x, new_y); // Llama a move_player
            }
        }
    }
}
void handle_d(int keysym, t_mlx_data *data)
{
    int new_x = data->game->player_x; // Usa la referencia
    int new_y = data->game->player_y;

    if (keysym == D)
    {
        if (new_x < data->game->line_x - 1) // Verificar límite derecho
        {
            new_x++; // Mover hacia la derecha
            if (data->game->map[new_y][new_x] != '1') // Verifica si no hay pared
            {
                if (data->game->map[new_y][new_x] == COLLECTIBLE) // Verificar si es un coleccionable
                {
                    data->game->collectibles--; // Descontar coleccionable
                    ft_printf("¡Coleccionable recogido! Quedan %d coleccionables.\n", data->game->collectibles);
                }
                move_player(data, new_x, new_y); // Llama a move _player
            }
        }
    }
}
int handle_input(int keysym, t_mlx_data *data)
{
    //int new_x = data->game->player_x; // Usa la referencia
    //int new_y = data->game->player_y;

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
    // Verificar si se han recogido todos los coleccionables
    if (data->game->collectibles == 0)
    {
        ft_printf("¡Todos los coleccionables han sido recogidos! La salida está activa.\n");
        // Aquí puedes activar la lógica para permitir la salida
    }
    return (0);
}
