#include "so_long.h"

// Function to draw a single map cell
void    draw_map_cell(t_mlx_data *data, t_images *im, char cell, int screen_x, int screen_y)
{
    if (cell == '1')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, im->wall, screen_x, screen_y);
    else if (cell == 'C')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, im->collectible, screen_x, screen_y);                
    else if (cell == 'E')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, im->exit, screen_x, screen_y);
    else if (cell == 'P') {
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, im->player, screen_x, screen_y);
    } else if (cell == '0')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, im->floor, screen_x, screen_y);
}

// Function to draw the entire map
void    draw_map(t_mlx_data *data, t_images *im, char **map, int rows, int cols)
{
    int y;
    int x;

    y = 0;
    while (y < rows) 
    {
        x = 0;
        while (x < cols) 
        {
            int screen_x = x * im->size;
            int screen_y = y * im->size;
            draw_map_cell(data, im, map[y][x], screen_x, screen_y);
            if (map[y][x] == 'P') {
                data->game->player_x = x;
                data->game->player_y = y;
            }
            x++;
        }
        y++;
    }
}
