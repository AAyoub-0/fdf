/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:17:40 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/26 20:21:32 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

// rotate 3d points
t_point   rotate_point(t_point p)
{
    t_point r_p;
    float x_p;
    float y_p;

    r_p.y = p.y * cos(R_X) + p.z * sin(R_X);
    r_p.z = -p.y * sin(R_X) + p.z * cos(R_X);
    
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

    p.x = (int)(r_p.x - r_p.y);
    p.y = (int)(r_p.x + r_p.z / 2 + r_p.z);
    return (p);
}

void    scale_point2d(t_point2d *p, t_camera camera, float s_f)
{
    p->x = (int)(p->x + SCREEN_WIDTH / 2 - s_f / 2);
    p->y = (int)(p->y + SCREEN_HEIGHT / 2 - s_f * 3 / 2);
}

void    scale_point3d(t_point *p, t_camera camera, float s_f)
{
    p->x = p->x * s_f;
    p->y = p->y * s_f;
    p->z = p->z * s_f * 0.25;
}

t_line_calc   init_line_calc(t_point2d p0, t_point2d p1)
{
    t_line_calc l_c;

    l_c.dx = abs(p1.x - p0.x);
    l_c.dy = abs(p1.y - p0.y);
    if (l_c.dx > l_c.dy)
        l_c.err = l_c.dx / 2;
    else
        l_c.err = -l_c.dy / 2;
    if (p0.x < p1.x)
        l_c.sx = 1;
    else
        l_c.sx = -1;
    if (p0.y < p1.y)
        l_c.sy = 1;
    else
        l_c.sy = -1;
    return (l_c);
}

void    ft_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    char *dst;

    dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

// draw lines between points
void    draw_line(t_mlx *mlx, t_point2d p0, t_point2d p1, int color)
{
    t_line_calc l_c;
    
    l_c = init_line_calc(p0, p1);
    while (1)
    {
        ft_pixel_put(mlx, p0.x, p0.y, color);
        if (p0.x == p1.x && p0.y == p1.y)
            break;
        l_c.e2 = l_c.err;
        if (l_c.e2 > -l_c.dx)
        {
            l_c.err -= l_c.dy;
            p0.x += l_c.sx;
        }
        if (l_c.e2 < l_c.dy)
        {
            l_c.err += l_c.dx;
            p0.y += l_c.sy;
        }
    }
}
void draw_circle(t_mlx *mlx, int x0, int y0, int radius, int color) {
    int x, y;

    for (y = -radius; y < radius; y++) {
        for (x = -radius; x < radius; x++) {
            if (x * x + y * y < radius * radius) {
                mlx_pixel_put(mlx->mlx, mlx->win, x0 + x, y0 + y, color);
            }
        }
    }
}

void draw_origins_name(t_mlx *mlx, int x, int y, char *name, int color)
{
    mlx_string_put(mlx->mlx, mlx->win, x, y, color, name);
}

void draw_origins(t_mlx *mlx)
{
    t_point origin = {0, 0, 0, WHITE};
    t_point x_axis = {100, 0, 0, RED};    // Axe X
    t_point y_axis = {0, 100, 0, GREEN}; // Axe Y
    t_point z_axis = {0, 0, 100, BLUE};  // Axe Z

    // Projeter les points en 2D
    t_point2d origin_2d = project_point(rotate_point(origin));
    t_point2d x_axis_2d = project_point(rotate_point(x_axis));
    t_point2d y_axis_2d = project_point(rotate_point(y_axis));
    t_point2d z_axis_2d = project_point(rotate_point(z_axis));

    // Appliquer le centrage sur l'écran
    scale_point2d(&origin_2d, *(mlx->camera), 1);
    scale_point2d(&x_axis_2d, *(mlx->camera), 1);
    scale_point2d(&y_axis_2d, *(mlx->camera), 1);
    scale_point2d(&z_axis_2d, *(mlx->camera), 1);

    // Dessiner les axes
    draw_line(mlx, origin_2d, x_axis_2d, RED);    // Ligne rouge pour X
    draw_line(mlx, origin_2d, y_axis_2d, GREEN);  // Ligne verte pour Y
    draw_line(mlx, origin_2d, z_axis_2d, BLUE);   // Ligne bleue pour Z
}


