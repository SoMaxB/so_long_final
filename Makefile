# Nombre del ejecutable
NAME = so_long

# Archivos fuente
SRC = 	main.c \
		map_checks_one.c \
		map_checks_two.c \
		movements.c \
		get_next_line.c \
		get_next_line_utils.c \
		floodfill.c \
		handle_input.c \
		draw_map.c \
		pre_read_map.c \
		read_map.c \
		main_func_one.c \
		main_func_two.c \
		ft_printf.c \
		ft_printf_alpha.c \
		ft_printf_nums.c \
		ft_strdup.c \

# Archivos objeto (cada archivo .c genera un archivo .o)
OBJ = $(SRC:.c=.o)

# Opciones de compilación
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address #eliminar g3 y fsanitize antes del push final.

# Opciones de enlace
LDFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

# Regla principal: compilar ejecutable
all: $(NAME) # Cómo generar el ejecutable
$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

# Regla para generar archivos objeto
%.o: %.c
	cc $(CFLAGS) -c $< -o $@

# Limpiar archivos objeto y ejecutable
clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

# Volver a compilar desde cero
re: fclean all

# Decir que estas reglas no son archivos
.PHONY: all clean fclean re
