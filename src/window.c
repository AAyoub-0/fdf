/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:01:48 by ayoub             #+#    #+#             */
/*   Updated: 2025/02/19 15:15:06 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_camera	*init_camera(void)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->zoom = 30;
	camera->r_x = 0;
	camera->r_y = 0;
	camera->r_z = 0;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->z_offset = 10;
	camera->iso = 1;
	camera->m_rad = 10;
	return (camera);
}

static t_mouse	*init_mouse(void)
{
	t_mouse	*mouse;

	mouse = malloc(sizeof(t_mouse));
	if (!mouse)
		return (NULL);
	mouse->x = 0;
	mouse->y = 0;
	mouse->prev_x = 0;
	mouse->prev_y = 0;
	mouse->button = 0;
	mouse->is_pressed = false;
	return (mouse);
}

t_mlx	*init_window(char *name)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (NULL);
	mlx->win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, name);
	if (!mlx->win)
		return (NULL);
	mlx->img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!mlx->img)
		return (NULL);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_len, &mlx->endian);
	if (!mlx->addr)
		return (NULL);
	mlx->map = NULL;
	mlx->camera = init_camera();
	if (!mlx->camera)
		return (NULL);
	mlx->mouse = init_mouse();
	if (!mlx->mouse)
		return (NULL);
	return (mlx);
}

int	free_window(t_mlx *mlx, int fd_out)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img);
	free(mlx->camera);
	free(mlx->mouse);
	free_frames(mlx->ins);
	free_map(mlx->map);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free(mlx);
	return (fd_out);
}
