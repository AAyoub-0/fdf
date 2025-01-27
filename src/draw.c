/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:17:40 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/27 20:36:32 by aboumall         ###   ########.fr       */
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

t_point2d **create_point2d(t_mlx *mlx)
{
    t_point2d **points2d;
    t_point **points;
    int x;
    int y;

    points2d = malloc(sizeof(t_point2d *));
    points = mlx->map->points;
    x = 0;
    int f = 50; // changer ca
    while (x < mlx->map->height)
    {
        y = 0;
        points2d[x] = malloc(sizeof(t_point2d) * mlx->map->width);
        while (y < mlx->map->width)
        {
            scale_point3d(&points[x][y], *(mlx->camera), f);
            points2d[x][y] = project_point(rotate_point(points[x][y]));
            y++;
        }
        x++;
        points2d = ft_realloc(points2d, sizeof(t_point2d *) * (x + 1));
    }
    return (points2d);
}

int	draw_map(t_mlx *mlx)
{
    t_point2d **point2d;
    
    point2d = create_point2d(mlx);
    ft_bzero(mlx->addr, SCREEN_WIDTH * SCREEN_HEIGHT * (mlx->bits_per_pixel / 8));
    
    draw_origins(mlx);
    if (mlx->map->needs_redraw)
    {
        mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
        mlx->map->needs_redraw = false;
    }
    return (0);
}
