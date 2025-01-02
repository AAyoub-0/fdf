/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:33:30 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/02 17:55:57 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_left(char *buffer, size_t size)
{
	char	*temp;
	size_t	j;

	temp = ft_calloc((BUFFER_SIZE + ft_strchr_gnl(buffer + size, '\n') + 1),
			sizeof(char));
	if (!temp)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	j = 0;
	while (buffer[size + j])
	{
		temp[j] = buffer[size + j];
		j++;
	}
	if (buffer[size + j] == '\n')
		temp[j++] = '\n';
	buffer[j] = '\0';
	free(buffer);
	return (temp);
}

char	*read_line(int fd, char *buffer, char *result, int *nb_read)
{
	while (*nb_read != 0)
	{
		*nb_read = read(fd, buffer, BUFFER_SIZE);
		if (*nb_read == -1)
		{
			free(result);
			return (NULL);
		}
		buffer[*nb_read] = '\0';
		result = ft_strjoin_gnl(buffer, result, '\n');
		if (ft_strchr(result, '\n'))
			return (result);
	}
	return (result);
}

char	*read_file(int fd, char *buffer)
{
	int		nb_read;
	char	*result;

	nb_read = -1;
	result = NULL;
	if (buffer[0] != '\0')
		result = ft_strjoin_gnl(buffer, result, '\n');
	if (ft_strchr(result, '\n'))
		return (result);
	result = read_line(fd, buffer, result, &nb_read);
	if (!result)
		return (NULL);
	if (result && result[0] != '\0' && nb_read == 0)
		return (result);
	if (buffer && buffer[0] == '\0' && nb_read == 0)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer == NULL)
		buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	line = read_file(fd, buffer);
	if (line == NULL)
	{
		free(buffer);
		buffer = NULL;
		return (line);
	}
	buffer = get_left(buffer, ft_strlen_gnl(buffer, '\n'));
	return (line);
}
