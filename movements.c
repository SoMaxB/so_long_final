#include "so_long.h"

void check_boundaries(t_mlx_data *data, int new_x, int new_y)
{
    if (new_x < 0 || new_x >= data->game->line_x || new_y < 0 || new_y >= data->game->line_y)
    {
        ft_printf("Movimiento fuera de límites.\n");
        return ;
    }
}

/*void collect_item(t_mlx_data *data, int new_x, int new_y)
{
    if (data->game->map[new_y][new_x] == COLLECTIBLE) 
    {
        ft_printf("Recogiendo un coleccionable!\n");
        //data->game->collectibles--;
    }
}*/

bool handle_exit(t_mlx_data *data, int new_x, int new_y)
{
    if (data->game->map[new_y][new_x] == 'E') {
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

void move_player_to_new_position(t_mlx_data *data, int new_x, int new_y, int current_x, int current_y)
{
    if (data->game->map[new_y][new_x] != '1' && data->game->map[new_y][new_x] != 'E') 
    {
        data->game->map[current_y][current_x] = '0';
        data->game->map[new_y][new_x] = 'P';
        data->game->player_x = new_x;
        data->game->player_y = new_y;
        data->game->moves++;
        ft_printf("Movimiento exitoso. Llevas %d movimientos\n", data->game->moves);
        draw_map(data, data->game->im, data->game->map, data->game->line_y, data->game->line_x);
    } 
    else 
    {
        ft_printf("Movimiento bloqueado por una pared o una salida no permitida.\n");
    }
}

void move_player(t_mlx_data *data, int new_x, int new_y)
{
    int current_x = data->game->player_x;
    int current_y = data->game->player_y;

    ft_printf("Intentando mover a X: %d, Y: %d\n", new_x, new_y);

    check_boundaries(data, new_x, new_y);
    if (handle_exit(data, new_x, new_y)) 
        return ;
    //collect_item(data, new_x, new_y);
    move_player_to_new_position(data, new_x, new_y, current_x, current_y);
}
