/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:44:23 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/24 15:19:02 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	view_rot_event(t_mlx *mlx)
{
	view_event_click(mlx, 2, (t_fpoint3d){-1.5708, 0, 0});
	view_event_click(mlx, 3, (t_fpoint3d){0, 1.5708, 0});
	view_event_click(mlx, 4, (t_fpoint3d){0, -1.5708, 0});
	view_event_click(mlx, 5, (t_fpoint3d){0, 0, 0});
	view_event_click(mlx, 6, (t_fpoint3d){0, -3.14159, 0});
	rot_event_click(mlx, 7, (t_fpoint3d){0.1, 0, 0});
	rot_event_click(mlx, 8, (t_fpoint3d){0, 0.1, 0});
	rot_event_click(mlx, 9, (t_fpoint3d){0, 0, 0.1});
	view_event_click(mlx, 10, (t_fpoint3d){0, 0, 0});
	view_event_click(mlx, 11, (t_fpoint3d){0, 0, 0});
	view_event_click(mlx, 13, (t_fpoint3d){0, 0, 0});
}

void	map_event(t_mlx *mlx)
{
	map_event_click(mlx, 14);
	map_event_click(mlx, 15);
	map_event_click(mlx, 16);
	map_event_click(mlx, 17);
	map_event_click(mlx, 18);
	map_event_click(mlx, 19);
	map_event_click(mlx, 20);
	map_event_click(mlx, 21);
	map_event_click(mlx, 22);
	map_event_click(mlx, 23);
	map_event_click(mlx, 24);
	map_event_click(mlx, 25);
	map_event_click(mlx, 26);
	map_event_click(mlx, 27);
	map_event_click(mlx, 28);
	map_event_click(mlx, 29);
	map_event_click(mlx, 30);
}

void	color_event(t_mlx *mlx)
{
	color_event_click(mlx, 31, (t_point3d){WHITE, YELLOW, MAGENTA});
	color_event_click(mlx, 32, (t_point3d){CYAN, BROWN_OV, GREEN});
	color_event_click(mlx, 33, (t_point3d){GREEN_OV, BROWN_OV, BROWN});
}
