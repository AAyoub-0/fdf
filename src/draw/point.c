/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:33:20 by ayoub             #+#    #+#             */
/*   Updated: 2025/02/24 16:51:51 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point3d	*init_point3d(int x, int y, int z)
{
	t_point3d	*point;

	point = malloc(sizeof(t_point3d));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

t_point2d	*init_point2d(int x, int y)
{
	t_point2d	*point;

	point = malloc(sizeof(t_point2d));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	return (point);
}

t_bool	free_points3d(t_point3d **point, size_t size)
{
	size_t	i;

	if (!point)
		return (false);
	i = 0;
	while (i < size)
	{
		free(point[i]);
		i++;
	}
	free(point);
	return (true);
}
