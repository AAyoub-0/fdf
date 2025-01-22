/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:17:40 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/22 17:44:57 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

// rotate 3d points
t_point   rotate_point(t_point p)
{
    t_point r_p;
    float x_p;
    float y_p;
    
    r_p.y = p.y * cos(R_X) - p.z * sin(R_X);  
    r_p.z = p.y * sin(R_X) + p.z * cos(R_X);
    
    r_p.x = p.x * cos(R_Y) + r_p.z * sin(R_Y);
    r_p.z = -p.x * sin(R_Y) + r_p.z * cos(R_Y);
    
    x_p = r_p.x * cos(R_Z) - r_p.y * sin(R_Z);
    y_p = r_p.x * sin(R_Z) + r_p.y * cos(R_Z);
    r_p.x = x_p;
    r_p.y = y_p;
    
    r_p.color = p.color;
    return (r_p);
}

// project 3d points in 2d plan
t_point2d   project_point(t_point r_p)
{
    t_point2d p;

    if (r_p.z > 0)
    {
        p.x = (int)((r_p.x * FOV) / r_p.z);
        p.y = (int)((r_p.y * FOV) / r_p.z);
    }
    else if (r_p.z < 0)
    {
        p.x = (int)((r_p.x * FOV) / (-r_p.z));
        p.y = (int)((r_p.y * FOV) / (-r_p.z));
    }
    else
    {
        p.x = 0;
        p.y = 0;
    }
    return (p);
}

// scale 2d points
void    scale_point(t_point2d *p, float s_f)
{
    p->x = (int)(p->x * s_f + SCREEN_WIDTH / 2);
    p->y = (int)(p->y * s_f + SCREEN_HEIGHT / 2);
}

int ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

// draw lines between points
void    draw_line(t_mlx *mlx, t_point2d p0, t_point2d p1, int color)
{
    int dx;
    int dy;
    int err;
    int e2;
    int sx, sy;

    if (p0.x < p1.x)
        sx = 1;
    else
        sx = -1;
    if (p0.y < p1.y)
        sy = 1;
    else
        sy = -1;
    p0.x = p0.x;
    p0.y = p0.y;
    p1.x = p1.x;
    p1.y = p1.y;
    dx = ft_abs(p0.x - p0.x);
    dy  = ft_abs(p1.y - p0.y);
    err = dx - dy;
    
    while (true)
    {
        mlx_pixel_put(mlx->mlx, mlx->win, p0.x, p0.y, color);
        if (p0.x == p1.x && p0.y == p1.y)
            break ;
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            p0.x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            p0.y += sy;
        }
    }
}


int	draw_map(t_mlx *mlx)
{
    t_point p1 = {-10, 10, 30, 0xFFFFFF};
    t_point p2 = {-10, -10, 30, 0xFFFFFF};
    t_point p3 = {10, 10, 30, 0xFFFFFF};
    t_point p4 = {10, -10, 30, 0xFFFFFF};
    t_point p5 = {-10, 10, -30, 0xFFFFFF};
    t_point p6 = {-10, -10, -30, 0xFFFFFF};
    t_point p7 = {10, 10, -30, 0xFFFFFF};
    t_point p8 = {10, -10, -30, 0xFFFFFF};
    t_point2d pp1;
    t_point2d pp2;
    t_point2d pp3;
    t_point2d pp4;
    t_point2d pp5;
    t_point2d pp6;
    t_point2d pp7;
    t_point2d pp8;
    pp1 = project_point(rotate_point(p1));
    pp2 = project_point(rotate_point(p2));
    pp3 = project_point(rotate_point(p3));
    pp4 = project_point(rotate_point(p4));
    pp5 = project_point(rotate_point(p5));
    pp6 = project_point(rotate_point(p6));
    pp7 = project_point(rotate_point(p7));
    pp8 = project_point(rotate_point(p8));
    float f = 3.5;
    scale_point(&pp1, f);
    scale_point(&pp2, f);
    scale_point(&pp3, f);
    scale_point(&pp4, f);
    scale_point(&pp5, f);
    scale_point(&pp6, f);
    scale_point(&pp7, f);
    scale_point(&pp8, f);
    draw_line(mlx, pp1, pp2, p1.color);
    draw_line(mlx, pp1, pp3, p1.color);
    mlx_pixel_put(mlx->mlx, mlx->win, pp1.x, pp1.y, 0xFF0000);
    // mlx_pixel_put(mlx->mlx, mlx->win, pp2.x, pp2.y, 0xFF0000);
    mlx_pixel_put(mlx->mlx, mlx->win, pp3.x, pp3.y, 0xFF0000);
    // mlx_pixel_put(mlx->mlx, mlx->win, pp4.x, pp4.y, 0xFF0000);
    // mlx_pixel_put(mlx->mlx, mlx->win, pp5.x, pp5.y, 0xFF0000);
    // mlx_pixel_put(mlx->mlx, mlx->win, pp6.x, pp6.y, 0xFF0000);
    // mlx_pixel_put(mlx->mlx, mlx->win, pp7.x, pp7.y, 0xFF0000);
    // mlx_pixel_put(mlx->mlx, mlx->win, pp8.x, pp8.y, 0xFF0000);
    // t_point2d pt = {0, 0};
    // t_point2d pt1 = {20, 0};
    // scale_point(&pt, 3.5);
    // scale_point(&pt1, 3.5);
    // draw_line(mlx, pt, pt1, p1.color);
    return (0);
}
