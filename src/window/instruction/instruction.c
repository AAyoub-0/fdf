/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:06:07 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/25 13:03:44 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_instructions(t_mlx *mlx)
{
	mlx->ins = ft_calloc(35, sizeof(t_frame *));
	exit_if(!mlx->ins, mlx, EXIT_FAILURE, NULL);
	mlx->ins[0] = init_frame((t_point2d){10, 10}, 30, 35, WHITE);
	exit_if(!mlx->ins[0], mlx, EXIT_FAILURE, NULL);
	mlx->ins[13] = init_frame((t_point2d){350, 20}, 60, 20, WHITE);
	exit_if(!mlx->ins[13], mlx, EXIT_FAILURE, NULL);
	mlx->ins[1] = init_frame((t_point2d){0, 0}, SCREEN_WIDTH * 0.23,
			SCREEN_HEIGHT, WHITE);
	exit_if(!mlx->ins[1], mlx, EXIT_FAILURE, NULL);
	mlx->ins[31] = init_frame((t_point2d){20, 925}, 120, 45, ORANGE);
	exit_if(!mlx->ins[31], mlx, EXIT_FAILURE, NULL);
	mlx->ins[32] = init_frame((t_point2d){155, 925}, 120, 45, ORANGE);
	exit_if(!mlx->ins[32], mlx, EXIT_FAILURE, NULL);
	mlx->ins[33] = init_frame((t_point2d){290, 925}, 120, 45, ORANGE);
	exit_if(!mlx->ins[33], mlx, EXIT_FAILURE, NULL);
	init_ctl_btn(mlx);
	init_maps_btn(mlx);
}

static void	draw_menu_icon(t_mlx *mlx)
{
	t_frame	*f0;
	t_frame	*f1;
	t_frame	*f2;

	f0 = init_frame((t_point2d){10, 10}, 30, 5, WHITE);
	exit_if(!f0, mlx, EXIT_FAILURE);
	f1 = init_frame((t_point2d){10, 20}, 30, 5, WHITE);
	exit_if(!f1, mlx, EXIT_FAILURE, f0, NULL);
	f2 = init_frame((t_point2d){10, 30}, 30, 5, WHITE);
	exit_if(!f2, mlx, EXIT_FAILURE, f0, f1, NULL);
	draw_frame(mlx, f0);
	draw_frame(mlx, f1);
	draw_frame(mlx, f2);
	free(f0);
	free(f1);
	free(f2);
}

static void	draw_texts(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 360, 35, BLACK, S_FERMER);
	mlx_string_put(mlx->mlx, mlx->win, 30, 75, BLACK, S_VUES);
	mlx_string_put(mlx->mlx, mlx->win, 30, 100, WHITE, S_VUE_FACE);
	mlx_string_put(mlx->mlx, mlx->win, 165, 100, WHITE, S_VUE_DROITE);
	mlx_string_put(mlx->mlx, mlx->win, 300, 100, WHITE, S_VUE_GAUCHE);
	mlx_string_put(mlx->mlx, mlx->win, 30, 160, WHITE, S_VUE_DESSUS);
	mlx_string_put(mlx->mlx, mlx->win, 165, 160, WHITE, S_VUE_DESSOUS);
	mlx_string_put(mlx->mlx, mlx->win, 30, 235, BLACK, S_ROTATION);
	mlx_string_put(mlx->mlx, mlx->win, 30, 260, WHITE, S_ROTATION_X);
	mlx_string_put(mlx->mlx, mlx->win, 165, 260, WHITE, S_ROTATION_Y);
	mlx_string_put(mlx->mlx, mlx->win, 300, 260, WHITE, S_ROTATION_Z);
	mlx_string_put(mlx->mlx, mlx->win, 30, 335, BLACK, S_PROJECTION);
	mlx_string_put(mlx->mlx, mlx->win, 30, 360, WHITE, S_ISOMETRIQUE);
	mlx_string_put(mlx->mlx, mlx->win, 165, 360, WHITE, S_PERSPECTIVE);
	mlx_string_put(mlx->mlx, mlx->win, 30, 430, BLACK, S_MAPS);
	mlx_string_put(mlx->mlx, mlx->win, 30, 920, BLACK, S_COULEURS);
	mlx_string_put(mlx->mlx, mlx->win, 30, 945, WHITE, S_COULEURS_1);
	mlx_string_put(mlx->mlx, mlx->win, 165, 945, WHITE, S_COULEURS_2);
	mlx_string_put(mlx->mlx, mlx->win, 300, 945, WHITE, S_COULEURS_3);
	draw_maps_texts(mlx);
}

void	draw_instructions(t_mlx *mlx)
{
	int	i;

	if (!mlx->show_ins)
	{
		draw_menu_icon(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
		return ;
	}
	i = 1;
	while (mlx->ins[i])
	{
		draw_frame(mlx, mlx->ins[i]);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	draw_texts(mlx);
	return ;
}
