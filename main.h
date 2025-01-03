/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:08:18 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/03 17:43:04 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H


#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "./libft/libft.h"
#include "./minilibx_linux/mlx.h"
#include "./gnl/get_next_line.h"

typedef struct s_point
{
    int     x;
    int     y;
    int     z;
    int     color;
}               t_point;

typedef struct s_map
{
    t_point     **points;
    int         width;
    int         height;
}               t_map;

typedef struct s_mlx
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    t_map   *map;
}               t_mlx;

t_map   *parse_map(int fd);

void    draw_line_angle(t_mlx *mlx, t_point start, double length, double angle);
void    draw_map(t_mlx *mlx);

void    init_window(t_mlx *mlx);

#endif