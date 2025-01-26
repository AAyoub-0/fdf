/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:36:07 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/26 20:21:13 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_camera	*init_camera(void)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->z_height = 0;
	camera->zoom = 1;
	camera->x_rot = R_X;
	camera->y_rot = R_Y;
	camera->z_rot = R_Z;
	return (camera);
}

void	init_window(t_mlx **mlx, int fd)
{
	(*mlx) = malloc(sizeof(t_mlx));
	(*mlx)->mlx = mlx_init();
	(*mlx)->win = mlx_new_window((*mlx)->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	(*mlx)->img = mlx_new_image((*mlx)->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	(*mlx)->addr = mlx_get_data_addr((*mlx)->img, &(*mlx)->bits_per_pixel,
			&(*mlx)->line_length, &(*mlx)->endian);
	(*mlx)->map = parse_map(fd);
	(*mlx)->map->needs_redraw = true;
	(*mlx)->camera = init_camera();
}
