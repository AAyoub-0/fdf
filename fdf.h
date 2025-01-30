/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:08:18 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/30 23:06:32 by ayoub            ###   ########.fr       */
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

typedef enum e_color
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
}           t_color;

typedef enum e_hook
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_DESTROY = 17
}			t_hook;

typedef enum e_key
{
	ESCAPE = 53
} t_key;

typedef struct s_point3d
{
	int		x;
	int		y;
	int		z;
	t_color		color;
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
}           t_map;

typedef struct s_camera
{
	int		zoom;
	int		z_div;
	float	r_x;
	float	r_y;
	float	r_z;
	int		x_offset;
	int		y_offset;
	int		z_offset;
	int		iso;
}           t_camera;

typedef struct s_mouse
{
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
	t_bool		is_pressed;
}           t_mouse;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
	t_map	*map;
	t_camera	*camera;
	t_mouse	*mouse;
}           t_mlx;

void		print_point(void *p, t_bool is3d);
t_point3d	*init_point3d(int x, int y, int z, t_color color);
t_point2d	*init_point2d(int x, int y);
t_bool  	free_points3d(t_point3d **point, size_t size);
t_bool  	free_points2d(t_point2d **point, size_t size);

t_point2d	project_point3d(t_point3d p3d, t_map map, t_camera c);

t_map		*init_map(void);
t_bool		parse_map(t_map *map, int fd);
t_bool		free_map(t_map *map);

void		draw_line(t_mlx *mlx, t_point2d p0, t_point2d p1);

t_mlx		*init_window(char *name);
void		free_window(t_mlx *mlx);

void		init_hooks(t_mlx *mlx);

void		exec_tests(void);

#endif