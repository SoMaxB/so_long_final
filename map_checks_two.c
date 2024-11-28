#include "so_long.h"


int     check_map_shape(t_game *game)
{
    ft_printf("Verificando forma del mapa: line_y = %d, line_x = %d\n", game->line_y, game->line_x);
    if (game->line_y == 0) 
    {
        ft_printf("Error: El mapa no tiene líneas.\n");
        return (0);
    }
    if (game->line_x == game->line_y) 
    {
        ft_printf("El mapa es cuadrado.\n");
        return (1); // Mapa cuadrado
    } 
    else 
    {
        ft_printf("El mapa es rectangular.\n");
        return (1); // Mapa rectangular
    }
}

// Function to count exits and player positions
void count_exits_and_players(t_game *game, int *count_e, int *count_p)
{
    *count_e = 0;
    *count_p = 0;

    int i = 0;
    while (i < game->line_y) {
        int j = 0;
        while (j < game->line_x) {
            char current_char = game->map_cpy[i][j];
            if (current_char == EXIT)
                (*count_e)++;
            else if (current_char == INITIAL_POS) {
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
void check_exit_and_player(t_game *game)
{
    int count_e, count_p;
    count_exits_and_players(game, &count_e, &count_p);

    if (count_e != 1) {
        ft_printf("Error: Debe haber exactamente una 'E' (salida). Encontradas: %d\n", count_e);
        exit(EXIT_FAILURE); // Cerrar el programa
    }
    if (count_p != 1) {
        ft_printf("Error: Debe haber exactamente una 'P' (posicion inicial). Encontradas: %d\n", count_p);
        exit(EXIT_FAILURE); // Cerrar el programa
    }
    ft_printf("Hay %i salidas y %i posiciones inicial.\n", count_e, count_p);
}

void    check_collectibles(t_game *game)
{
    int i = 0;
    while (i < game->line_y) 
    {
        int j = 0;
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
        ft_printf("Error: Debe haber al menos una 'C' (coleccionable). Encontradas: %d\n", game->collectibles);
        exit(EXIT_FAILURE); // Cerrar el programa
    } 
    else
        ft_printf("Número de coleccionables 'C' encontrados: %d\n", game->collectibles);
}

void    check_break(char *line, t_game *game)
{
    int i;                                                                      
                                                                                 
    i = 0;                                                                      
    game->control = 1;                                                  
    while (line[i])                                                             
    {                                                                           
        if (line[i] == '\n')                                                    
            game->control = 0;                                          
        i++;                                                                    
    }                                                                           
} 
