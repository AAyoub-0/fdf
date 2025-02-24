/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:46:02 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/24 17:30:01 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_z_max_min(t_map *map, int z)
{
	if (z > map->z_max)
		map->z_max = z;
	if (z < map->z_min)
		map->z_min = z;
	map->z_mid = (map->z_max + map->z_min) / 2;
}

int	get_map_width(char *line)
{
	int	width;

	width = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			width++;
			while (ft_isdigit(*line))
				line++;
		}
		else
			line++;
	}
	return (width);
}

void	parse_map_line(t_mlx *mlx, char *line)
{
	mlx->map->pts_3d = ft_realloc(mlx->map->pts_3d, sizeof(t_point3d *)
			* (mlx->map->height), sizeof(t_point3d *) * (mlx->map->height + 1));
	if (!mlx->map->pts_3d)
	{
		mlx->map->height++;
		exit_if(true, mlx, EXIT_FAILURE, line, NULL);
	}
	mlx->map->pts_3d[mlx->map->height] = ft_calloc(mlx->map->width,
			sizeof(t_point3d));
	if (!mlx->map->pts_3d[mlx->map->height])
	{
		mlx->map->height++;
		exit_if(true, mlx, EXIT_FAILURE, line, NULL);
	}
	if (!fill_map(mlx->map, line, mlx->map->height))
	{
		mlx->map->height++;
		exit_if(true, mlx, EXIT_FAILURE, line, NULL);
	}
}
