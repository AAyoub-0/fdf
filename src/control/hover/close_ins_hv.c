/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_ins_hv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:03:28 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/21 14:53:07 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_btn_event_hover(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[13]) && mlx->show_ins == true)
	{
		mlx->ins[13]->m_over = true;
		if (mlx->ins[13]->bg != GRAY)
		{
			mlx->ins[13]->bg = GRAY;
			draw_instructions(mlx);
		}
	}
	if (!mouse_over_frame(mlx->mouse, mlx->ins[13]) && mlx->show_ins == true)
	{
		mlx->ins[13]->m_over = false;
		if (mlx->ins[13]->bg != WHITE)
		{
			mlx->ins[13]->bg = WHITE;
			draw_instructions(mlx);
		}
	}
}
