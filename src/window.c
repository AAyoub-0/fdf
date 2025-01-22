/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:36:07 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/22 14:49:45 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	init_window(t_mlx **mlx, int fd)
{
	(*mlx) = malloc(sizeof(t_mlx));
	(*mlx)->mlx = mlx_init();
	(*mlx)->win = mlx_new_window((*mlx)->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	(*mlx)->img = mlx_new_image((*mlx)->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	(*mlx)->addr = mlx_get_data_addr((*mlx)->img, &(*mlx)->bits_per_pixel,
			&(*mlx)->line_length, &(*mlx)->endian);
	(*mlx)->map = parse_map(fd);
}
