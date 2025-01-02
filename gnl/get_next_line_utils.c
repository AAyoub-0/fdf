/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:33:23 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/02 17:56:10 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str, char c)
{
	size_t	size;

	size = 0;
	if (str == NULL)
		return (0);
	while (str[size] != '\0' && str[size] != c)
		size++;
	if (str[size] != '\0' && str[size] == c)
		size++;
	return (size);
}

int	ft_strchr_gnl(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		return (1);
	return (0);
}

void	join_str(char *temp, char *buffer, char *result, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (result && result[i])
	{
		temp[i] = result[i];
		i++;
	}
	while (buffer[j] && buffer[j] != c)
	{
		temp[i + j] = buffer[j];
		j++;
	}
	if (buffer[j] == c)
		temp[i + j] = c;
}

char	*ft_strjoin_gnl(char *buffer, char *result, char c)
{
	char	*temp;
	size_t	size;

	size = ft_strlen_gnl(buffer, '\n') + ft_strlen_gnl(result, '\0') + 1;
	temp = (char *)ft_calloc(size, sizeof(char));
	if (!temp)
	{
		free(result);
		return (NULL);
	}
	join_str(temp, buffer, result, c);
	free(result);
	return (temp);
}
