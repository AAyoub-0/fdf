/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:03:52 by aboumall          #+#    #+#             */
/*   Updated: 2024/12/18 16:14:50 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

int     main(void)
{
        int     i = 0;
        int     j = 0;
        char    *buffer;
        char    **map;
        int fd = open("test.txt", O_RDONLY);
        read(fd, buffer, 1024);
        
        map = calloc(11, sizeof(char **));
        while (j < 11)
        {
                map[j] = calloc(20, sizeof(char *));
                j++;
        }
        j = 0;
        while (buffer[i])
        {
                if (buffer[i] == ' ')
                {
                        i++;
                        continue ;       
                }
                map[j][i] = buffer[i];
                i++;
                if (buffer[i] == '\n')
                {
                        i = 0;
                        j++;
                }
        }
        close(fd);
        free(buffer);
        return (0);
}