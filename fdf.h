/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:08:18 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/30 19:47:26 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./minilibx_linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SCREEN_WIDTH  800
# define SCREEN_HEIGHT 600

typedef enum e_colors
{
	RED = 0xB22222,
	GREEN = 0x90EE90,
	BLUE = 0x0000FF,
	WHITE = 0xFFFFFF,
	BLACK = 0x000000,
	YELLOW = 0xFFFF00,
	CYAN = 0x00FFFF,
	MAGENTA = 0xFF00FF,
	GRAY = 0x808080,
	ORANGE = 0xFFA500,
}           t_colors;

typedef struct s_point3d
{
	int		x;
	int		y;
	int		z;
	t_colors		color;
}           t_point3d;

typedef struct s_point2d
{
	int		x;
	int		y;
}           t_point2d;

typedef struct s_map
{
	t_point3d	**pts_3d;
	t_point2d	**pts_2d;
	int		width;
	int		height;
	int		zoom;
	int		z_div;
	float	r_x;
	float	r_y;
	float	r_z;
}           t_map;

void		print_point(void *p, t_bool is3d);
t_point3d	*init_point3d(int x, int y, int z, t_colors color);
t_point2d	*init_point2d(int x, int y);
t_bool  	free_points3d(t_point3d **point, size_t size);
t_bool  	free_points2d(t_point2d **point, size_t size);

t_map		*init_map(void);
t_bool		parse_map(t_map *map, int fd);
t_bool		free_map(t_map *map);

void		exec_tests(void);

#endif