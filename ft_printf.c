/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:41:51 by jorbarro          #+#    #+#             */
/*   Updated: 2024/10/29 02:10:59 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n);

int	ft_printf(const char *mystr, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start (args, mystr);
	while (mystr[i] != '\0')
	{
		if (mystr[i] == '%')
		{
			i++;
			length += var_type(mystr[i], args);
			i++;
		}
		else
		{
			write (1, &mystr[i], 1);
			i++;
			length++;
		}
	}
	va_end (args);
	return (length);
}

int	var_type(char c, va_list args)
{
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	if (c == 'p')
		return (ft_putptr(va_arg(args, unsigned long *)));
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

static int	int_min(int n)
{
	(void)n;
	if (write(1, "-2147483648", 11) != 11)
		return (-1);
	return (11);
}

int	ft_putnbr(int n)
{
	int	let;

	let = 0;
	if (n == -2147483648)
		return (int_min(n));
	if (n < 0 && ++let)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		n = -n;
	}
	if (n > 9)
	{
		let += ft_putnbr(n / 10);
		if (let == -1)
			return (-1);
		n = n % 10;
	}
	if (n <= 9)
	{
		if (ft_putchar (('0' + n)) == -1)
			return (-1);
		let++;
	}
	return (let);
}

/*int main()
{
    int entero = 985632;
    char caracter = 'B';
    char *cadena = NULL;
    char *cadena_larga = "Este es un string largo";
    char *cadena_vacia = "";
    void *puntero = &entero;
    void *puntero_null = NULL;
    int num_negativo = -42;
    int int_max = 2147483647;
    int int_min = -2147483648;
    unsigned int uint_max = 4294967295;

    int original_ret, mi_ret;
    //PRUEBA DE CARACTERES
    printf("%s\n", "Prueba de impresión de caracteres");
    printf("Original printf:\n");
    original_ret = printf("Caracter: %c\n", caracter);
    printf("Return: %d\n", original_ret);
    original_ret = printf("%c\n", caracter);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Caracter: %c\n", caracter);
    printf("Return: %d\n", mi_ret);
    mi_ret = ft_printf("%c\n", caracter);
    printf("Return: %d\n\n", mi_ret);
    
    //PRUEBA CON CADENAS
    printf("%s\n", "Prueba de impresión de cadenas");
    printf("Original printf:\n");
    original_ret = printf("Cadena: %s\n", cadena);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Cadena: %s\n", cadena);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA CON CADENAS LARGAS
    printf("%s\n", "Prueba de impresión de cadenas largas");
    printf("Original printf:\n");
    original_ret = printf("Cadena larga: %s\n", cadena_larga);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Cadena larga: %s\n", cadena_larga);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA DE CADENAS VACIAS
    printf("%s\n", "Prueba de impresión de cadenas vacías");
    printf("Original printf:\n");
    original_ret = printf("Cadena vacía: %s\n", cadena_vacia);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Cadena vacía: %s\n", cadena_vacia);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA DE PUNTEROS
    printf("%s\n", "Prueba de impresión de punteros");
    printf("Original printf:\n");
    original_ret = printf("Puntero: %p\n", puntero);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Puntero: %p\n", puntero);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA DE PUNTERO NULL
    printf("%s\n", "Prueba de impresión de puntero NULL");
    printf("Original printf:\n");
    original_ret = printf("Puntero NULL: %p\n", puntero_null);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Puntero NULL: %p\n", puntero_null);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA NUMEROS DECIMALES
    printf("%s\n", "Prueba de impresión de números decimales (base 10)");
    printf("Original printf:\n");
    original_ret = printf("Entero: %d\n", entero);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Entero: %d\n", entero);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA ENTEROS
    printf("%s\n", "Prueba de impresión de enteros (base 10)");
    printf("Original printf:\n");
    original_ret = printf("Entero: %i\n", entero);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Entero: %i\n", entero);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA DECIMALES LARGOS
    printf("%s\n", "Prueba de impresión de números decimales negativos");
    printf("Original printf:\n");
    original_ret = printf("Número negativo: %d\n", num_negativo);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Número negativo: %d\n", num_negativo);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA NUMEROS SIN SIGNO
    printf("%s\n", "Prueba de impresión de números sin signo (base 10)");
    printf("Original printf:\n");
    original_ret = printf("Unsigned Entero: %u\n", uint_max);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Unsigned Entero: %u\n", uint_max);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA INT MAX, INT MIN UINT MAX
    printf("%s\n", "Prueba de impresión de enteros máximos y mínimos");
    printf("Original printf:\n");
    original_ret = printf("Entero máximo: %d\n", int_max);
    printf("Return: %d\n", original_ret);
    original_ret = printf("Entero mínimo: %d\n", int_min);
    printf("Return: %d\n", original_ret);
    original_ret = printf("Unsigned Entero máximo: %u\n", uint_max);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Entero máximo: %d\n", int_max);
    printf("Return: %d\n", mi_ret);
    mi_ret = ft_printf("Entero mínimo: %d\n", int_min);
    printf("Return: %d\n", mi_ret);
    mi_ret = ft_printf("Unsigned Entero máximo: %u\n", uint_max);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA HEXADECIMALES MINUSCULA
    printf("%s\n", "Prueba de impresión de números hexadecimales en minúsculas");
    printf("Original printf:\n");
    original_ret = printf("Hexadecimal (minúsculas): %x\n", entero);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Hexadecimal (minúsculas): %x\n", entero);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA HEXADECIMALES MAYUSCULA
    printf("%s\n", "Prueba de impresión de números hexadecimales en mayúsculas");
    printf("Original printf:\n");
    original_ret = printf("Hexadecimal (mayúsculas): %X\n", entero);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Hexadecimal (mayúsculas): %X\n", entero);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA HEXADECIMALES 0
    printf("%s\n", "Prueba de impresión de números hexadecimales para 0");
    printf("Original printf:\n");original_ret = 
    printf("Hexadecimal (mayúsculas): %X\nHexadecimal (minusculas): %x\n", 0, 0);
    printf("Return: %d\n", original_ret);
    printf("Mi ft_printf:\n");mi_ret =
 ft_printf("Hexadecimal (mayúsculas): %X\nHexadecimal (minusculas): %x\n", 0, 0);
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA PORCENTAJE
    printf("%s\n", "Prueba de impresión de porcentaje");
    printf("Original printf:\n");
    original_ret = printf("Porcentaje: %%\n");
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Porcentaje: %%\n");
    printf("Return: %d\n\n", mi_ret);

    //PRUEBA MULTIPLES PARAMETROS
    printf("%s\n", "Prueba de impresión de multiples parametros");
    printf("Original printf:\n");
    original_ret = printf("Hola mi nombre es %s, tengo %d años, 
estudio en %s y este es mi printf:\n", "Max", 44, "42 Madrid")
    ;printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Hola mi nombre es %s, tengo %d años, 
estudio en %s y este es mi printf:\n", "Max", 44, "42 Madrid");
     printf("Return: %d\n\n", mi_ret);

    return 0;
}*/
