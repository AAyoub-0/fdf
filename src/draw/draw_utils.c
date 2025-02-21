/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:11:14 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/21 16:31:45 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_errors(t_calc_draw *calc, t_point2d *p0, t_point2d *p1)
{
	(*calc).error[1] = (*calc).error[0] * 2;
	if ((*calc).error[1] > -(*calc).delta.y)
	{
		(*calc).error[0] -= (*calc).delta.y;
		(*p0).x += (*calc).sign.x;
	}
	if ((*calc).error[1] < (*calc).delta.x)
	{
		(*calc).error[0] += (*calc).delta.x;
		(*p0).y += (*calc).sign.y;
	}
}

void	draw_vectors(t_mlx *mlx, t_point2d *p3d_z, t_point2d *i)
{
	t_point2d	p[2];

	p[0] = project_point3d(mlx->map->pts_3d[i->y][i->x], mlx->map,
			mlx->camera);
	p3d_z->x = mlx->map->pts_3d[i->y][i->x].z;
	if (i->x + 1 < mlx->map->width)
	{
		p[1] = project_point3d(mlx->map->pts_3d[i->y][i->x + 1], mlx->map,
				mlx->camera);
		p3d_z->y = mlx->map->pts_3d[i->y][i->x + 1].z;
		draw_line(mlx, p[0], p[1], *p3d_z);
	}
	if (i->y + 1 < mlx->map->height)
	{
		p[1] = project_point3d(mlx->map->pts_3d[i->y + 1][i->x], mlx->map,
				mlx->camera);
		p3d_z->y = mlx->map->pts_3d[i->y + 1][i->x].z;
		draw_line(mlx, p[0], p[1], *p3d_z);
	}
}
