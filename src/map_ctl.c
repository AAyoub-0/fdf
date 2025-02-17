/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ctl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:41:44 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/17 16:50:46 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
		if (mlx->ins[14]->bg != WHITE && mlx->ins[14]->bg != MAGENTA)
		{	
			if (mlx->ins[14]->selected)
				mlx->ins[14]->bg = MAGENTA;
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
		if (mlx->ins[15]->bg != WHITE && mlx->ins[15]->bg != MAGENTA)
		{	
			if (mlx->ins[15]->selected)
				mlx->ins[15]->bg = MAGENTA;
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
		if (mlx->ins[16]->bg != WHITE && mlx->ins[16]->bg != MAGENTA)
		{	
			if (mlx->ins[16]->selected)
				mlx->ins[16]->bg = MAGENTA;
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
		if (mlx->ins[17]->bg != WHITE && mlx->ins[17]->bg != MAGENTA)
		{	
			if (mlx->ins[17]->selected)
				mlx->ins[17]->bg = MAGENTA;
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
		if (mlx->ins[18]->bg != WHITE && mlx->ins[18]->bg != MAGENTA)
		{	
			if (mlx->ins[18]->selected)
				mlx->ins[18]->bg = MAGENTA;
			else
				mlx->ins[18]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}

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
		if (mlx->ins[19]->bg != WHITE && mlx->ins[19]->bg != MAGENTA)
		{	
			if (mlx->ins[19]->selected)
				mlx->ins[19]->bg = MAGENTA;
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
		if (mlx->ins[20]->bg != WHITE && mlx->ins[20]->bg != MAGENTA)
		{	
			if (mlx->ins[20]->selected)
				mlx->ins[20]->bg = MAGENTA;
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
		if (mlx->ins[21]->bg != WHITE && mlx->ins[21]->bg != MAGENTA)
		{	
			if (mlx->ins[21]->selected)
				mlx->ins[21]->bg = MAGENTA;
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
		if (mlx->ins[22]->bg != WHITE && mlx->ins[22]->bg != MAGENTA)
		{	
			if (mlx->ins[22]->selected)
				mlx->ins[22]->bg = MAGENTA;
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
		if (mlx->ins[23]->bg != WHITE && mlx->ins[23]->bg != MAGENTA)
		{	
			if (mlx->ins[23]->selected)
				mlx->ins[23]->bg = MAGENTA;
			else
				mlx->ins[23]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}

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
		if (mlx->ins[24]->bg != WHITE && mlx->ins[24]->bg != MAGENTA)
		{	
			if (mlx->ins[24]->selected)
				mlx->ins[24]->bg = MAGENTA;
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
		if (mlx->ins[25]->bg != WHITE && mlx->ins[25]->bg != MAGENTA)
		{	
			if (mlx->ins[25]->selected)
				mlx->ins[25]->bg = MAGENTA;
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
		if (mlx->ins[26]->bg != WHITE && mlx->ins[26]->bg != MAGENTA)
		{	
			if (mlx->ins[26]->selected)
				mlx->ins[26]->bg = MAGENTA;
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
		if (mlx->ins[27]->bg != WHITE && mlx->ins[27]->bg != MAGENTA)
		{	
			if (mlx->ins[27]->selected)
				mlx->ins[27]->bg = MAGENTA;
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
		if (mlx->ins[28]->bg != WHITE && mlx->ins[28]->bg != MAGENTA)
		{	
			if (mlx->ins[28]->selected)
				mlx->ins[28]->bg = MAGENTA;
			else
				mlx->ins[28]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}

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
		if (mlx->ins[29]->bg != WHITE && mlx->ins[29]->bg != MAGENTA)
		{	
			if (mlx->ins[29]->selected)
				mlx->ins[29]->bg = MAGENTA;
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
		if (mlx->ins[30]->bg != WHITE && mlx->ins[30]->bg != MAGENTA)
		{
			if (mlx->ins[30]->selected)
				mlx->ins[30]->bg = MAGENTA;
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
