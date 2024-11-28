/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 01:13:17 by jorbarro          #+#    #+#             */
/*   Updated: 2024/10/29 01:56:03 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	char	buffer[11];
	int		i;

	i = 10;
	if (n == 0)
	{
		return (write(1, "0", 1));
	}
	while (n > 0)
	{
		buffer[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (write(1, &buffer[i + 1], 10 - i));
}

int	ft_puthex(unsigned int n, int is_uppercase)
{
	char	buffer[9];
	int		i;
	int		digit;

	i = 8;
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		digit = n % 16;
		if (digit < 10)
			buffer[i] = digit + '0';
		else
		{
			if (is_uppercase)
				buffer[i] = digit - 10 + 'A';
			else
				buffer[i] = digit - 10 + 'a';
		}
		n /= 16;
		i--;
	}
	return (write(1, &buffer[i + 1], 8 - i));
}

int	ft_puthex_ptr(size_t n)
{
	int	printed_chars;

	printed_chars = 0;
	if (n / 16)
		printed_chars += ft_puthex_ptr(n / 16);
	printed_chars += ft_putchar("0123456789abcdef"[n % 16]);
	return (printed_chars);
}

int	ft_putptr(void *ptr)
{
	size_t	addr;
	int		printed_chars;

	addr = (size_t)ptr;
	if (!ptr)
		return (ft_putstr("(nil)"));
	printed_chars = write(1, "0x", 2);
	printed_chars += ft_puthex_ptr(addr);
	return (printed_chars);
}
