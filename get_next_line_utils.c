/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:49:50 by jorbarro          #+#    #+#             */
/*   Updated: 2024/11/15 04:22:37 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_copy_str(char *dest, const char *src)
{
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
}

char	*ft_strappend(char *old_chain, char *block)
{
	char	*new_chain;
	int		len_old;
	int		len_block;

	len_old = 0;
	if (!block)
		return (NULL);
	if (old_chain)
		len_old = ft_strlen(old_chain);
	len_block = ft_strlen(block);
	new_chain = (char *)malloc(sizeof(char) * (len_old + len_block + 1));
	if (!new_chain)
		return (NULL);
	if (old_chain)
		ft_copy_str(new_chain, old_chain);
	ft_copy_str(new_chain + len_old, block);
	if (old_chain)
		free(old_chain);
	return (new_chain);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
