/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:36:13 by ayoub             #+#    #+#             */
/*   Updated: 2025/01/30 23:06:18 by ayoub            ###   ########.fr       */
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

void	draw_line(t_mlx *mlx, t_point2d p0, t_point2d p1)
{
	t_point2d	delta;
	t_point2d	sign;
	int			error[2];

	delta.x = abs(p1.x - p0.x);
	delta.y = abs(p1.y - p0.y);
	sign.x = p0.x < p1.x ? 1 : -1;
	sign.y = p0.y < p1.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	while (p0.x != p1.x || p0.y != p1.y)
	{
		ft_put_pixel(mlx, p0.x, p0.y, 0xFFFFFF);
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
