/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:16:42 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/21 14:52:45 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_frame	*init_frame(t_point2d coor, int width, int height, t_color bg)
{
	t_frame *frame;

	frame = malloc(sizeof(t_frame));
	if (!frame)
		return (NULL);
	frame->data = NULL;
	frame->coord.x = coor.x;
	frame->coord.y = coor.y;
	frame->width = width;
	frame->height = height;
	frame->bg = bg;
	frame->m_over = false;
	frame->selected = false;
	return (frame);
}

void	draw_frame(t_mlx *mlx, t_frame *frame)
{
	t_point2d s_coor;
	t_point2d e_coor;

	e_coor = frame->coord;
	s_coor.x = frame->coord.x;
	s_coor.y = frame->coord.y + frame->height;
	while (e_coor.x < frame->coord.x + frame->width)
	{
		draw_line_simple(mlx, e_coor, s_coor, frame->bg);
		e_coor.x++;
		s_coor.x++;
	}
}

t_bool	mouse_over_frame(t_mouse *m, t_frame *f)
{
	return (m->x >= f->coord.x && m->x <= f->coord.x + f->width
				&& m->y >= f->coord.y && m->y <= f->height + f->coord.y);
}

void	menu_frame_event_hover(t_mlx *mlx)
{
	if (mouse_over_frame(mlx->mouse, mlx->ins[1]))
		mlx->ins[1]->m_over = true;
	else
		mlx->ins[1]->m_over = false;
	if (!mouse_over_frame(mlx->mouse, mlx->ins[0]))
		mlx->ins[0]->m_over = false;
	else
		mlx->ins[0]->m_over = true;
}

t_bool	free_frames(t_frame **frame)
{
	int	i;

	i = 0;
	while (frame[i])
	{
		if (frame[i]->data)
			free(frame[i]->data);
		free(frame[i]);
		i++;
	}
	free(frame);
	return (true);
}
