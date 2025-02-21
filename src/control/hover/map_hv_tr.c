/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hv_tr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:54:33 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/21 14:53:07 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_btn_event_hover_24(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[24]) && mlx->show_ins == true)
	{
		mlx->ins[24]->m_over = true;
		if (mlx->ins[24]->bg != GRAY_OV)
		{
			mlx->ins[24]->bg = GRAY_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[24]) && mlx->show_ins == true)
	{
		mlx->ins[24]->m_over = false;
		if (mlx->ins[24]->bg != WHITE && mlx->ins[24]->bg != MAGENTA_9)
		{
			if (mlx->ins[24]->selected)
				mlx->ins[24]->bg = MAGENTA_9;
			else
				mlx->ins[24]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}

void	map_btn_event_hover_25(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[25]) && mlx->show_ins == true)
	{
		mlx->ins[25]->m_over = true;
		if (mlx->ins[25]->bg != GRAY_OV)
		{
			mlx->ins[25]->bg = GRAY_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[25]) && mlx->show_ins == true)
	{
		mlx->ins[25]->m_over = false;
		if (mlx->ins[25]->bg != WHITE && mlx->ins[25]->bg != MAGENTA_9)
		{
			if (mlx->ins[25]->selected)
				mlx->ins[25]->bg = MAGENTA_9;
			else
				mlx->ins[25]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}

void	map_btn_event_hover_26(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[26]) && mlx->show_ins == true)
	{
		mlx->ins[26]->m_over = true;
		if (mlx->ins[26]->bg != GRAY_OV)
		{
			mlx->ins[26]->bg = GRAY_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[26]) && mlx->show_ins == true)
	{
		mlx->ins[26]->m_over = false;
		if (mlx->ins[26]->bg != WHITE && mlx->ins[26]->bg != MAGENTA_9)
		{
			if (mlx->ins[26]->selected)
				mlx->ins[26]->bg = MAGENTA_9;
			else
				mlx->ins[26]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}

void	map_btn_event_hover_27(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[27]) && mlx->show_ins == true)
	{
		mlx->ins[27]->m_over = true;
		if (mlx->ins[27]->bg != GRAY_OV)
		{
			mlx->ins[27]->bg = GRAY_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[27]) && mlx->show_ins == true)
	{
		mlx->ins[27]->m_over = false;
		if (mlx->ins[27]->bg != WHITE && mlx->ins[27]->bg != MAGENTA_9)
		{
			if (mlx->ins[27]->selected)
				mlx->ins[27]->bg = MAGENTA_9;
			else
				mlx->ins[27]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}

void	map_btn_event_hover_28(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[28]) && mlx->show_ins == true)
	{
		mlx->ins[28]->m_over = true;
		if (mlx->ins[28]->bg != GRAY_OV)
		{
			mlx->ins[28]->bg = GRAY_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[28]) && mlx->show_ins == true)
	{
		mlx->ins[28]->m_over = false;
		if (mlx->ins[28]->bg != WHITE && mlx->ins[28]->bg != MAGENTA_9)
		{
			if (mlx->ins[28]->selected)
				mlx->ins[28]->bg = MAGENTA_9;
			else
				mlx->ins[28]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}
