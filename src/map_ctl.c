/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ctl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:41:44 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/14 19:09:40 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	map_btn_event_hover_14(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[14]) && mlx->show_ins == true)
	{
		mlx->ins[14]->m_over = true;
		if (mlx->ins[14]->bg != GRAY)
		{
			mlx->ins[14]->bg = GRAY;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[14]) && mlx->show_ins == true)
	{
		mlx->ins[14]->m_over = false;
		if (mlx->ins[14]->bg != WHITE)
		{	
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
		if (mlx->ins[15]->bg != GRAY)
		{
			mlx->ins[15]->bg = GRAY;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[15]) && mlx->show_ins == true)
	{
		mlx->ins[15]->m_over = false;
		if (mlx->ins[15]->bg != WHITE)
		{	
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
		if (mlx->ins[16]->bg != GRAY)
		{
			mlx->ins[16]->bg = GRAY;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[16]) && mlx->show_ins == true)
	{
		mlx->ins[16]->m_over = false;
		if (mlx->ins[16]->bg != WHITE)
		{	
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
		if (mlx->ins[17]->bg != GRAY)
		{
			mlx->ins[17]->bg = GRAY;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[17]) && mlx->show_ins == true)
	{
		mlx->ins[17]->m_over = false;
		if (mlx->ins[17]->bg != WHITE)
		{	
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
		if (mlx->ins[18]->bg != GRAY)
		{
			mlx->ins[18]->bg = GRAY;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[18]) && mlx->show_ins == true)
	{
		mlx->ins[18]->m_over = false;
		if (mlx->ins[18]->bg != WHITE)
		{	
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
		if (mlx->ins[19]->bg != GRAY)
		{
			mlx->ins[19]->bg = GRAY;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[19]) && mlx->show_ins == true)
	{
		mlx->ins[19]->m_over = false;
		if (mlx->ins[19]->bg != WHITE)
		{	
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
		if (mlx->ins[20]->bg != GRAY)
		{
			mlx->ins[20]->bg = GRAY;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[20]) && mlx->show_ins == true)
	{
		mlx->ins[20]->m_over = false;
		if (mlx->ins[20]->bg != WHITE)
		{	
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
		if (mlx->ins[21]->bg != GRAY)
		{
			mlx->ins[21]->bg = GRAY;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[21]) && mlx->show_ins == true)
	{
		mlx->ins[21]->m_over = false;
		if (mlx->ins[21]->bg != WHITE)
		{	
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
		if (mlx->ins[22]->bg != GRAY)
		{
			mlx->ins[22]->bg = GRAY;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[22]) && mlx->show_ins == true)
	{
		mlx->ins[22]->m_over = false;
		if (mlx->ins[22]->bg != WHITE)
		{	
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
		if (mlx->ins[23]->bg != GRAY)
		{
			mlx->ins[23]->bg = GRAY;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[23]) && mlx->show_ins == true)
	{
		mlx->ins[23]->m_over = false;
		if (mlx->ins[23]->bg != WHITE)
		{	
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
		if (mlx->ins[24]->bg != GRAY)
		{
			mlx->ins[24]->bg = GRAY;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[24]) && mlx->show_ins == true)
	{
		mlx->ins[24]->m_over = false;
		if (mlx->ins[24]->bg != WHITE)
		{	
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
		if (mlx->ins[25]->bg != GRAY)
		{
			mlx->ins[25]->bg = GRAY;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[25]) && mlx->show_ins == true)
	{
		mlx->ins[25]->m_over = false;
		if (mlx->ins[25]->bg != WHITE)
		{	
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
		if (mlx->ins[26]->bg != GRAY)
		{
			mlx->ins[26]->bg = GRAY;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[26]) && mlx->show_ins == true)
	{
		mlx->ins[26]->m_over = false;
		if (mlx->ins[26]->bg != WHITE)
		{	
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
		if (mlx->ins[27]->bg != GRAY)
		{
			mlx->ins[27]->bg = GRAY;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[27]) && mlx->show_ins == true)
	{
		mlx->ins[27]->m_over = false;
		if (mlx->ins[27]->bg != WHITE)
		{	
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
		if (mlx->ins[28]->bg != GRAY)
		{
			mlx->ins[28]->bg = GRAY;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[28]) && mlx->show_ins == true)
	{
		mlx->ins[28]->m_over = false;
		if (mlx->ins[28]->bg != WHITE)
		{	
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
		if (mlx->ins[29]->bg != GRAY)
		{
			mlx->ins[29]->bg = GRAY;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[29]) && mlx->show_ins == true)
	{
		mlx->ins[29]->m_over = false;
		if (mlx->ins[29]->bg != WHITE)
		{	
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
		if (mlx->ins[30]->bg != GRAY)
		{
			mlx->ins[30]->bg = GRAY;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[30]) && mlx->show_ins == true)
	{
		mlx->ins[30]->m_over = false;
		if (mlx->ins[30]->bg != WHITE)
		{	
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
