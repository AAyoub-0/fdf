/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:03:52 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/08 19:35:29 by aboumall         ###   ########.fr       */
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

int	draw_pixels(t_mlx *mlx)
{
	mlx_pixel_put(mlx->mlx, mlx->win, 10, 10, 0xFFFFFF);
	mlx_pixel_put(mlx->mlx, mlx->win, 10, 11, 0xFFFFFF);
	mlx_pixel_put(mlx->mlx, mlx->win, 10, 12, 0xFFFFFF);
	return (0);
}

int     main(void)
{
        t_map  *map;
        t_mlx  *mlx;
        int     fd;

        fd = open("map.txt", O_RDONLY);
        init_window(&mlx, fd);
        mlx_loop_hook(mlx->mlx, &handle_no_event, &mlx);
        mlx_hook(mlx->win, KEYDOWN, KEYDOWN_MASK, &handle_keydown, &mlx);
        mlx_hook(mlx->win, KEYUP, KEYUP_MASK, &handle_keyup, &mlx);
        mlx_hook(mlx->win, DESTROY, 0, &handle_destroy, &mlx);
        mlx_loop_hook(mlx->mlx, &draw_map, mlx);
        mlx_loop(mlx->mlx);
        mlx_clear_window(mlx->mlx, mlx->win);
        close(fd);
        return (0);
}