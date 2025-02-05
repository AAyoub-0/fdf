/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cursor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 18:56:35 by mg                #+#    #+#             */
/*   Updated: 2025/02/05 18:15:38 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

void	mlx_cursor_change(void *mlx_ptr, void *win_ptr, int cursor_shape) {
	t_xvar *xvar = (t_xvar *)mlx_ptr;
	t_win_list *win = (t_win_list *)win_ptr;

	Cursor cursor = XCreateFontCursor(xvar->display, cursor_shape);
	XDefineCursor(xvar->display, win->window, cursor);
	XFlush(xvar->display);
}

void	mlx_cursor_reset(void *mlx_ptr, void *win_ptr) {
	t_xvar *xvar = (t_xvar *)mlx_ptr;
	t_win_list *win = (t_win_list *)win_ptr;

	XUndefineCursor(xvar->display, win->window);
	XFlush(xvar->display);
}
