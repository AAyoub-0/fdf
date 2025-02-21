/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:43:25 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/21 14:53:07 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	view_event_click(t_mlx *mlx, int id, t_fpoint3d n_rt)
{
	if (id == 13 && mlx->ins[13]->m_over && mlx->show_ins)
	{
		mlx->show_ins = false;
		draw_map(mlx);
		draw_instructions(mlx);
		return ;
	}
	if (id == 10 && mlx->ins[10]->m_over)
		mlx->camera->iso = true;
	if (id == 11 && mlx->ins[11]->m_over)
		mlx->camera->iso = false;
	if (mouse_over_frame(mlx->mouse, mlx->ins[id]) && mlx->show_ins)
	{
		mlx->camera->r_x = n_rt.x;
		mlx->camera->r_y = n_rt.y;
		mlx->camera->r_z = n_rt.z;
		draw_map(mlx);
		draw_instructions(mlx);
	}
}

void	rot_event_click(t_mlx *mlx, int id, t_fpoint3d n_rt)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[id]) && mlx->show_ins)
	{
		mlx->camera->r_x += n_rt.x;
		mlx->camera->r_y += n_rt.y;
		mlx->camera->r_z += n_rt.z;
		draw_map(mlx);
		draw_instructions(mlx);
	}
}

void	map_event_click(t_mlx *mlx, int id)
{
	char	*tmp;

	if (mouse_over_frame(mlx->mouse, mlx->ins[id]) && mlx->show_ins)
	{
		tmp = ft_strjoin("maps/", mlx->ins[id]->data);
		exit_if(!tmp, mlx, EXIT_FAILURE);
		open_map(mlx, tmp);
		set_selected_map_btn(mlx, id);
		draw_map(mlx);
		draw_instructions(mlx);
		free(tmp);
	}
}

void	color_event_click(t_mlx *mlx, int id, t_point3d n_colors)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[id]) && mlx->show_ins)
	{
		mlx->map->c_min = n_colors.x;
		mlx->map->c_mid = n_colors.y;
		mlx->map->c_max = n_colors.z;
		draw_map(mlx);
		draw_instructions(mlx);
	}
}
