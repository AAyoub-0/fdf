/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:16:42 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/05 17:56:13 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_frame	*init_frame(t_point2d coor, int width, int height, t_color bg)
{
	t_frame *frame;

	frame = malloc(sizeof(t_frame));
	frame->coord.x = coor.x;
	frame->coord.y = coor.y;
	frame->width = width;
	frame->height = height;
	frame->bg = bg;
	frame->m_over = false;
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

t_bool	free_frames(t_frame **frame)
{
	int	i;

	i = 0;
	while (frame[i])
	{
		free(frame[i]->class);
		free(frame[i]);
		i++;
	}
	free(frame);
	return (true);
}
