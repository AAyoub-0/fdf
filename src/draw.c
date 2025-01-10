/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:17:40 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/10 18:23:58 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	LINE_SIZE = 30;

t_point	*project_pixels(t_point *p, int map_width)
{
    t_point *point;
	int	f;
    int x_p;
    int y_p;

    point = malloc(sizeof(t_point));
    if (!point)
        return (NULL);
	f = map_width / (2 * tan(FOV/2));
	x_p = (p->x * cos(R_Z) * cos(R_Y)) + (p->y * (cos(R_Z) * sin(R_X)
				* sin(R_Y) - sin(R_Z) * cos(R_X))) + (p->z * (cos(R_Z)
				* cos(R_X) * sin(R_Y) + sin(R_Z) * sin(R_X)));
	y_p = (p->x * sin(R_Z) * cos(R_Y)) + (p->y * (cos(R_Z) * sin(R_X)
				* sin(R_Y) + sin(R_Z) * cos(R_X))) + (p->z * (cos(R_Z)
				* cos(R_X) * sin(R_Y) - sin(R_Z) * sin(R_X)));
	p->z = (p->x * -sin(R_Y)) + (cos(R_Y) * sin(R_X)) + (cos(R_Y) * cos(R_X));
    p->x = (x_p * f) / (p->z + 5);
    p->y = (y_p * f) / (p->z + 5);
    return (point);
}

int get_y(t_point start, t_point end, int x)
{
    if (end.x == start.x)
        return (start.y);
    return (start.y + ((end.y - start.y) * (x - start.x)) / (end.x - start.x));
}

void    draw_line(t_mlx **mlx, t_point *start, t_point *end)
{
    int x;
    int dx;
    int dy;
    float y;

    dx = (float)((*end)).x - (*start).x;
    dy = (float)((*end)).y - (*start).y;
    x = (*start).x;
    y = (float)(*start).y;
    while (x < (*end).x)
    {
        mlx_pixel_put((*mlx)->mlx, (*mlx)->win, x, (int)y, (*start).color);
        y += (dy / dx);
        x++;
    }
}

int	draw_map(t_mlx *mlx)
{
    t_point point;
    t_point point1;

    point.color = 0xFFFFFF;
    point.x = 100;
    point.y = 100;
    point.z = 0;
    point1.color = 0xFFFFFF;
    point1.x = 500;
    point1.y = 100;
    point1.z = 0;
    draw_line(&mlx, &point, &point1);
    return (0);
}
