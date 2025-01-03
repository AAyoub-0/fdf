/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:17:40 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/02 23:40:15 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void    draw_line(t_mlx *mlx, t_point p1, t_point p2)
{
    int delta_x = p2.x - p1.x;
    int delta_y = p2.y - p1.y;
    int x = p1.x;
    int y = p1.y;

    if (delta_x == 0)
    {
        while (y <= p2.y)
        {
            mlx->addr[(y * mlx->line_length + x * (mlx->bits_per_pixel / 8))] = p1.color;
            y++;
        }
    }
    else if (delta_y == 0)
    {
        while (x <= p2.x)
        {
            mlx->addr[(p1.y * mlx->line_length + x * (mlx->bits_per_pixel / 8))] = p1.color;
            x++;
        }
    }
}

void    draw_line_angle(t_mlx *mlx, t_point start, double length, double angle)
{
    int end_x = start.x + (int)(length * cos(angle));
    int end_y = start.y + (int)(length * sin(angle));
    t_point end = {end_x, end_y, start.color};

    draw_line(mlx, start, end);
}

void    draw_map(t_mlx *mlx)
{
    int x;
    int y;

    y = 0;
    while (y < mlx->map->height)
    {
        x = 0;
        while (x < mlx->map->width)
        {
            if (x + 1 < mlx->map->width)
                draw_line(mlx, mlx->map->points[y][x], mlx->map->points[y][x + 1]);
            if (y + 1 < mlx->map->height)
                draw_line(mlx, mlx->map->points[y][x], mlx->map->points[y + 1][x]);
            x++;
        }
        y++;
    }
}

