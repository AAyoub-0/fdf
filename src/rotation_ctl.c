/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_ctl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:26:42 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/18 15:24:59 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	rot_x_event_hover(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[7]) && mlx->show_ins == true)
	{
		mlx->ins[7]->m_over = true;
		if (mlx->ins[7]->bg != BLUE_OV)
		{
			mlx->ins[7]->bg = BLUE_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[7]) && mlx->show_ins == true)
	{
		mlx->ins[7]->m_over = false;
		if (mlx->ins[7]->bg != BLUE)
		{	
			mlx->ins[7]->bg = BLUE;
			draw_instructions(mlx);
		}
	}
}

void	rot_y_event_hover(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[8]) && mlx->show_ins == true)
	{
		mlx->ins[8]->m_over = true;
		if (mlx->ins[8]->bg != BLUE_OV)
		{
			mlx->ins[8]->bg = BLUE_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[8]) && mlx->show_ins == true)
	{
		mlx->ins[8]->m_over = false;
		if (mlx->ins[8]->bg != BLUE)
		{	
			mlx->ins[8]->bg = BLUE;
			draw_instructions(mlx);
		}
	}
}

void	rot_z_event_hover(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[9]) && mlx->show_ins == true)
	{
		mlx->ins[9]->m_over = true;
		if (mlx->ins[9]->bg != BLUE_OV)
		{
			mlx->ins[9]->bg = BLUE_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[9]) && mlx->show_ins == true)
	{
		mlx->ins[9]->m_over = false;
		if (mlx->ins[9]->bg != BLUE)
		{	
			mlx->ins[9]->bg = BLUE;
			draw_instructions(mlx);
		}
	}
}

void	rot_event_hover(t_mlx *mlx)
{
	rot_x_event_hover(mlx);
	rot_y_event_hover(mlx);
	rot_z_event_hover(mlx);
}
