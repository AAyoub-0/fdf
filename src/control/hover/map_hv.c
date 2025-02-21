/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:41:44 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/21 14:53:07 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_btn_event_hover_29(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[29]) && mlx->show_ins == true)
	{
		mlx->ins[29]->m_over = true;
		if (mlx->ins[29]->bg != GRAY_OV)
		{
			mlx->ins[29]->bg = GRAY_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[29]) && mlx->show_ins == true)
	{
		mlx->ins[29]->m_over = false;
		if (mlx->ins[29]->bg != WHITE && mlx->ins[29]->bg != MAGENTA_9)
		{
			if (mlx->ins[29]->selected)
				mlx->ins[29]->bg = MAGENTA_9;
			else
				mlx->ins[29]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}

void	map_btn_event_hover_30(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[30]) && mlx->show_ins == true)
	{
		mlx->ins[30]->m_over = true;
		if (mlx->ins[30]->bg != GRAY_OV)
		{
			mlx->ins[30]->bg = GRAY_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[30]) && mlx->show_ins == true)
	{
		mlx->ins[30]->m_over = false;
		if (mlx->ins[30]->bg != WHITE && mlx->ins[30]->bg != MAGENTA_9)
		{
			if (mlx->ins[30]->selected)
				mlx->ins[30]->bg = MAGENTA_9;
			else
				mlx->ins[30]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}

void	map_btn_event_hover(t_mlx *mlx)
{
	map_btn_event_hover_14(mlx);
	map_btn_event_hover_15(mlx);
	map_btn_event_hover_16(mlx);
	map_btn_event_hover_17(mlx);
	map_btn_event_hover_18(mlx);
	map_btn_event_hover_19(mlx);
	map_btn_event_hover_20(mlx);
	map_btn_event_hover_21(mlx);
	map_btn_event_hover_22(mlx);
	map_btn_event_hover_23(mlx);
	map_btn_event_hover_24(mlx);
	map_btn_event_hover_25(mlx);
	map_btn_event_hover_26(mlx);
	map_btn_event_hover_27(mlx);
	map_btn_event_hover_28(mlx);
	map_btn_event_hover_29(mlx);
	map_btn_event_hover_30(mlx);
}
