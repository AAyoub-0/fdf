/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:08:18 by aayoub            #+#    #+#             */
/*   Updated: 2025/01/10 18:21:52 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "./gnl/get_next_line.h"
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

# define R_X 30
# define R_Y 0
# define R_Z 30
# define FOV 1

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}			t_point;

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

int			draw_map(t_mlx *mlx);

void		init_window(t_mlx **mlx, int fd);
int			handle_no_event(void *data);
int			handle_keydown(int key, t_mlx **mlx);
int			handle_keyup(int key, t_mlx **mlx);
int			handle_destroy(t_mlx **mlx);

#endif