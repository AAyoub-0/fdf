/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_ctl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:36:13 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/18 15:22:23 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	proj_event_hover_10(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[10]) && mlx->show_ins == true)
	{
		mlx->ins[10]->m_over = true;
		if (mlx->ins[10]->bg != GREEN_OV)
		{
			mlx->ins[10]->bg = GREEN_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[10]) && mlx->show_ins == true)
	{
		mlx->ins[10]->m_over = false;
		if (mlx->ins[10]->bg != GREEN)
		{	
			mlx->ins[10]->bg = GREEN;
			draw_instructions(mlx);
		}
	}
}

void	proj_event_hover_11(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[11]) && mlx->show_ins == true)
	{
		mlx->ins[11]->m_over = true;
		if (mlx->ins[11]->bg != GREEN_OV)
		{
			mlx->ins[11]->bg = GREEN_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[11]) && mlx->show_ins == true)
	{
		mlx->ins[11]->m_over = false;
		if (mlx->ins[11]->bg != GREEN)
		{	
			mlx->ins[11]->bg = GREEN;
			draw_instructions(mlx);
		}
	}
}

void	proj_event_hover_12(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[12]) && mlx->show_ins == true)
	{
		mlx->ins[12]->m_over = true;
		if (mlx->ins[12]->bg != GREEN_OV)
		{
			mlx->ins[12]->bg = GREEN_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[12]) && mlx->show_ins == true)
	{
		mlx->ins[12]->m_over = false;
		if (mlx->ins[12]->bg != GREEN)
		{	
			mlx->ins[12]->bg = GREEN;
			draw_instructions(mlx);
		}
	}
}

void	proj_event_hover(t_mlx *mlx)
{
	proj_event_hover_10(mlx);
	proj_event_hover_11(mlx);
	proj_event_hover_12(mlx);
}
