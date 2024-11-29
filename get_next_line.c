/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:55:16 by jorbarro          #+#    #+#             */
/*   Updated: 2024/11/15 04:50:36 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*ft_read(int fd, char *storage)
{
	char	*buffer;
	int		bytes;

	bytes = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&storage));
	buffer[0] = '\0';
	while (1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0 || (!bytes && storage && !*storage))
			return (free(buffer), ft_free(&storage));
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		storage = ft_strappend(storage, buffer);
		if (!storage)
			return (free(buffer), ft_free(&storage));
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (storage);
}

char	*extract_line(char *storage)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!storage)
		return (NULL);
	while (storage[len] && storage[len] != '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[len] == '\n')
	{
		line[len] = storage[len];
		len++;
	}
	line[len] = '\0';
	return (line);
}

char	*update_storage(char *storage)
{
	char	*new_storage;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (storage[len] && storage[len] != '\n')
		len++;
	if (!storage[len])
	{
		free(storage);
		return (NULL);
	}
	len++;
	new_storage = (char *)malloc(sizeof(char) * (ft_strlen(storage) - len + 1));
	if (!new_storage)
		return (NULL);
	while (storage[len])
		new_storage[i++] = storage[len++];
	new_storage[i] = '\0';
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_read(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	if (!line || (line[0] == '\0' && !storage))
	{
		ft_free(&storage);
		return (NULL);
	}
	if (line[0] == '\n' && !line[1])
	{
		free(line);
		return get_next_line(fd);
	}
	storage = update_storage(storage);
	if (!storage)
		ft_free(&storage);
	return (line);
}
