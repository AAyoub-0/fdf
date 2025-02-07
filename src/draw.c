/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:36:13 by ayoub             #+#    #+#             */
/*   Updated: 2025/02/07 14:28:18 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		i = (x * mlx->bpp / 8) + (y * mlx->line_len);
		mlx->addr[i] = color;
		mlx->addr[++i] = color >> 8;
		mlx->addr[++i] = color >> 16;
	}
}

static t_point2d get_sign(t_point2d p0, t_point2d p1)
{
	t_point2d	sign;

	if (p0.x < p1.x)
		sign.x = 1;
	else
		sign.x = -1;
	if (p0.y < p1.y)
		sign.y = 1;
	else
		sign.y = -1;
	return (sign);
}

void	draw_line(t_mlx *mlx, t_point2d p0, t_point2d p1, t_point2d p3d_z)
{
	t_point2d	delta;
	t_point2d	sign;
	int			error[2];
    int step = 0;
	
	delta.x = abs(p1.x - p0.x);
	delta.y = abs(p1.y - p0.y);
	sign = get_sign(p0, p1);
	error[0] = delta.x - delta.y;
	while (p0.x != p1.x || p0.y != p1.y)
	{
		ft_put_pixel(mlx, p0.x, p0.y, get_gradient_color(mlx->map, step, delta, p3d_z));
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			p0.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			p0.y += sign.y;
		}
		step++;
	}
}

void	draw_line_simple(t_mlx *mlx, t_point2d p0, t_point2d p1, t_color color)
{
	t_point2d	delta;
	t_point2d	sign;
	int			error[2];
	
	delta.x = abs(p1.x - p0.x);
	delta.y = abs(p1.y - p0.y);
	sign = get_sign(p0, p1);
	error[0] = delta.x - delta.y;
	while (p0.x != p1.x || p0.y != p1.y)
	{
		ft_put_pixel(mlx, p0.x, p0.y, color);
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			p0.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			p0.y += sign.y;
		}
	}
}

int	draw_map(t_mlx *mlx)
{	
	t_point2d	i;
	t_point2d	p[2];
	t_point2d	p3d_z;

	ft_bzero(mlx->addr, SCREEN_WIDTH * SCREEN_HEIGHT * (mlx->bpp / 8));
	i.y = 0;
	while (i.y < mlx->map->height)
	{
		i.x = 0;
		while (i.x < mlx->map->width)
		{
			p[0] = project_point3d(mlx->map->pts_3d[i.y][i.x], mlx->map, mlx->camera);
			p3d_z.x = mlx->map->pts_3d[i.y][i.x].z;
			if (i.x + 1 < mlx->map->width)
			{
				p[1] = project_point3d(mlx->map->pts_3d[i.y][i.x + 1], mlx->map, mlx->camera);
				p3d_z.y = mlx->map->pts_3d[i.y][i.x + 1].z;
				draw_line(mlx, p[0], p[1], p3d_z);
			}
			if (i.y + 1 < mlx->map->height)
			{
				p[1] = project_point3d(mlx->map->pts_3d[i.y + 1][i.x], mlx->map, mlx->camera);
				p3d_z.y = mlx->map->pts_3d[i.y + 1][i.x].z;
				draw_line(mlx, p[0], p[1], p3d_z);
			}
			i.x++;
		}
		i.y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx->map->need_update = false;
	return (0);
}
