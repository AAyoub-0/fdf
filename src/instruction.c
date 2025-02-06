/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:06:07 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/06 17:59:51 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	init_instructions(t_mlx *mlx)
{
	mlx->ins = ft_calloc(8, sizeof(t_frame *));
	mlx->ins[0] = init_frame((t_point2d){10, 10}, 30, 35, WHITE);
	mlx->ins[1] = init_frame((t_point2d){0, 0}, SCREEN_WIDTH * 0.23, SCREEN_HEIGHT,
			WHITE);
	mlx->ins[2] = init_frame((t_point2d){20, 20}, 120, 45, RED);
	mlx->ins[3] = init_frame((t_point2d){155, 20}, 120, 45, RED);
	mlx->ins[4] = init_frame((t_point2d){290, 20}, 120, 45, RED);
	mlx->ins[5] = init_frame((t_point2d){20, 80}, 120, 45, RED);
	mlx->ins[6] = init_frame((t_point2d){155, 80}, 120, 45, RED);
}

void	draw_menu_icon(t_mlx *mlx)
{
	t_frame	f0;
	t_frame	f1;
	t_frame	f2;

	f0 = *init_frame((t_point2d){10, 10}, 30, 5, WHITE);
	f1 = *init_frame((t_point2d){10, 20}, 30, 5, WHITE);
	f2 = *init_frame((t_point2d){10, 30}, 30, 5, WHITE);
	draw_frame(mlx, &f0);
	draw_frame(mlx, &f1);
	draw_frame(mlx, &f2);
}

void	draw_instructions(t_mlx *mlx)
{
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

