/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:17:22 by aboumall          #+#    #+#             */
/*   Updated: 2025/02/21 14:54:53 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_if(t_bool cond, t_mlx *mlx, int fd_out)
{
	if (cond == true)
		exit(free_window(mlx, fd_out));
}
