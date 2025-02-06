/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:27:14 by ayoub             #+#    #+#             */
/*   Updated: 2025/02/05 20:30:54 by aboumall         ###   ########.fr       */
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
	mouse_move(x, y, mlx);
	return (0);
}

static t_bool	mouse_over_frame(t_mouse m, t_frame f)
{
	return (m.x >= f.coord.x && m.x <= f.coord.x + f.width
				&& m.y >= f.coord.y && m.y <= f.height + f.coord.y);
}

static int	no_event(void *data)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)data;
	int mouse_pos;
	mouse_pos = mlx_mouse_get_pos(mlx->mlx, mlx->win, &mlx->mouse->x, &mlx->mouse->y);
	// printf("x: %d, y: %d\n", mlx->mouse->x, mlx->mouse->y);
	if (mlx->ins)
	{
		if (mouse_over_frame(*(mlx->mouse), *(mlx->ins[1])))
		{
			mlx->ins[1]->m_over = true;
		}
		else
		{
			mlx->ins[1]->m_over = false;
		}
		if (!mouse_over_frame(*(mlx->mouse), *(mlx->ins[0])))
			mlx->ins[0]->m_over = false;
		if (!mouse_over_frame(*(mlx->mouse), *(mlx->ins[2])) && mlx->show_ins == true)
		{
			mlx->ins[2]->m_over = false;
			if (!mlx->ins[4]->m_over && !mlx->ins[3]->m_over && !mlx->ins[5]->m_over && !mlx->ins[6]->m_over)
				mlx_cursor_reset(mlx->mlx, mlx->win);
			if (mlx->ins[2]->bg != RED)
			{	
				mlx->ins[2]->bg = RED;
				draw_instructions(mlx);
			}
		}
		if (!mouse_over_frame(*(mlx->mouse), *(mlx->ins[3])) && mlx->show_ins == true)
		{
			mlx->ins[3]->m_over = false;
			if (!mlx->ins[2]->m_over && !mlx->ins[4]->m_over && !mlx->ins[5]->m_over && !mlx->ins[6]->m_over)
				mlx_cursor_reset(mlx->mlx, mlx->win);
			if (mlx->ins[3]->bg != RED)
			{	
				mlx->ins[3]->bg = RED;
				draw_instructions(mlx);
			}
		}
		if (!mouse_over_frame(*(mlx->mouse), *(mlx->ins[4])) && mlx->show_ins == true)
		{
			mlx->ins[4]->m_over = false;
			if (!mlx->ins[2]->m_over && !mlx->ins[3]->m_over && !mlx->ins[5]->m_over && !mlx->ins[6]->m_over)
				mlx_cursor_reset(mlx->mlx, mlx->win);
			if (mlx->ins[4]->bg != RED)
			{	
				mlx->ins[4]->bg = RED;
				draw_instructions(mlx);
			}
		}
		if (!mouse_over_frame(*(mlx->mouse), *(mlx->ins[5])) && mlx->show_ins == true)
		{
			mlx->ins[5]->m_over = false;
			if (!mlx->ins[2]->m_over && !mlx->ins[3]->m_over && !mlx->ins[4]->m_over && !mlx->ins[6]->m_over)
				mlx_cursor_reset(mlx->mlx, mlx->win);
			if (mlx->ins[5]->bg != RED)
			{	
				mlx->ins[5]->bg = RED;
				draw_instructions(mlx);
			}
		}
		if (!mouse_over_frame(*(mlx->mouse), *(mlx->ins[6])) && mlx->show_ins == true)
		{
			mlx->ins[6]->m_over = false;
			if (!mlx->ins[2]->m_over && !mlx->ins[3]->m_over && !mlx->ins[5]->m_over && !mlx->ins[4]->m_over)
				mlx_cursor_reset(mlx->mlx, mlx->win);
			if (mlx->ins[6]->bg != RED)
			{	
				mlx->ins[6]->bg = RED;
				draw_instructions(mlx);
			}
		}
		if (mouse_over_frame(*(mlx->mouse), *(mlx->ins[0])) && mlx->show_ins == false)
		{
			mlx_cursor_change(mlx->mlx, mlx->win, 60);
			mlx->ins[0]->m_over = true;
		}
		if (mouse_over_frame(*(mlx->mouse), *(mlx->ins[2])) && mlx->show_ins == true)
		{
			mlx->ins[2]->m_over = true;
			mlx_cursor_change(mlx->mlx, mlx->win, 60);
			if (mlx->ins[2]->bg != RED_OV)
			{
				mlx->ins[2]->bg = RED_OV;
				draw_instructions(mlx);
			}
		}
		if (mouse_over_frame(*(mlx->mouse), *(mlx->ins[3])) && mlx->show_ins == true)
		{
			mlx->ins[3]->m_over = true;
			mlx_cursor_change(mlx->mlx, mlx->win, 60);
			if (mlx->ins[3]->bg != RED_OV)
			{
				mlx->ins[3]->bg = RED_OV;
				draw_instructions(mlx);
			}
		}
		if (mouse_over_frame(*(mlx->mouse), *(mlx->ins[4])) && mlx->show_ins == true)
		{
			mlx->ins[4]->m_over = true;
			mlx_cursor_change(mlx->mlx, mlx->win, 60);
			if (mlx->ins[4]->bg != RED_OV)
			{
				mlx->ins[4]->bg = RED_OV;
				draw_instructions(mlx);
			}
		}
		if (mouse_over_frame(*(mlx->mouse), *(mlx->ins[5])) && mlx->show_ins == true)
		{
			mlx->ins[5]->m_over = true;
			mlx_cursor_change(mlx->mlx, mlx->win, 60);
			if (mlx->ins[5]->bg != RED_OV)
			{
				mlx->ins[5]->bg = RED_OV;
				draw_instructions(mlx);
			}
		}
		if (mouse_over_frame(*(mlx->mouse), *(mlx->ins[6])) && mlx->show_ins == true)
		{
			mlx->ins[6]->m_over = true;
			mlx_cursor_change(mlx->mlx, mlx->win, 60);
			if (mlx->ins[6]->bg != RED_OV)
			{
				mlx->ins[6]->bg = RED_OV;
				draw_instructions(mlx);
			}
		}
	}
	if (mlx->mouse->is_pressed)
	{
		mouse_move(mlx->mouse->x, mlx->mouse->y, mlx);
	}
	return (0);
}

void	init_hooks(t_mlx *mlx)
{
	mlx_loop_hook(mlx->win, no_event, mlx);
	mlx_key_hook(mlx->win, key_down, mlx);
	mlx_mouse_hook(mlx->win, mouse_events, mlx);
	mlx_hook(mlx->win, ON_DESTROY, 0, close_window, mlx);
	mlx_loop_hook(mlx->mlx, no_event, mlx);
}
