/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:54:09 by jorbarro          #+#    #+#             */
/*   Updated: 2024/11/07 02:20:22 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//get_next_line_utils.c
void	ft_copy_str(char *dest, const char *src);
char	*ft_strappend(char *old_chain, char *block);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

//get_next_line.c
char	*ft_free(char **str);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *storage);
char	*extract_line(char *storage);
char	*update_storage(char *storage);

#endif // GET_NEXT_LINE_H
