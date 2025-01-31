/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:05:40 by ayoub             #+#    #+#             */
/*   Updated: 2025/01/31 17:10:54 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static uint32_t	interpolate_colors(t_color *c_rgb, double rt)
{
	t_point3d s_rgb;
	t_point3d e_rgb;
	t_point3d f_rgb;
	
	s_rgb.x = (c_rgb[0] >> 16) & 0xFF;
    s_rgb.y = (c_rgb[0] >> 8) & 0xFF;
    s_rgb.z = c_rgb[0] & 0xFF;
    e_rgb.x = (c_rgb[1] >> 16) & 0xFF;
    e_rgb.y = (c_rgb[1] >> 8) & 0xFF;
    e_rgb.z = c_rgb[1] & 0xFF;
    f_rgb.x = (int)(s_rgb.x + rt * (e_rgb.x - s_rgb.x));
    f_rgb.y = (int)(s_rgb.y + rt * (e_rgb.y - s_rgb.y));
    f_rgb.z = (int)(s_rgb.z + rt * (e_rgb.z - s_rgb.z));
    return ((f_rgb.x << 16) | (f_rgb.y << 8) | f_rgb.z);
}	

uint32_t get_gradient_color(t_map map, int step, t_point2d delta, t_point2d p3d_z)
{
	double rt;
	t_color   c_rgb[2];
	int total_steps;
	int	z;
	
	total_steps = fmax(delta.x, delta.y);
	z = (int)((p3d_z.x * (total_steps - step) + p3d_z.y * step) / total_steps);
	if (z == map.z_min)
		return (map.c_min);
    if (z == map.z_max)
		return (map.c_max);
	if (z <= map.z_mid)
	{
		rt = (double)(z - map.z_min) / (map.z_mid - map.z_min);
		c_rgb[0] = map.c_min;
		c_rgb[1] = map.c_mid;
	}
	else
	{
		rt = (double)(z - map.z_mid) / (map.z_max - map.z_mid);
		c_rgb[0] = map.c_mid;
		c_rgb[1] = map.c_max;
	}
	return (interpolate_colors(c_rgb, rt));
}