int	draw_map(t_mlx *mlx)
{
    ft_bzero(mlx->addr, SCREEN_WIDTH * SCREEN_HEIGHT * (mlx->bits_per_pixel / 8));
    t_point p1 = {0, 0, 0, WHITE};
    t_point p2 = {1, 0, 0, GREEN};
    t_point p3 = {0, 1, 0, GREEN};
    t_point p4 = {1, 1, 2, GREEN};
    t_point p5 = {0, 2, 0, GREEN};
    t_point p6 = {1, 2, 0, GREEN};
    t_point p7 = {0, 3, 0, GREEN};
    t_point p8 = {1, 3, 0, GREEN};
    t_point2d pp1;
    t_point2d pp2;
    t_point2d pp3;
    t_point2d pp4;
    t_point2d pp5;
    t_point2d pp6;
    t_point2d pp7;
    t_point2d pp8;
    float f = 50;
    scale_point3d(&p1, *(mlx->camera), f);
    scale_point3d(&p2, *(mlx->camera), f);
    scale_point3d(&p3, *(mlx->camera), f);
    scale_point3d(&p4, *(mlx->camera), f);
    scale_point3d(&p5, *(mlx->camera), f);
    scale_point3d(&p6, *(mlx->camera), f);
    scale_point3d(&p7, *(mlx->camera), f);
    scale_point3d(&p8, *(mlx->camera), f);
    p1 = rotate_point(p1);
    p2 = rotate_point(p2);
    p3 = rotate_point(p3);
    p4 = rotate_point(p4);
    p5 = rotate_point(p5);
    p6 = rotate_point(p6);
    p7 = rotate_point(p7);
    p8 = rotate_point(p8);
    pp1 = project_point(p1);
    pp2 = project_point(p2);
    pp3 = project_point(p3);
    pp4 = project_point(p4);
    pp5 = project_point(p5);
    pp6 = project_point(p6);
    pp7 = project_point(p7);
    pp8 = project_point(p8);
    scale_point2d(&pp1, *(mlx->camera), f);
    scale_point2d(&pp2, *(mlx->camera), f);
    scale_point2d(&pp3, *(mlx->camera), f);
    scale_point2d(&pp4, *(mlx->camera), f);
    scale_point2d(&pp5, *(mlx->camera), f);
    scale_point2d(&pp6, *(mlx->camera), f);
    scale_point2d(&pp7, *(mlx->camera), f);
    scale_point2d(&pp8, *(mlx->camera), f);
    draw_line(mlx, pp1, pp2, p1.color);
    draw_line(mlx, pp1, pp3, p1.color);
    draw_line(mlx, pp2, pp4, p1.color);
    draw_line(mlx, pp3, pp4, p1.color);
    draw_line(mlx, pp3, pp5, p1.color);
    draw_line(mlx, pp5, pp6, p1.color);
    draw_line(mlx, pp4, pp6, p1.color);
    draw_line(mlx, pp6, pp8, p1.color);
    draw_line(mlx, pp8, pp7, p1.color);
    draw_line(mlx, pp7, pp5, p1.color);
    draw_circle(mlx, pp1.x, pp1.y, 5, RED);
    draw_circle(mlx, pp2.x, pp2.y, 5, BLUE);
    draw_circle(mlx, pp3.x, pp3.y, 5, WHITE);
    draw_circle(mlx, pp4.x, pp4.y, 5, YELLOW);
    draw_circle(mlx, pp5.x, pp5.y, 5, CYAN);
    draw_circle(mlx, pp6.x, pp6.y, 5, MAGENTA);
    draw_circle(mlx, pp7.x, pp7.y, 5, GRAY);
    draw_circle(mlx, pp8.x, pp8.y, 5, ORANGE);
    draw_origins(mlx);
    if (mlx->map->needs_redraw)
    {
        mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
        mlx->map->needs_redraw = false;
    }
    draw_origins_name(mlx, 10, 10, "X", RED);
    draw_origins_name(mlx, 10, 30, "Y", GREEN);
    draw_origins_name(mlx, 10, 50, "Z", BLUE);
    return (0);
}
