/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_ctl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:26:12 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/06 19:35:03 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	view_face_event_hover(t_mlx *mlx)
{
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
	if (!mouse_over_frame(*(mlx->mouse), *(mlx->ins[2])) && mlx->show_ins == true)
	{
		mlx->ins[2]->m_over = false;
		if (!mlx->ins[4]->m_over && !mlx->ins[3]->m_over && !mlx->ins[5]->m_over
				&& !mlx->ins[6]->m_over && !mlx->ins[7]->m_over && !mlx->ins[8]->m_over
					&& !mlx->ins[9]->m_over)
			mlx_cursor_reset(mlx->mlx, mlx->win);
		if (mlx->ins[2]->bg != RED)
		{	
			mlx->ins[2]->bg = RED;
			draw_instructions(mlx);
		}
	}
}

void	view_right_event_hover(t_mlx *mlx)
{
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
	if (!mouse_over_frame(*(mlx->mouse), *(mlx->ins[3])) && mlx->show_ins == true)
	{
		mlx->ins[3]->m_over = false;
		if (!mlx->ins[2]->m_over && !mlx->ins[4]->m_over && !mlx->ins[5]->m_over
				&& !mlx->ins[6]->m_over && !mlx->ins[7]->m_over && !mlx->ins[8]->m_over
					&& !mlx->ins[9]->m_over)
			mlx_cursor_reset(mlx->mlx, mlx->win);
		if (mlx->ins[3]->bg != RED)
		{	
			mlx->ins[3]->bg = RED;
			draw_instructions(mlx);
		}
	}
}

void	view_left_event_hover(t_mlx *mlx)
{
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
	if (!mouse_over_frame(*(mlx->mouse), *(mlx->ins[4])) && mlx->show_ins == true)
	{
		mlx->ins[4]->m_over = false;
		if (!mlx->ins[2]->m_over && !mlx->ins[3]->m_over && !mlx->ins[5]->m_over
				&& !mlx->ins[6]->m_over && !mlx->ins[7]->m_over && !mlx->ins[8]->m_over
					&& !mlx->ins[9]->m_over)
			mlx_cursor_reset(mlx->mlx, mlx->win);
		if (mlx->ins[4]->bg != RED)
		{	
			mlx->ins[4]->bg = RED;
			draw_instructions(mlx);
		}
	}
}

void	view_up_event_hover(t_mlx *mlx)
{
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
	if (!mouse_over_frame(*(mlx->mouse), *(mlx->ins[5])) && mlx->show_ins == true)
	{
		mlx->ins[5]->m_over = false;
		if (!mlx->ins[2]->m_over && !mlx->ins[3]->m_over && !mlx->ins[4]->m_over
				&& !mlx->ins[6]->m_over && !mlx->ins[7]->m_over && !mlx->ins[8]->m_over
					&& !mlx->ins[9]->m_over)
			mlx_cursor_reset(mlx->mlx, mlx->win);
		if (mlx->ins[5]->bg != RED)
		{	
			mlx->ins[5]->bg = RED;
			draw_instructions(mlx);
		}
	}
}

void	view_down_event_hover(t_mlx *mlx)
{
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
	if (!mouse_over_frame(*(mlx->mouse), *(mlx->ins[6])) && mlx->show_ins == true)
	{
		mlx->ins[6]->m_over = false;
		if (!mlx->ins[2]->m_over && !mlx->ins[3]->m_over && !mlx->ins[4]->m_over
				&& !mlx->ins[5]->m_over && !mlx->ins[7]->m_over && !mlx->ins[8]->m_over
					&& !mlx->ins[9]->m_over)
			mlx_cursor_reset(mlx->mlx, mlx->win);
		if (mlx->ins[6]->bg != RED)
		{	
			mlx->ins[6]->bg = RED;
			draw_instructions(mlx);
		}
	}
}
