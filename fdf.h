/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:08:18 by aayoub            #+#    #+#             */
/*   Updated: 2025/02/07 11:47:09 by aboumall         ###   ########.fr       */
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

# define SCREEN_WIDTH  		1920
# define SCREEN_HEIGHT 		1080

# define MOUSE_LEFT 		1
# define MOUSE_RIGHT 		2
# define MOUSE_WHEEL_UP 	4
# define MOUSE_WHEEL_DOWN 	5

typedef enum e_color
{
	RED = 0xB22222,
	RED_OV = 0xFA8072,
	GREEN = 0x228B22,
	GREEN_OV = 0x3CB371,
	BLUE = 0x4169E1,
	BLUE_OV = 0x87CEEB,
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
	ON_DESTROY = 17,
	ON_MOUSEDOWN = 4,
	ON_MOSEUP = 5
}			t_hook;

typedef struct s_point3d
{
	int		x;
	int		y;
	int		z;
	t_color		color;
}           t_point3d;

typedef struct s_fpoint3d
{
	float		x;
	float		y;
	float		z;
}			t_fpoint3d;

typedef struct s_point2d
{
	int		x;
	int		y;
}           t_point2d;

typedef struct s_frame
{
	t_point2d	coord;
	int	height;
	int	width;
	int	border;
	t_color	bg;
	t_color b_clr;
	t_bool	m_over;
}			t_frame;

typedef struct s_map
{
	t_point3d	**pts_3d;
	int		width;
	int		height;
	int		z_min;
	int		z_mid;
	int		z_max;
	t_color	c_max;
	t_color	c_mid;
	t_color	c_min;
	t_bool		need_update;
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
	int		button;
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
	t_frame **ins;
	t_bool	show_ins;
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

uint32_t 	get_gradient_color(t_map map, int step, t_point2d delta, t_point2d p3d_z);

void		draw_line(t_mlx *mlx, t_point2d p0, t_point2d p1, t_point2d p3d_coor);
void		draw_line_simple(t_mlx *mlx, t_point2d p0, t_point2d p1, t_color color);
int			draw_map(t_mlx *mlx);

t_mlx		*init_window(char *name);
void		free_window(t_mlx *mlx);

void		keyboard_events(int key, t_mlx *mlx);
int			mouse_down(int button, int x, int y, t_mlx *mlx);
int			mouse_up(int button, int x, int y, t_mlx *mlx);
int			mouse_move(int x, int y, t_mlx *mlx);
void		init_hooks(t_mlx *mlx);

t_frame		*init_frame(t_point2d coor, int width, int height, t_color bg);
void		draw_frame(t_mlx *mlx, t_frame *frame);
t_bool		free_frames(t_frame **frame);

void		init_instructions(t_mlx *mlx);
t_bool		mouse_over_frame(t_mouse m, t_frame f);
void		draw_instructions(t_mlx *mlx);

void		menu_frame_event_hover(t_mlx *mlx);
void		view_face_event_hover(t_mlx *mlx);
void		view_right_event_hover(t_mlx *mlx);
void		view_left_event_hover(t_mlx *mlx);
void		view_up_event_hover(t_mlx *mlx);
void		view_down_event_hover(t_mlx *mlx);
void		rot_x_event_hover(t_mlx *mlx);
void		rot_y_event_hover(t_mlx *mlx);
void		rot_z_event_hover(t_mlx *mlx);
void		proj_iso_event_hover(t_mlx *mlx);
void		proj_1_event_hover(t_mlx *mlx);
void		proj_2_event_hover(t_mlx *mlx);

void		exec_tests(void);

#endif