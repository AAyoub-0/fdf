/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:27:14 by ayoub             #+#    #+#             */
/*   Updated: 2025/02/06 17:52:42 by aboumall         ###   ########.fr       */
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

static int	no_event(void *data)
{
	t_mlx	*mlx;
	int	mouse_pos;

	mlx = (t_mlx *)data;
	mouse_pos = mlx_mouse_get_pos(mlx->mlx, mlx->win, &mlx->mouse->x, &mlx->mouse->y);
	if (mlx->ins)
	{
		menu_frame_event_hover(mlx);
		view_face_event_hover(mlx);
		view_right_event_hover(mlx);
		view_left_event_hover(mlx);
		view_up_event_hover(mlx);
		view_down_event_hover(mlx);
	}
	if (mlx->mouse->is_pressed)
	{
		mouse_move(mlx->mouse->x, mlx->mouse->y, mlx);
	}
	return (0);
}

void	init_hooks(t_mlx *mlx)
{
	mlx_key_hook(mlx->win, key_down, mlx);
	mlx_loop_hook(mlx->mlx, no_event, mlx);
	mlx_hook(mlx->win, ON_MOUSEDOWN, 1L<<2, mouse_down, mlx);
	mlx_hook(mlx->win, ON_MOSEUP, 1L<<3, mouse_up, mlx);
	mlx_hook(mlx->win, ON_DESTROY, 0, close_window, mlx);
}
