/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:03:52 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/03 17:17:22 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void    print_map(t_map *map)
{
    int     x;
    int     y;

    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            printf("x: %d, y: %d, z: %d, color: %x\n", map->points[y][x].x, map->points[y][x].y, map->points[y][x].z, map->points[y][x].color);
            x++;
        }
        y++;
    }
}

int     main(void)
{
        t_map  *map;
        t_mlx  *mlx;
        int     fd;

        
        mlx = malloc(sizeof(t_mlx));
        fd = open("map.txt", O_RDONLY);
        map = parse_map(fd);
        init_window(mlx);
        mlx_loop(mlx->mlx);
        close(fd);
        return (0);
}