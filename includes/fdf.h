/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:08:18 by aayoub            #+#    #+#             */
/*   Updated: 2025/02/25 14:03:25 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_linux/mlx.h"
# include "fdf_strings.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>

# ifndef FDF_BONUS
#  define FDF_BONUS 0
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

typedef enum e_color
{
	RED = 0xB22222,
	RED_OV = 0xFA8072,
	GREEN = 0x228B22,
	GREEN_OV = 0x3CB371,
	GREEN_D = 0x006400,
	BROWN = 0x8B4513,
	BROWN_OV = 0xD2B48C,
	BLUE = 0x4169E1,
	BLUE_OV = 0x87CEEB,
	WHITE = 0xFFFFFF,
	BLACK = 0x000000,
	YELLOW = 0xFFFF00,
	CYAN = 0x00FFFF,
	CYAN_OV = 0xCCFFFF,
	CYAN_D = 0x008888,
	MAGENTA = 0xFF00FF,
	MAGENTA_9 = 0x990099,
	GRAY = 0x808080,
	GRAY_OV = 0xA0A0A0,
	ORANGE = 0xFFA500,
	ORANGE_OV = 0xFFC178
}				t_color;

typedef enum e_hook
{
	ON_DESTROY = 17,
	ON_MOUSEDOWN = 4,
	ON_MOSEUP = 5
}				t_hook;

typedef struct s_point3d
{
	int			x;
	int			y;
	int			z;
}				t_point3d;

typedef struct s_fpoint3d
{
	float		x;
	float		y;
	float		z;
}				t_fpoint3d;

typedef struct s_point2d
{
	int			x;
	int			y;
}				t_point2d;

typedef struct s_calc_draw
{
	t_point2d	delta;
	t_point2d	sign;
	int			error[2];
}				t_calc_draw;

typedef struct s_frame
{
	void		*data;
	int			height;
	int			width;
	int			border;
	t_color		bg;
	t_color		b_clr;
	t_bool		m_over;
	t_bool		selected;
	t_point2d	coord;
}				t_frame;

typedef struct s_map
{
	t_color		c_max;
	t_color		c_mid;
	t_color		c_min;
	int			width;
	int			height;
	int			z_min;
	int			z_mid;
	int			z_max;
	int			fd;
	char		*file;
	t_point3d	**pts_3d;
}				t_map;

typedef struct s_camera
{
	t_bool		iso;
	int			zoom;
	int			x_offset;
	int			y_offset;
	int			z_offset;
	int			m_rad;
	float		r_x;
	float		r_y;
	float		r_z;
}				t_camera;

typedef struct s_mouse
{
	int			x;
	int			y;
	int			prev_x;
	int			prev_y;
	int			button;
	t_bool		is_pressed;
}				t_mouse;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_map		*map;
	t_camera	*camera;
	t_mouse		*mouse;
	t_frame		**ins;
	t_bool		show_ins;
	t_bool		bonus;
}				t_mlx;

t_point3d		*init_point3d(int x, int y, int z);
t_point2d		*init_point2d(int x, int y);
t_bool			free_points3d(t_point3d **point, size_t size);

t_point2d		project_point3d(t_point3d p3d, t_map *map, t_camera *c);

t_map			*init_map(void);
t_bool			check_extension(char *file);
char			*sub_argv(char *av);
void			set_z_max_min(t_map *map, int z);
int				get_map_width(char *line);
void			parse_map(t_mlx *mlx, int fd);
void			open_map(t_mlx *mlx, char *file);
int				free_map(t_map *map);

uint32_t		get_gradient_color(t_map *map, int step, t_point2d delta,
					t_point2d p3d_z);

void			draw_line(t_mlx *mlx, t_point2d p0, t_point2d p1,
					t_point2d p3d_coor);
void			draw_line_simple(t_mlx *mlx, t_point2d p0, t_point2d p1,
					t_color color);
void			set_errors(t_calc_draw *calc, t_point2d *p0);
void			draw_vectors(t_mlx *mlx, t_point2d *p3d_z, t_point2d *i);
t_bool			fill_map_point(t_map **map, char *line, int x, int y);
t_bool			fill_map(t_map *map, char *line, int y);
void			parse_map_line(t_mlx *mlx, char *line);
int				draw_map(t_mlx *mlx);

t_mlx			*init_window(char *color_btn_event_hovername);
int				free_window(t_mlx *mlx, int fd_out);

void			keyboard_events(int key, t_mlx *mlx);
int				mouse_down(int button, int x, int y, t_mlx *mlx);
int				mouse_up(int button, int x, int y, t_mlx *mlx);
int				mouse_move(int x, int y, t_mlx *mlx);
void			init_hooks(t_mlx *mlx);

t_frame			*init_frame(t_point2d coor, int width, int height, t_color bg);
void			draw_frame(t_mlx *mlx, t_frame *frame);
t_bool			free_frames(t_frame **frame);

void			init_instructions(t_mlx *mlx);
t_bool			mouse_over_frame(t_mouse *m, t_frame *f);
void			draw_instructions(t_mlx *mlx);

void			init_ctl_btn(t_mlx *mlx);
void			init_maps_btn(t_mlx *mlx);
void			init_maps_data(char **maps);
void			draw_maps_texts(t_mlx *mlx);
void			set_selected_map_btn(t_mlx *mlx, int i);

void			view_event_click(t_mlx *mlx, int id, t_fpoint3d n_rt);
void			rot_event_click(t_mlx *mlx, int id, t_fpoint3d n_rt);
void			map_event_click(t_mlx *mlx, int id);
void			color_event_click(t_mlx *mlx, int id, t_point3d n_colors);
void			view_rot_event(t_mlx *mlx);
void			map_event(t_mlx *mlx);
void			color_event(t_mlx *mlx);

void			map_btn_event_hover_14(t_mlx *mlx);
void			map_btn_event_hover_15(t_mlx *mlx);
void			map_btn_event_hover_16(t_mlx *mlx);
void			map_btn_event_hover_17(t_mlx *mlx);
void			map_btn_event_hover_18(t_mlx *mlx);
void			map_btn_event_hover_19(t_mlx *mlx);
void			map_btn_event_hover_20(t_mlx *mlx);
void			map_btn_event_hover_21(t_mlx *mlx);
void			map_btn_event_hover_22(t_mlx *mlx);
void			map_btn_event_hover_23(t_mlx *mlx);
void			map_btn_event_hover_24(t_mlx *mlx);
void			map_btn_event_hover_25(t_mlx *mlx);
void			map_btn_event_hover_26(t_mlx *mlx);
void			map_btn_event_hover_27(t_mlx *mlx);
void			map_btn_event_hover_28(t_mlx *mlx);

void			menu_frame_event_hover(t_mlx *mlx);
void			close_btn_event_hover(t_mlx *mlx);
void			view_face_event_hover(t_mlx *mlx);
void			view_right_event_hover(t_mlx *mlx);
void			view_left_event_hover(t_mlx *mlx);
void			view_up_event_hover(t_mlx *mlx);
void			view_down_event_hover(t_mlx *mlx);
void			rot_event_hover(t_mlx *mlx);
void			proj_event_hover(t_mlx *mlx);
void			map_btn_event_hover(t_mlx *mlx);
void			color_btn_event_hover(t_mlx *mlx);

void			exit_if(t_bool cond, t_mlx *mlx, int fd_out, ...);
int				ft_abs(int n);

void			exec_tests(void);

#endif