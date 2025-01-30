/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:27:14 by ayoub             #+#    #+#             */
/*   Updated: 2025/01/30 21:01:38 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	close_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free_map(mlx->map);
	free_window(mlx);
	exit (0);
}
static int	key_down(int key, t_mlx *mlx)
{
	if (key == ESCAPE)
		close_window(mlx);
	return (0);
}

void	init_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win, ON_KEYDOWN, 0, key_down, mlx);
	mlx_hook(mlx->win, ON_DESTROY, 0, close_window, mlx);
}
