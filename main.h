/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:08:18 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/22 17:45:38 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

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

#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#define DEG_TO_RAD(angle) ((angle) * M_PI / 180.0)

# define R_X DEG_TO_RAD(0)
# define R_Y DEG_TO_RAD(0)
# define R_Z DEG_TO_RAD(0)

# define FOV 60
# define SCREEN_WIDTH  800
# define SCREEN_HEIGHT 600

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	int		color;
}			t_point;

typedef struct s_point2d
{
    int x;
    int y;
}           t_point2d;

typedef struct s_map
{
	t_point	**points;
	int		width;
	int		height;
}			t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	*map;
}			t_mlx;

enum
{
	KEYDOWN = 2,
	KEYUP = 3,
	MOUSEDOWN = 4,
	MOUSEUP = 5,
	MOUSEMOVE = 6,
	EXPOSE = 12,
	DESTROY = 17,
	KEYDOWN_MASK = 1L << 0,
	KEYUP_MASK = 1L << 1
};

t_map		*parse_map(int fd);

void        print_point2d(t_point2d *point);
void        print_point3d(t_point *point);

int			draw_map(t_mlx *mlx);

void		init_window(t_mlx **mlx, int fd);
int			handle_no_event(void *data);
int			handle_keydown(int key, t_mlx **mlx);
int			handle_keyup(int key, t_mlx **mlx);
int			handle_destroy(t_mlx **mlx);

#endif