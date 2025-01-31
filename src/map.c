/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:20:33 by ayoub             #+#    #+#             */
/*   Updated: 2025/01/31 16:55:29 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->pts_3d = NULL;
	map->pts_2d = NULL;
	map->height = 0;
	map->width = 0;
	map->z_min = 0;
	map->z_mid = 0;
	map->z_max = 0;
	map->c_max = MAGENTA;
	map->c_mid = YELLOW;
	map->c_min = WHITE;
	map->need_update = true;
	return (map);
}

static int  get_map_width(char *line)
{
    int     width;

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

static void	set_z_max_min(t_map *map, int z)
{
	if (z > map->z_max)
		map->z_max = z;
	if (z < map->z_min)
		map->z_min = z;
	map->z_mid = (map->z_max + map->z_min) / 2;
}

static t_bool     fill_map(t_map *map, char *line, int y)
{
    int     x;
	t_point3d *tmp;

    x = 0;
    while (*line)
    {
        if (ft_isdigit(*line))
        {
            tmp = init_point3d(x, y, ft_atoi(line), WHITE);
			if (!tmp)
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

t_bool	parse_map(t_map *map, int fd)
{
	char 	*line;

	if (fd <= 0)
		return (false);
	line = NULL;
	map->pts_3d = malloc(sizeof(t_point3d *));
	if (!map->pts_3d)
		return (false);
	while (get_next_line(fd, &line) >= 0 && *line != '\0')
	{
		if (map->width == 0)
			map->width = get_map_width(line);
		map->pts_3d = ft_realloc(map->pts_3d, sizeof(t_point3d *) * (map->height), sizeof(t_point3d *) * (map->height + 1));
		if (!map->pts_3d)
			return (free_map(map), free(line), false);
		map->pts_3d[map->height] = malloc(sizeof(t_point3d) * map->width);
		if (!map->pts_3d[map->height])
			return (free_map(map), free(line), false);
		if (!fill_map(map, line, map->height))
			return (free_map(map), free(line), false);
		map->height++;
		free(line);
	}
	free(line);
	return (true);
}

t_bool	free_map(t_map *map)
{
	if (!map)
		return (false);
	free_points3d(map->pts_3d, map->height + 1);
	free_points2d(map->pts_2d, map->height + 1);
	free(map);
	return (true);
}
