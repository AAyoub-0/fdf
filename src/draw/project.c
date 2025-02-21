/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:02:34 by ayoub             #+#    #+#             */
/*   Updated: 2025/02/21 14:52:45 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_point3d(t_point3d *p, t_camera *c)
{
	int	tmp_y;
	int	tmp_x;
	int	tmp_z;

	tmp_y = p->y;
	tmp_x = p->x;
	tmp_z = p->z;
	// rotation x axes
	p->y = tmp_y * cos(c->r_x) + p->z * sin(c->r_x);
	p->z = -tmp_y * sin(c->r_x) + p->z * cos(c->r_x);
	// rotation y axes
	p->x = tmp_x * cos(c->r_y) + p->z * sin(c->r_y);
	p->z = -tmp_x * sin(c->r_y) + p->z * cos(c->r_y);
	// rotation z axes
	tmp_x = p->x;
	tmp_y = p->y;
	p->x = tmp_x * cos(c->r_z) - tmp_y * sin(c->r_z);
	p->y = tmp_x * sin(c->r_z) + tmp_y * cos(c->r_z);
}

static t_point2d	project_isometric(t_point3d p3d, t_map *map, t_camera *c)
{
	t_point2d	p2d;

	// apply zoom
	p3d.x *= c->zoom;
	p3d.y *= c->zoom;
	p3d.z *= c->zoom;
	if (c->z_offset < 1)
		c->z_offset = 1;
	p3d.z /= c->z_offset;
	p3d.x -= (map->width * c->zoom) / 2;
	p3d.y -= (map->height * c->zoom) / 2;
	// apply rotation
	rotate_point3d(&p3d, c);
	// apply scaling
	p3d.x += (SCREEN_WIDTH / 2 + c->x_offset) * 1.2;
	p3d.y += ((SCREEN_HEIGHT + map->height / 2 * c->zoom) / 2 + c->y_offset)
		* 0.009;
	// iso projection
	p2d.x = (p3d.x - p3d.y) * cos(0.523599);
	p2d.y = (p3d.y + p3d.x) * sin(0.523599) - p3d.z;
	return (p2d);
}

static t_point2d	project_perspective(t_point3d p3d, t_map *map, t_camera *c)
{
	t_point2d	p2d;

	// apply zoom
	p3d.x *= c->zoom;
	p3d.y *= c->zoom;
	p3d.z *= c->zoom;
	if (c->z_offset < 1)
		c->z_offset = 1;
	p3d.z /= c->z_offset;
	p3d.x -= (map->width * c->zoom) / 2;
	p3d.y -= (map->height * c->zoom) / 2;
	// apply rotation
	rotate_point3d(&p3d, c);
	// apply scaling
	p3d.x += SCREEN_WIDTH / 2 + c->x_offset;
	p3d.y += (SCREEN_HEIGHT + map->height / 2 * c->zoom) / 2 + c->y_offset;
	p2d.x = p3d.x;
	p2d.y = p3d.y;
	return (p2d);
}

t_point2d	project_point3d(t_point3d p3d, t_map *map, t_camera *c)
{
	if (c->iso)
		return (project_isometric(p3d, map, c));
	else
		return (project_perspective(p3d, map, c));
}
