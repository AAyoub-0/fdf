/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:20:33 by ayoub             #+#    #+#             */
/*   Updated: 2025/02/24 17:34:34 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->pts_3d = NULL;
	map->height = 0;
	map->width = 0;
	map->z_min = 0;
	map->z_mid = 0;
	map->z_max = 0;
	map->c_max = MAGENTA;
	map->c_mid = YELLOW;
	map->c_min = WHITE;
	map->need_update = true;
	map->fd = -1;
	map->file = NULL;
	return (map);
}

void	open_map(t_mlx *mlx, char *file)
{
	if (mlx->map)
		free_map(mlx->map);
	mlx->map = init_map();
	exit_if(!mlx->map, mlx, EXIT_FAILURE, NULL);
	mlx->map->fd = open(file, O_RDONLY);
	exit_if(mlx->map->fd <= 0, mlx, EXIT_FAILURE, NULL);
	mlx->map->file = ft_strdup(file);
	exit_if(!mlx->map->file, mlx, EXIT_FAILURE, NULL);
	parse_map(mlx, mlx->map->fd);
	close(mlx->map->fd);
	if (mlx->map->z_max > mlx->camera->z_offset * 3)
		mlx->camera->z_offset = mlx->map->z_max * 0.4;
	else
		mlx->camera->z_offset = mlx->map->z_max * 0.2;
	if (mlx->map->width * mlx->map->height > SCREEN_HEIGHT * SCREEN_WIDTH)
		mlx->camera->zoom = 1;
	else
		mlx->camera->zoom = SCREEN_WIDTH / mlx->map->width * 0.4;
}

t_bool	fill_map(t_map *map, char *line, int y)
{
	int			x;
	int			error;
	t_point3d	*tmp;

	x = 0;
	error = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			tmp = init_point3d(x, y, ft_atoi_error(line, &error));
			if (!tmp || error)
				return (false);
			set_z_max_min(map, tmp->z);
			map->pts_3d[y][x] = *tmp;
			free(tmp);
			x++;
			while (ft_isdigit(*line))
				line++;
		}
		else
			line++;
	}
	return (true);
}

void	parse_map(t_mlx *mlx, int fd)
{
	char	*line;

	line = NULL;
	mlx->map->pts_3d = ft_calloc(1, sizeof(t_point3d *));
	exit_if(!mlx->map->pts_3d, mlx, EXIT_FAILURE, NULL);
	while (get_next_line(fd, &line) >= 0 && *line != '\0')
	{
		if (mlx->map->width == 0)
			mlx->map->width = get_map_width(line);
		parse_map_line(mlx, line);
		mlx->map->height++;
		free(line);
	}
	free(line);
}

int	free_map(t_map *map)
{
	if (!map)
		return (0);
	free_points3d(map->pts_3d, map->height);
	if (map->file)
		free(map->file);
	free(map);
	map = NULL;
	return (1);
}
