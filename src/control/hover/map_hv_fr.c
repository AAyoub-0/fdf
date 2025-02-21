/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hv_fr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:52:22 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/21 14:53:07 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_btn_event_hover_14(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[14]) && mlx->show_ins == true)
	{
		mlx->ins[14]->m_over = true;
		if (mlx->ins[14]->bg != GRAY_OV)
		{
			mlx->ins[14]->bg = GRAY_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[14]) && mlx->show_ins == true)
	{
		mlx->ins[14]->m_over = false;
		if (mlx->ins[14]->bg != WHITE && mlx->ins[14]->bg != MAGENTA_9)
		{
			if (mlx->ins[14]->selected)
				mlx->ins[14]->bg = MAGENTA_9;
			else
				mlx->ins[14]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}

void	map_btn_event_hover_15(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[15]) && mlx->show_ins == true)
	{
		mlx->ins[15]->m_over = true;
		if (mlx->ins[15]->bg != GRAY_OV)
		{
			mlx->ins[15]->bg = GRAY_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[15]) && mlx->show_ins == true)
	{
		mlx->ins[15]->m_over = false;
		if (mlx->ins[15]->bg != WHITE && mlx->ins[15]->bg != MAGENTA_9)
		{
			if (mlx->ins[15]->selected)
				mlx->ins[15]->bg = MAGENTA_9;
			else
				mlx->ins[15]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}

void	map_btn_event_hover_16(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[16]) && mlx->show_ins == true)
	{
		mlx->ins[16]->m_over = true;
		if (mlx->ins[16]->bg != GRAY_OV)
		{
			mlx->ins[16]->bg = GRAY_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[16]) && mlx->show_ins == true)
	{
		mlx->ins[16]->m_over = false;
		if (mlx->ins[16]->bg != WHITE && mlx->ins[16]->bg != MAGENTA_9)
		{
			if (mlx->ins[16]->selected)
				mlx->ins[16]->bg = MAGENTA_9;
			else
				mlx->ins[16]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}

void	map_btn_event_hover_17(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[17]) && mlx->show_ins == true)
	{
		mlx->ins[17]->m_over = true;
		if (mlx->ins[17]->bg != GRAY_OV)
		{
			mlx->ins[17]->bg = GRAY_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[17]) && mlx->show_ins == true)
	{
		mlx->ins[17]->m_over = false;
		if (mlx->ins[17]->bg != WHITE && mlx->ins[17]->bg != MAGENTA_9)
		{
			if (mlx->ins[17]->selected)
				mlx->ins[17]->bg = MAGENTA_9;
			else
				mlx->ins[17]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}

void	map_btn_event_hover_18(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[18]) && mlx->show_ins == true)
	{
		mlx->ins[18]->m_over = true;
		if (mlx->ins[18]->bg != GRAY_OV)
		{
			mlx->ins[18]->bg = GRAY_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[18]) && mlx->show_ins == true)
	{
		mlx->ins[18]->m_over = false;
		if (mlx->ins[18]->bg != WHITE && mlx->ins[18]->bg != MAGENTA_9)
		{
			if (mlx->ins[18]->selected)
				mlx->ins[18]->bg = MAGENTA_9;
			else
				mlx->ins[18]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}
