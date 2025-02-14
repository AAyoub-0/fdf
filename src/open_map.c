/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:43:00 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/14 13:19:37 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	open_map(t_mlx *mlx, char *file)
{
	if (mlx->map)
		free_map(mlx->map);
	mlx->map = init_map();
	exit_if(!mlx->map, mlx, EXIT_FAILURE);
	mlx->map->fd = open(file, O_RDONLY);
	exit_if(mlx->map->fd <= 0, mlx, EXIT_FAILURE);
	parse_map(mlx->map, mlx->map->fd);
}
