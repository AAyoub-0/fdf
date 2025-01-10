/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:17:40 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/10 13:37:19 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	LINE_SIZE = 30;

void	project_pixels(t_point *p, int map_width)
{
	int	f;

	f = map_width / (2 * tan(FOV/2));
	p->x_p = (p->x * cos(R_Z) * cos(R_Y)) + (p->y * (cos(R_Z) * sin(R_X)
				* sin(R_Y) - sin(R_Z) * cos(R_X))) + (p->z * (cos(R_Z)
				* cos(R_X) * sin(R_Y) + sin(R_Z) * sin(R_X)));
	p->y_p = (p->x * sin(R_Z) * cos(R_Y)) + (p->y * (cos(R_Z) * sin(R_X)
				* sin(R_Y) + sin(R_Z) * cos(R_X))) + (p->z * (cos(R_Z)
				* cos(R_X) * sin(R_Y) - sin(R_Z) * sin(R_X)));
	p->z_p = (p->x * -sin(R_Y)) + (cos(R_Y) * sin(R_X)) + (cos(R_Y) * cos(R_X));
    p->x_pp = (p->x_p * f) / (p->z_p + 5);
    p->y_pp = (p->y_p * f) / (p->z_p + 5);
}

void    draw_line(t_point start, t_point end)
{
    
}

int	draw_map(t_mlx *mlx)
{
	t_map	map;
	t_point	point;

	map = *(mlx->map);
}
