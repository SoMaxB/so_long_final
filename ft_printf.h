/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:03:53 by jorbarro          #+#    #+#             */
/*   Updated: 2024/10/29 01:43:00 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>                              
# include <stdlib.h>                             
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

//Functions//
int	ft_printf(const char *mystr, ...);
int	var_type(char c, va_list args);
int	ft_putnbr(int n);
int	ft_putunsigned(unsigned int n);
int	ft_putstr(char *s);
int	ft_puthex(unsigned int n, int is_uppercase);
int	ft_putchar(int c);
int	ft_putptr(void *ptr);

#endif
