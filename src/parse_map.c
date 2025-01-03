/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:11:50 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/02 23:39:13 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

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

static t_point   *get_point(char *line, int x, int y)
{
    t_point     *point;

    point = malloc(sizeof(t_point));
    point->x = x;
    point->y = y;
    point->z = ft_atoi(line);
    while (ft_isdigit(*line))
        line++;
    // point->color = ft_atoi_base(line, "0123456789ABCDEF");
    point->color = 0x00FF00;
    return (point);
}

static void     fill_map(t_map *map, char *line, int y)
{
    int     x;

    x = 0;
    while (*line)
    {
        if (ft_isdigit(*line))
        {
            map->points[y][x] = *get_point(line, x, y);
            x++;
            while (ft_isdigit(*line))
                line++;
        }
        else
            line++;
    }
}

t_map   *parse_map(int fd)
{
    t_map   *map;
    char    *line;

    line = NULL;
    map = malloc(sizeof(t_map));
    map->width = 0;
    map->height = 0;
    map->points = malloc(sizeof(t_point *));
    while (get_next_line(fd, &line) >= 0 && *line != '\0')
    {
        if (map->width == 0)
            map->width = get_map_width(line);
        map->points = ft_realloc(map->points, sizeof(t_point *) * (map->height + 1));
        map->points[map->height] = malloc(sizeof(t_point) * map->width);
        fill_map(map, line, map->height);
        map->height++;
        free(line);
    }
    return (map);
}
