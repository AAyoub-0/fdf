/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:01:48 by ayoub             #+#    #+#             */
/*   Updated: 2025/02/24 17:12:33 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static void	set_null(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->addr = NULL;
	mlx->map = NULL;
	mlx->camera = NULL;
	mlx->mouse = NULL;
	mlx->ins = NULL;
}

t_mlx	*init_window(char *name)
{
	t_mlx	*mlx;
	char	*full_name;

	mlx = malloc(sizeof(t_mlx));
	exit_if(!mlx, mlx, EXIT_FAILURE, NULL);
	set_null(mlx);
	full_name = ft_strjoin("Fdf - ", name);
	exit_if(!full_name, mlx, EXIT_FAILURE, NULL);
	free(name);
	mlx->mlx = mlx_init();
	exit_if(!mlx->mlx, mlx, EXIT_FAILURE, full_name, NULL);
	mlx->win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, full_name);
	exit_if(!mlx->win, mlx, EXIT_FAILURE, full_name, NULL);
	free(full_name);
	mlx->img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	exit_if(!mlx->img, mlx, EXIT_FAILURE, NULL);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_len,
			&mlx->endian);
	exit_if(!mlx->addr, mlx, EXIT_FAILURE, NULL);
	mlx->map = NULL;
	mlx->camera = init_camera();
	exit_if(!mlx->camera, mlx, EXIT_FAILURE, NULL);
	mlx->mouse = init_mouse();
	exit_if(!mlx->mouse, mlx, EXIT_FAILURE, NULL);
	return (mlx);
}

int	free_window(t_mlx *mlx, int fd_out)
{
	if (!mlx)
		return (fd_out);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->camera)
		free(mlx->camera);
	if (mlx->mouse)
		free(mlx->mouse);
	free_frames(mlx->ins);
	free_map(mlx->map);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free(mlx);
	return (fd_out);
}
