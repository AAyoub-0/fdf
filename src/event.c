/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:49:22 by aboumall          #+#    #+#             */
/*   Updated: 2025/01/08 16:49:38 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	handle_no_event(void *data)
{
	return (0);
}

int	handle_keydown(int key, t_mlx **mlx)
{
	return (0);
}

int handle_keyup(int key, t_mlx **mlx)
{
	if (key == XK_Escape)
        handle_destroy(mlx);
	return (0);
}

int	handle_destroy(t_mlx **mlx)
{
	mlx_destroy_window((*mlx)->mlx, (*mlx)->win);
	return (0);
}
