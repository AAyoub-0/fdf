/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:11:50 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/02 01:52:15 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char    *read_ligne(char *buffer, int fd)
{
        char    *line;
        char    *temp;
        int     nb_read ;

        line = ft_strdup("");
        nb_read  = 1;
        while (nb_read  != 0)
        {
                nb_read  = read(fd, buffer, 1) > 0;
                buffer[nb_read ] = '\0';
                if (buffer[0] == '\n')
                        break ;
                temp = ft_strjoin(line, buffer);
                free(line);
                line = temp;
        }
        return (ft_strtrim(line, " "));
}

int array_size(char *array)
{
    int i;
    int size;

    i = 0;
    size = 0;
    while (array[i])
    {
        if (array[i] == ' ')
            size++;   
        i++;
    }
    return (size - 1);
}