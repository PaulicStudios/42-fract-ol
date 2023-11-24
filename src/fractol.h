/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:06:26 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/13 18:06:47 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>

# define WIDTH 800
# define HEIGHT 800

typedef enum e_type
{
	MANDELBROT,
	JULIA,
	SHIP,
	FERN
}	t_type;
typedef struct s_win	t_win;
typedef struct s_fract
{
	double	a;
	double	b;
	double	ca;
	double	cb;
	int		ca_int;
	int		cb_int;
	double	aa;
	double	bb;
	double	ca_aa;
	double	ca_bb;
	int		iter_max;
	double	limit;
	t_type	type;
	int		(*ft_calc)(double, double, struct s_win *);
}			t_fract;
typedef struct s_mouse
{
	int		last_x;
	int		last_y;
	bool	button_pressed;
}			t_mouse;
struct	s_win
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_fract		*fract;
	int			width;
	int			height;
	double		off_x;
	double		off_y;
	double		scale;
	bool		rebuilding;
	t_mouse		mouse;
};

//fract-ol.c
void			ft_exit(char *msg);
void			ft_exit_loop(char *msg, t_win *win);

//input_parser.c
void			ft_parse_input(int argc, char **argv, t_win *win);

//setup_fract.c
void			ft_setup_mandelbrot(t_win *win);
void			ft_setup_julia(t_win *win);
void			ft_setup_ship(t_win *win);
void			ft_setup_fern(t_win *win);

//algorithm.c
int				ft_calc_mandelbrot(double a, double b, t_win *win);
int				ft_calc_julia(double x, double y, t_win *win);
int				ft_calc_ship(double x, double y, t_win *win);

//algorithm_fern.c
void			ft_fill_fern(t_win *win);

//fern_util.c
unsigned int	ft_random_nbr(void);
double			ft_random_zero_one(void);
void			ft_fill_white(t_win *win);

//mlxmanager.c
void			ft_rebuild_fract(t_win *win);

//mlxhooks.c
void			ft_resize_hook(int width, int height, void *win);
void			ft_scroll_hook(double xdelta, double ydelta, void *param);
void			ft_key_hook(mlx_key_data_t keydata, void *param);
void			ft_loop_hook(void *param);

//hook_helper.c
void			ft_drag_mouse(int mouse_x, int mouse_y, t_win *win);
void			ft_drag_mouse_shift(int mouse_x, int mouse_y, t_win *win);
bool			ft_key_change_values(mlx_key_data_t keydata, t_win *win);
void			ft_scroll_not_fern(double *mouse_x, double *mouse_y,
					double *factor, t_win *win);
double			ft_get_factor(double ydelta, t_win *win);

//utils.c
int				ft_get_rgba(int r, int g, int b, int a);
void			ft_prefill_win(t_win *win, t_fract *fract);
double			ft_abs(double x);

#endif
