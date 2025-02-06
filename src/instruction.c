/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:06:07 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/05 19:13:17 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	init_instructions(t_mlx *mlx)
{
	mlx->ins = ft_calloc(8, sizeof(t_frame *));
	mlx->ins[1] = init_frame((t_point2d){0, 0}, SCREEN_WIDTH * 0.23, SCREEN_HEIGHT,
			WHITE);
	mlx->ins[1]->class = ft_strdup("body");
	mlx->ins[2] = init_frame((t_point2d){20, 20}, 120, 45, RED);
	mlx->ins[2]->class = ft_strdup("vue-de-face");
	mlx->ins[3] = init_frame((t_point2d){155, 20}, 120, 45, RED);
	mlx->ins[3]->class = ft_strdup("vue-de-droite");
	mlx->ins[4] = init_frame((t_point2d){290, 20}, 120, 45, RED);
	mlx->ins[4]->class = ft_strdup("vue-de-gauche");
	mlx->ins[5] = init_frame((t_point2d){20, 80}, 120, 45, RED);
	mlx->ins[5]->class = ft_strdup("vue-de-dessous");
	mlx->ins[6] = init_frame((t_point2d){155, 80}, 120, 45, RED);
	mlx->ins[6]->class = ft_strdup("vue-de-dessus");
}

void	draw_menu_icon(t_mlx *mlx)
{
	t_point2d	p0[2];
	t_point2d	p1[2];
	t_point2d	p2[2];
	
	p0[0].x = 10;
	p0[1].x = 40;
	p1[0].x = 10;
	p1[1].x = 40;
	p2[0].x = 10;
	p2[1].x = 40;
	p0[0].y = 10;
	p0[1].y = 10;
	p1[0].y = 15;
	p1[1].y = 15;
	p2[0].y = 20;
	p2[1].y = 20;
	mlx->ins[0] = init_frame((t_point2d){10, 10}, 30, 30, WHITE);
	mlx->ins[0]->class = ft_strdup("menu");
	draw_line_simple(mlx, p0[0], p0[1], WHITE);
	draw_line_simple(mlx, p1[0], p1[1], WHITE);
	draw_line_simple(mlx, p2[0], p2[1], WHITE);
}

void	draw_instructions(t_mlx *mlx)
{
	ft_bzero(mlx->addr, SCREEN_WIDTH * SCREEN_HEIGHT * (mlx->bpp / 8));
	if (!mlx->show_ins)
	{
		draw_menu_icon(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
		return ;
	}
	draw_frame(mlx, mlx->ins[1]);
	draw_frame(mlx, mlx->ins[2]);
	draw_frame(mlx, mlx->ins[3]);
	draw_frame(mlx, mlx->ins[4]);
	draw_frame(mlx, mlx->ins[5]);
	draw_frame(mlx, mlx->ins[6]);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_string_put(mlx->mlx, mlx->win, 30, 40, WHITE, "Vue de face");
	mlx_string_put(mlx->mlx, mlx->win, 165, 40, WHITE, "Vue de droite");
	mlx_string_put(mlx->mlx, mlx->win, 300, 40, WHITE, "Vue de gauche");
	mlx_string_put(mlx->mlx, mlx->win, 30, 100, WHITE, "Vue de dessous");
	mlx_string_put(mlx->mlx, mlx->win, 165, 100, WHITE, "Vue de dessous");
	return ;
}

