/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set_font.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:30:47 by amalliar          #+#    #+#             */
/*   Updated: 2025/02/05 14:17:48 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

/*
** Allows to specify the font that will be used by mlx_string_put.
**
** Note: only fixed-width bitmap fonts are supported by Xlib, refer to xfontsel
** utility to get valid font names for this function.
*/

void	mlx_set_font(t_xvar *xvar, t_win_list *win, char *name)
{
	static Font		font = 0;

	if (font)
		XUnloadFont(xvar->display, font);
	font = XLoadFont(xvar->display, name);
	XSetFont(xvar->display, win->gc, font);
}
