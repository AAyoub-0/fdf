/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:48:04 by ayoub             #+#    #+#             */
/*   Updated: 2025/02/21 14:52:45 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keyboard_events(int key, t_mlx *mlx)
{
	if (key == XK_Up)
		mlx->camera->y_offset -= 10;
	else if (key == XK_Down)
		mlx->camera->y_offset += 10;
	else if (key == XK_Left)
		mlx->camera->x_offset -= 10;
	else if (key == XK_Right)
		mlx->camera->x_offset += 10;
	else if (key == XK_equal)
		mlx->camera->zoom += 1;
	else if (key == XK_minus)
		mlx->camera->zoom -= 1;
	else if (key == XK_i)
		mlx->camera->iso = !mlx->camera->iso;
	else if (key == XK_z)
		mlx->camera->z_offset -= 1;
	else if (key == XK_x)
		mlx->camera->z_offset += 1;
	else
		return ;
	draw_map(mlx);
	draw_instructions(mlx);
}

int	mouse_down(int button, int x, int y, t_mlx *mlx)
{
	if (button == MOUSE_WHEEL_UP)
		mlx->camera->zoom += 1;
	else if (button == MOUSE_WHEEL_DOWN)
		mlx->camera->zoom -= 1;
	else if (button == MOUSE_LEFT || button == MOUSE_RIGHT)
	{
		mlx->mouse->is_pressed = true;
		mlx->mouse->button = button;
		mlx->mouse->prev_x = x;
		mlx->mouse->prev_y = y;
		if (mlx->ins[0]->m_over && !mlx->show_ins)
		{
			mlx->show_ins = true;
			draw_instructions(mlx);
			return (0);
		}
	}
	draw_map(mlx);
	draw_instructions(mlx);
	return (0);
}

int	mouse_up(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == MOUSE_LEFT || button == MOUSE_RIGHT)
	{
		view_rot_event(mlx);
		map_event(mlx);
		color_event(mlx);
		mlx->mouse->is_pressed = false;
		mlx->mouse->button = 0;
	}
	return (0);
}

int	mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->mouse->is_pressed)
	{
		if (mlx->mouse->button == MOUSE_LEFT)
		{
			if ((!mlx->ins[1]->m_over && mlx->show_ins) || (!mlx->ins[0]->m_over
					&& !mlx->show_ins))
			{
				mlx->camera->r_x += (y - mlx->mouse->prev_y) * 0.005;
				mlx->camera->r_y += (x - mlx->mouse->prev_x) * 0.005;
				draw_map(mlx);
				draw_instructions(mlx);
				return (0);
			}
		}
		mlx->mouse->prev_x = x;
		mlx->mouse->prev_y = y;
	}
	return (0);
}
