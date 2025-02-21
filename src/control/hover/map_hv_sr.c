/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hv_sr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:53:14 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/21 14:53:07 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_btn_event_hover_19(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[19]) && mlx->show_ins == true)
	{
		mlx->ins[19]->m_over = true;
		if (mlx->ins[19]->bg != GRAY_OV)
		{
			mlx->ins[19]->bg = GRAY_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[19]) && mlx->show_ins == true)
	{
		mlx->ins[19]->m_over = false;
		if (mlx->ins[19]->bg != WHITE && mlx->ins[19]->bg != MAGENTA_9)
		{
			if (mlx->ins[19]->selected)
				mlx->ins[19]->bg = MAGENTA_9;
			else
				mlx->ins[19]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}

void	map_btn_event_hover_20(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[20]) && mlx->show_ins == true)
	{
		mlx->ins[20]->m_over = true;
		if (mlx->ins[20]->bg != GRAY_OV)
		{
			mlx->ins[20]->bg = GRAY_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[20]) && mlx->show_ins == true)
	{
		mlx->ins[20]->m_over = false;
		if (mlx->ins[20]->bg != WHITE && mlx->ins[20]->bg != MAGENTA_9)
		{
			if (mlx->ins[20]->selected)
				mlx->ins[20]->bg = MAGENTA_9;
			else
				mlx->ins[20]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}

void	map_btn_event_hover_21(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[21]) && mlx->show_ins == true)
	{
		mlx->ins[21]->m_over = true;
		if (mlx->ins[21]->bg != GRAY_OV)
		{
			mlx->ins[21]->bg = GRAY_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[21]) && mlx->show_ins == true)
	{
		mlx->ins[21]->m_over = false;
		if (mlx->ins[21]->bg != WHITE && mlx->ins[21]->bg != MAGENTA_9)
		{
			if (mlx->ins[21]->selected)
				mlx->ins[21]->bg = MAGENTA_9;
			else
				mlx->ins[21]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}

void	map_btn_event_hover_22(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[22]) && mlx->show_ins == true)
	{
		mlx->ins[22]->m_over = true;
		if (mlx->ins[22]->bg != GRAY_OV)
		{
			mlx->ins[22]->bg = GRAY_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[22]) && mlx->show_ins == true)
	{
		mlx->ins[22]->m_over = false;
		if (mlx->ins[22]->bg != WHITE && mlx->ins[22]->bg != MAGENTA_9)
		{
			if (mlx->ins[22]->selected)
				mlx->ins[22]->bg = MAGENTA_9;
			else
				mlx->ins[22]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}

void	map_btn_event_hover_23(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[23]) && mlx->show_ins == true)
	{
		mlx->ins[23]->m_over = true;
		if (mlx->ins[23]->bg != GRAY_OV)
		{
			mlx->ins[23]->bg = GRAY_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[23]) && mlx->show_ins == true)
	{
		mlx->ins[23]->m_over = false;
		if (mlx->ins[23]->bg != WHITE && mlx->ins[23]->bg != MAGENTA_9)
		{
			if (mlx->ins[23]->selected)
				mlx->ins[23]->bg = MAGENTA_9;
			else
				mlx->ins[23]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}
