/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:52:33 by ayoub             #+#    #+#             */
/*   Updated: 2025/02/25 13:39:30 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	char	*name;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf <map_path>\n", 2);
		return (EXIT_FAILURE);
	}
	if (!check_extension(argv[1]))
	{
		ft_putstr_fd("Error\nMaps must be .fdf files\n", 2);
		return (EXIT_FAILURE);
	}
	name = sub_argv(argv[1]);
	exit_if(!name, NULL, EXIT_FAILURE, NULL);
	mlx = init_window(name);
	open_map(mlx, argv[1]);
	init_instructions(mlx);
	init_hooks(mlx);
	mlx->show_ins = false;
	mlx->bonus = FDF_BONUS;
	draw_map(mlx);
	draw_instructions(mlx);
	mlx_loop(mlx->mlx);
	return (EXIT_SUCCESS);
}
