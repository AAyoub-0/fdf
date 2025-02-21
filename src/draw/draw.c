/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:36:13 by ayoub             #+#    #+#             */
/*   Updated: 2025/02/21 17:54:34 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int	i;

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		i = (x * mlx->bpp / 8) + (y * mlx->line_len);
		mlx->addr[i] = color;
		mlx->addr[++i] = color >> 8;
		mlx->addr[++i] = color >> 16;
	}
}

static t_point2d	get_sign(t_point2d p0, t_point2d p1)
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
	t_calc_draw	calc;
	int			step;

	step = 0;
	calc.delta.x = abs(p1.x - p0.x);
	calc.delta.y = abs(p1.y - p0.y);
	calc.sign = get_sign(p0, p1);
	calc.error[0] = calc.delta.x - calc.delta.y;
	while (p0.x != p1.x || p0.y != p1.y)
	{
		ft_put_pixel(mlx, p0.x, p0.y, get_gradient_color(mlx->map, step,
				calc.delta, p3d_z));
		set_errors(&calc, &p0);
		step++;
	}
}

void	draw_line_simple(t_mlx *mlx, t_point2d p0, t_point2d p1, t_color color)
{
	t_calc_draw	calc;

	calc.delta.x = abs(p1.x - p0.x);
	calc.delta.y = abs(p1.y - p0.y);
	calc.sign = get_sign(p0, p1);
	calc.error[0] = calc.delta.x - calc.delta.y;
	while (p0.x != p1.x || p0.y != p1.y)
	{
		ft_put_pixel(mlx, p0.x, p0.y, color);
		set_errors(&calc, &p0);
	}
}

int	draw_map(t_mlx *mlx)
{
	t_point2d	i;
	t_point2d	p3d_z;

	ft_bzero(mlx->addr, SCREEN_WIDTH * SCREEN_HEIGHT * (mlx->bpp / 8));
	i.y = 0;
	while (i.y < mlx->map->height)
	{
		i.x = 0;
		while (i.x < mlx->map->width)
		{
			draw_vectors(mlx, &p3d_z, &i);
			i.x++;
		}
		i.y++;
	}
	mlx->map->need_update = false;
	return (0);
}
