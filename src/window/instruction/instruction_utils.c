/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:26:26 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/21 20:05:05 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_ctl_btn(t_mlx *mlx)
{
	mlx->ins[2] = init_frame((t_point2d){20, 80}, 120, 45, RED);
	exit_if(!mlx->ins[2], mlx, EXIT_FAILURE, NULL);
	mlx->ins[3] = init_frame((t_point2d){155, 80}, 120, 45, RED);
	exit_if(!mlx->ins[3], mlx, EXIT_FAILURE, NULL);
	mlx->ins[4] = init_frame((t_point2d){290, 80}, 120, 45, RED);
	exit_if(!mlx->ins[4], mlx, EXIT_FAILURE, NULL);
	mlx->ins[5] = init_frame((t_point2d){20, 140}, 120, 45, RED);
	exit_if(!mlx->ins[5], mlx, EXIT_FAILURE, NULL);
	mlx->ins[6] = init_frame((t_point2d){155, 140}, 120, 45, RED);
	exit_if(!mlx->ins[6], mlx, EXIT_FAILURE, NULL);
	mlx->ins[7] = init_frame((t_point2d){20, 240}, 120, 45, BLUE);
	exit_if(!mlx->ins[7], mlx, EXIT_FAILURE, NULL);
	mlx->ins[8] = init_frame((t_point2d){155, 240}, 120, 45, BLUE);
	exit_if(!mlx->ins[8], mlx, EXIT_FAILURE, NULL);
	mlx->ins[9] = init_frame((t_point2d){290, 240}, 120, 45, BLUE);
	exit_if(!mlx->ins[9], mlx, EXIT_FAILURE, NULL);
	mlx->ins[10] = init_frame((t_point2d){20, 340}, 120, 45, GREEN);
	exit_if(!mlx->ins[10], mlx, EXIT_FAILURE, NULL);
	mlx->ins[11] = init_frame((t_point2d){155, 340}, 120, 45, GREEN);
	exit_if(!mlx->ins[11], mlx, EXIT_FAILURE, NULL);
	mlx->ins[12] = init_frame((t_point2d){290, 340}, 120, 45, WHITE);
	exit_if(!mlx->ins[12], mlx, EXIT_FAILURE, NULL);
}

void	init_maps_data(char **maps)
{
	maps[0] = M_42;
	maps[1] = M_FRANCE;
	maps[2] = M_JAPAN;
	maps[3] = M_PLAT;
	maps[4] = M_PYRA;
	maps[5] = M_WORLD;
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
	int		i;
	int		y;
	char	*maps[18];

	i = 14;
	y = 440;
	init_maps_data(maps);
	while (i < 31)
	{
		mlx->ins[i] = init_frame((t_point2d){20, y}, (mlx->ins[1]->width - 40),
				23, WHITE);
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
