/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:52:33 by ayoub             #+#    #+#             */
/*   Updated: 2025/02/21 18:05:55 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	(void)argc;
	(void)argv;
	mlx = init_window("Fdf - 42");
	open_map(mlx, "maps/pyramide.fdf");
	init_hooks(mlx);
	init_instructions(mlx);
	mlx->show_ins = false;
	draw_map(mlx);
	draw_instructions(mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
