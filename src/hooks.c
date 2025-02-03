/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:27:14 by ayoub             #+#    #+#             */
/*   Updated: 2025/02/03 15:31:10 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	close_window(void *params)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)params;
	free_map(mlx->map);
	free_window(mlx);
	exit (0);
}
int	key_down(int keycode, void *params)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)params;
	if (keycode == XK_Escape)
		close_window(mlx);
	else
		keyboard_events(keycode, mlx);
	return (0);
}

static int mouse_events(int button, int x, int y, t_mlx *mlx)
{
	if (button == MOUSE_WHEEL_UP || button == MOUSE_WHEEL_DOWN)
		mouse_down(button, x, y, mlx);
	else if (button == MOUSE_LEFT || button == MOUSE_RIGHT)
	{
		if (mlx->mouse->is_pressed)
			mouse_up(button, x, y, mlx);
		else
			mouse_down(button, x, y, mlx);
	}
	// mouse_move(x, y, mlx);
	return (0);
}

static int	no_event(void *data)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)data;
	if (mlx->mouse->is_pressed)
	{
		int mouse_pos;
		mouse_pos = mlx_mouse_get_pos(mlx->mlx, mlx->win, &mlx->mouse->x, &mlx->mouse->y);
		mouse_move(mlx->mouse->x, mlx->mouse->y, mlx);
	}
	return (0);
}

void	init_hooks(t_mlx *mlx)
{
	mlx_loop_hook(mlx->win, no_event,mlx);
	mlx_key_hook(mlx->win, key_down,mlx);
	mlx_mouse_hook(mlx->win, mouse_events, mlx);
	mlx_hook(mlx->win, ON_DESTROY, 0, close_window, mlx);
	mlx_loop_hook(mlx->mlx, no_event, mlx);
}
