/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:06:07 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/18 18:10:20 by aboumall         ###   ########.fr       */
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
	mlx->ins[31] = init_frame((t_point2d){20, 925}, 120, 45, ORANGE);
	exit_if(!mlx->ins[31], mlx, EXIT_FAILURE);
	mlx->ins[32] = init_frame((t_point2d){155, 925}, 120, 45, ORANGE);
	exit_if(!mlx->ins[32], mlx, EXIT_FAILURE);
	mlx->ins[33] = init_frame((t_point2d){290, 925}, 120, 45, ORANGE);
	exit_if(!mlx->ins[33], mlx, EXIT_FAILURE);
}

void	init_maps_data(char **maps)
{
	maps[0] = M_42;
	maps[1] = M_FRANCE;
	maps[2] = M_JAPAN;
	maps[3] = M_PLAT;
	maps[4] = M_PYRA;
	maps[5] = M_10_2;
	maps[6] = M_10_70;
	maps[7] = M_20_60;
	maps[8] = M_50_4;
	maps[9] = M_100_6;
	maps[10] = M_BAS_TEST;
	maps[11] = M_ELEM;
	maps[12] = M_MARS;
	maps[13] = M_PENTEN;
	maps[14] = M_PNP_FLAT;
	maps[15] = M_PYLONE;
	maps[16] = M_PYRAMIDE;
	maps[17] = NULL;
}

void	set_selected_map_btn(t_mlx *mlx, int i)
{
	int	j;

	j = 14;
	while (j < 31)
	{
		mlx->ins[j]->selected = false;
		mlx->ins[j]->bg = WHITE;
		j++;
	}
	mlx->ins[i]->selected = true;
	mlx->ins[i]->bg = MAGENTA_9;
}

void	init_maps_btn(t_mlx *mlx)
{
	int	i;
	int	y;
	t_color	color;
	char	*maps[18];
	
	i = 14;
	y = 440;
	init_maps_data(maps);
	while (i < 31)
	{
		mlx->ins[i] = init_frame((t_point2d){20, y}, (mlx->ins[1]->width - 40), 23, WHITE);
		exit_if(!mlx->ins[i], mlx, EXIT_FAILURE);
		mlx->ins[i]->data = ft_strdup(maps[i - 14]);
		exit_if(!mlx->ins[i]->data, mlx, EXIT_FAILURE);
		if (ft_strcmp(mlx->map->file + 5, mlx->ins[i]->data))
		{
			mlx->ins[i]->bg = MAGENTA_9;
			mlx->ins[i]->selected = true;
		}
		i++;
		y += 25;
	}
}

void	init_instructions(t_mlx *mlx)
{
	mlx->ins = ft_calloc(35, sizeof(t_frame *));
	exit_if(!mlx->ins, mlx, EXIT_FAILURE);
	mlx->ins[0] = init_frame((t_point2d){10, 10}, 30, 35, WHITE);
	exit_if(!mlx->ins[0], mlx, EXIT_FAILURE);
	mlx->ins[13] = init_frame((t_point2d){350, 20}, 60, 20, WHITE);
	exit_if(!mlx->ins[13], mlx, EXIT_FAILURE);
	mlx->ins[1] = init_frame((t_point2d){0, 0}, SCREEN_WIDTH * 0.23, SCREEN_HEIGHT,
			WHITE);
	exit_if(!mlx->ins[1], mlx, EXIT_FAILURE);
	init_ctl_btn(mlx);
	init_maps_btn(mlx);
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

void	draw_maps_texts(t_mlx *mlx)
{
	int	i;
	int	y;

	i = 14;
	y = 455;
	while (i < 31)
	{
		if (mlx->ins[i]->selected)
			mlx_string_put(mlx->mlx, mlx->win, 30, y, WHITE, mlx->ins[i]->data);
		else
			mlx_string_put(mlx->mlx, mlx->win, 30, y, BLACK, mlx->ins[i]->data);
		i++;
		y += 25;
	}
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
	mlx_string_put(mlx->mlx, mlx->win, 30, 430, BLACK, "Maps");
	mlx_string_put(mlx->mlx, mlx->win, 30, 920, BLACK, "Couleurs");
	mlx_string_put(mlx->mlx, mlx->win, 30, 945, WHITE, "Couleurs 1");
	mlx_string_put(mlx->mlx, mlx->win, 165, 945, WHITE, "Couleurs 2");
	mlx_string_put(mlx->mlx, mlx->win, 300, 945, WHITE, "Couleurs 3");
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
	draw_titles(mlx);
	draw_maps_texts(mlx);
	return ;
}

