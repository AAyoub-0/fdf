/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:06:07 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/13 17:11:13 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	init_ctl_btn(t_mlx *mlx)
{
	mlx->ins[2] = init_frame((t_point2d){20, 80}, 120, 45, RED);
	exit_if(!mlx->ins[2], mlx, EXIT_FAILURE);
	mlx->ins[3] = init_frame((t_point2d){155, 80}, 120, 45, RED);
	exit_if(!mlx->ins[3], mlx, EXIT_FAILURE);
	mlx->ins[4] = init_frame((t_point2d){290, 80}, 120, 45, RED);
	exit_if(!mlx->ins[4], mlx, EXIT_FAILURE);
	mlx->ins[5] = init_frame((t_point2d){20, 140}, 120, 45, RED);
	exit_if(!mlx->ins[5], mlx, EXIT_FAILURE);
	mlx->ins[6] = init_frame((t_point2d){155, 140}, 120, 45, RED);
	exit_if(!mlx->ins[6], mlx, EXIT_FAILURE);
	mlx->ins[7] = init_frame((t_point2d){20, 240}, 120, 45, BLUE);
	exit_if(!mlx->ins[7], mlx, EXIT_FAILURE);
	mlx->ins[8] = init_frame((t_point2d){155, 240}, 120, 45, BLUE);
	exit_if(!mlx->ins[8], mlx, EXIT_FAILURE);
	mlx->ins[9] = init_frame((t_point2d){290, 240}, 120, 45, BLUE);
	exit_if(!mlx->ins[9], mlx, EXIT_FAILURE);
	mlx->ins[10] = init_frame((t_point2d){20, 340}, 120, 45, GREEN);
	exit_if(!mlx->ins[10], mlx, EXIT_FAILURE);
	mlx->ins[11] = init_frame((t_point2d){155, 340}, 120, 45, GREEN);
	exit_if(!mlx->ins[11], mlx, EXIT_FAILURE);
	mlx->ins[12] = init_frame((t_point2d){290, 340}, 120, 45, GREEN);
	exit_if(!mlx->ins[12], mlx, EXIT_FAILURE);
}

void	init_instructions(t_mlx *mlx)
{	
	mlx->ins = ft_calloc(15, sizeof(t_frame *));
	exit_if(!mlx->ins, mlx, EXIT_FAILURE);
	mlx->ins[0] = init_frame((t_point2d){10, 10}, 30, 35, WHITE);
	exit_if(!mlx->ins[0], mlx, EXIT_FAILURE);
	mlx->ins[13] = init_frame((t_point2d){350, 20}, 60, 20, WHITE);
	exit_if(!mlx->ins[13], mlx, EXIT_FAILURE);
	mlx->ins[1] = init_frame((t_point2d){0, 0}, SCREEN_WIDTH * 0.23, SCREEN_HEIGHT,
			WHITE);
	exit_if(!mlx->ins[1], mlx, EXIT_FAILURE);
	init_ctl_btn(mlx);
}

void	draw_menu_icon(t_mlx *mlx)
{
	t_frame	*f0;
	t_frame	*f1;
	t_frame	*f2;

	f0 = init_frame((t_point2d){10, 10}, 30, 5, WHITE);
	exit_if(!f0, mlx, EXIT_FAILURE);
	f1 = init_frame((t_point2d){10, 20}, 30, 5, WHITE);
	if (!f1)
	{
		free(f0);
		exit_if(true, mlx, EXIT_FAILURE);
	}
	f2 = init_frame((t_point2d){10, 30}, 30, 5, WHITE);
	if (!f2)
	{
		free(f0);
		free(f1);
		exit_if(true, mlx, EXIT_FAILURE);
	}
	draw_frame(mlx, f0);
	draw_frame(mlx, f1);
	draw_frame(mlx, f2);
	free(f0);
	free(f1);
	free(f2);
}

void	draw_titles(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 360, 35, BLACK, "Fermer");
	mlx_string_put(mlx->mlx, mlx->win, 30, 75, BLACK, "Vues");
	mlx_string_put(mlx->mlx, mlx->win, 30, 100, WHITE, "Vue de face");
	mlx_string_put(mlx->mlx, mlx->win, 165, 100, WHITE, "Vue de droite");
	mlx_string_put(mlx->mlx, mlx->win, 300, 100, WHITE, "Vue de gauche");
	mlx_string_put(mlx->mlx, mlx->win, 30, 160, WHITE, "Vue de dessous");
	mlx_string_put(mlx->mlx, mlx->win, 165, 160, WHITE, "Vue de dessous");
	mlx_string_put(mlx->mlx, mlx->win, 30, 235, BLACK, "Rotation");
	mlx_string_put(mlx->mlx, mlx->win, 30, 260, WHITE, "Rotation X");
	mlx_string_put(mlx->mlx, mlx->win, 165, 260, WHITE, "Rotation Y");
	mlx_string_put(mlx->mlx, mlx->win, 300, 260, WHITE, "Rotation Z");
	mlx_string_put(mlx->mlx, mlx->win, 30, 335, BLACK, "Projection");
	mlx_string_put(mlx->mlx, mlx->win, 30, 360, WHITE, "Isometrique");
	mlx_string_put(mlx->mlx, mlx->win, 165, 360, WHITE, "TEST 1");
	mlx_string_put(mlx->mlx, mlx->win, 300, 360, WHITE, "TEST 2");
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
	draw_frame(mlx, mlx->ins[7]);
	draw_frame(mlx, mlx->ins[8]);
	draw_frame(mlx, mlx->ins[9]);
	draw_frame(mlx, mlx->ins[10]);
	draw_frame(mlx, mlx->ins[11]);
	draw_frame(mlx, mlx->ins[12]);
	draw_frame(mlx, mlx->ins[13]);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	draw_titles(mlx);
	return ;
}

