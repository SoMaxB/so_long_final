#include "so_long.h"

int handle_close(t_mlx_data *data)
{
		ft_printf("The window has been closed.\n\n");
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        //destroy_images(data);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(0);
		return (0);
}

void	init_imgs(t_images *im)
{
    int w = im->size;
    int h = im->size;

    im->floor = mlx_xpm_file_to_image(im->mlx, "textures/floor.xpm", &w, &h);
    im->wall = mlx_xpm_file_to_image(im->mlx, "textures/wall.xpm", &w, &h);
    im->collectible = mlx_xpm_file_to_image(im->mlx, "textures/collectible.xpm", &w, &h);
    im->exit = mlx_xpm_file_to_image(im->mlx, "textures/exit.xpm", &w, &h);
    im->player = mlx_xpm_file_to_image(im->mlx, "textures/player.xpm", &w, &h);
}

int	check_images(t_images *im)
{
    if (!im->floor || !im->wall || !im->collectible || !im->exit || !im->player)
    {
        ft_printf("Error loading images\n", stderr);
        return 1;
    }
    return 0;
}


bool validate_arguments(int argc) 
{
    if (argc != 2) {
        ft_printf("El archivo no existe!\n");
        return false;
    }
    return true;
}

int open_file(char *filename) 
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo");
    }
    return fd;
}
