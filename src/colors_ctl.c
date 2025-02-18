/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_ctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:12:46 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/18 15:17:24 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	color_btn_event_hover_31(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[31]) && mlx->show_ins == true)
	{
		mlx->ins[31]->m_over = true;
		if (mlx->ins[31]->bg != ORANGE_OV)
		{
			mlx->ins[31]->bg = ORANGE_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[31]) && mlx->show_ins == true)
	{
		mlx->ins[31]->m_over = false;
		if (mlx->ins[31]->bg != ORANGE)
		{
			mlx->ins[31]->bg = ORANGE;
			draw_instructions(mlx);
		}
	}
}

void	color_btn_event_hover_32(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[32]) && mlx->show_ins == true)
	{
		mlx->ins[32]->m_over = true;
		if (mlx->ins[32]->bg != ORANGE_OV)
		{
			mlx->ins[32]->bg = ORANGE_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[32]) && mlx->show_ins == true)
	{
		mlx->ins[32]->m_over = false;
		if (mlx->ins[32]->bg != ORANGE)
		{
			mlx->ins[32]->bg = ORANGE;
			draw_instructions(mlx);
		}
	}
}

void	color_btn_event_hover_33(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[33]) && mlx->show_ins == true)
	{
		mlx->ins[33]->m_over = true;
		if (mlx->ins[33]->bg != ORANGE_OV)
		{
			mlx->ins[33]->bg = ORANGE_OV;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[33]) && mlx->show_ins == true)
	{
		mlx->ins[33]->m_over = false;
		if (mlx->ins[33]->bg != ORANGE)
		{
			mlx->ins[33]->bg = ORANGE;
			draw_instructions(mlx);
		}
	}
}

void	color_btn_event_hover(t_mlx *mlx)
{
	color_btn_event_hover_31(mlx);
	color_btn_event_hover_32(mlx);
	color_btn_event_hover_33(mlx);
}
