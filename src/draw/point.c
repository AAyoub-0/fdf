/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:33:20 by ayoub             #+#    #+#             */
/*   Updated: 2025/02/21 15:55:39 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point3d	*init_point3d(int x, int y, int z, t_color color)
{
	t_point3d	*point;

	point = malloc(sizeof(t_point3d));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = color;
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
	int	i;

	if (!point)
		return (false);
	i = 0;
	while (i < size - 1)
	{
		free(point[i]);
		i++;
	}
	free(point);
	return (true);
}

t_bool	free_points2d(t_point2d **point, size_t size)
{
	int	i;

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
