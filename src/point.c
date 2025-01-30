/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:33:20 by ayoub             #+#    #+#             */
/*   Updated: 2025/01/30 17:37:04 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	print_point(void *p, t_bool is3d)
{
	if (!p)
	{
		ft_printf("Point NULL\n");
		return ;
	}
	if (is3d)
	{
		t_point3d *point = (t_point3d *)p;
		ft_printf("Point3d[%p]\n{\n", point);
		ft_printf("%10s : %d\n", "x", point->x);
		ft_printf("%10s : %d\n", "y", point->y);
		ft_printf("%10s : %d\n", "z", point->z);
		ft_printf("%10s : %d\n", "color", point->color);
		ft_printf("}\n");
		return ;
	}
	t_point2d *point = (t_point2d *)p;
	ft_printf("Point2d[%p]\n{\n", point);
	ft_printf("%10s : %d\n", "x", point->x);
	ft_printf("%10s : %d\n", "y", point->y);
	ft_printf("}\n");
}

t_point3d	*init_point3d(int x, int y, int z, t_colors color)
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

t_bool  free_points3d(t_point3d **point, size_t size)
{
	int i;

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

t_bool  free_points2d(t_point2d **point, size_t size)
{
	int i;

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
