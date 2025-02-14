/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:46:02 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/14 13:57:13 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	set_z_max_min(t_map *map, int z)
{
	if (z > map->z_max)
		map->z_max = z;
	if (z < map->z_min)
		map->z_min = z;
	map->z_mid = (map->z_max + map->z_min) / 2;
}

int  get_map_width(char *line)
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
