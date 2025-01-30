/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:20:33 by ayoub             #+#    #+#             */
/*   Updated: 2025/01/30 19:58:39 by ayoub            ###   ########.fr       */
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
	map->zoom = 20;
	map->z_div = 1;
	map->r_x = 0;
	map->r_y = 0;
	map->r_z = 0;
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
		printf("height: %d\n", map->height);
		if (map->width == 0)
			map->width = get_map_width(line);
		map->pts_3d = ft_realloc(map->pts_3d, sizeof(t_point3d *) * (map->height), sizeof(t_point3d *) * (map->height + 1));
		if (!map->pts_3d)
			return (free_map(map), free(line), false);
		printf("Point allocated\n");
		map->pts_3d[map->height] = malloc(sizeof(t_point3d) * map->width);
		if (!map->pts_3d[map->height])
			return (free_map(map), free(line), false);
		printf("Point allocated 1\n");
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
