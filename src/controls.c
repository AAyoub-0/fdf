/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:48:04 by ayoub             #+#    #+#             */
/*   Updated: 2025/02/17 18:49:20 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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

void	view_event_click(t_mlx *mlx, int id, t_fpoint3d n_rt)
{
	if (id == 13 && mlx->ins[13]->m_over && mlx->show_ins)
	{
		mlx->show_ins = false;
		draw_map(mlx);
		draw_instructions(mlx);
		return ;
	}
	if (id == 10 && mlx->ins[10]->m_over)
		mlx->camera->iso = true;
	if (id == 11 && mlx->ins[11]->m_over)
		mlx->camera->iso = false;
	if (mouse_over_frame(mlx->mouse, mlx->ins[id])
		&& mlx->show_ins)
	{
		mlx->camera->r_x = n_rt.x;
		mlx->camera->r_y = n_rt.y;
		mlx->camera->r_z = n_rt.z;
		draw_map(mlx);
		draw_instructions(mlx);
	}
}

void	rot_event_click(t_mlx *mlx, int id, t_fpoint3d n_rt)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[id]) && mlx->show_ins)
	{
		mlx->camera->r_x += n_rt.x;
		mlx->camera->r_y += n_rt.y;
		mlx->camera->r_z += n_rt.z;
		draw_map(mlx);
		draw_instructions(mlx);
	}
}

void	map_event_click(t_mlx *mlx, int id)
{
	char	*tmp;
	if (mouse_over_frame(mlx->mouse, mlx->ins[id]) && mlx->show_ins)
	{
		tmp = ft_strjoin("maps/", mlx->ins[id]->data);
		exit_if(!tmp, mlx, EXIT_FAILURE);
		open_map(mlx, tmp);
		draw_map(mlx);
		draw_instructions(mlx);
		free(tmp);
	}
}

int	mouse_up(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == MOUSE_LEFT || button == MOUSE_RIGHT)
	{
		view_event_click(mlx, 2, (t_fpoint3d){-1.5708, 0, 0});
		view_event_click(mlx, 3, (t_fpoint3d){0, 1.5708, 0});
		view_event_click(mlx, 4, (t_fpoint3d){0, -1.5708, 0});
		view_event_click(mlx, 5, (t_fpoint3d){0, 0, 0});
		view_event_click(mlx, 6, (t_fpoint3d){0, -3.14159, 0});
		rot_event_click(mlx, 7, (t_fpoint3d){0.1, 0, 0});
		rot_event_click(mlx, 8, (t_fpoint3d){0, 0.1, 0});
		rot_event_click(mlx, 9, (t_fpoint3d){0, 0, 0.1});
		view_event_click(mlx, 10, (t_fpoint3d){0, 0, 0});
		view_event_click(mlx, 11, (t_fpoint3d){0.349, 0.785, 0.0});
		view_event_click(mlx, 12, (t_fpoint3d){0.0, 0.785, 0.0});
		view_event_click(mlx, 13, (t_fpoint3d){0, 0, 0});
		map_event_click(mlx, 14);
		map_event_click(mlx, 15);
		map_event_click(mlx, 16);
		map_event_click(mlx, 17);
		map_event_click(mlx, 18);
		map_event_click(mlx, 19);
		map_event_click(mlx, 20);
		map_event_click(mlx, 21);
		map_event_click(mlx, 22);
		map_event_click(mlx, 23);
		map_event_click(mlx, 24);
		map_event_click(mlx, 25);
		map_event_click(mlx, 26);
		map_event_click(mlx, 27);
		map_event_click(mlx, 28);
		map_event_click(mlx, 29);
		map_event_click(mlx, 30);
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
