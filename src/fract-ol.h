#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "libft.h"
# include "ft_printf.h"
# include <math.h>
# include <stdio.h>
# include <stdbool.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_window t_window;
typedef struct	s_fractal
{
	double	ca;
	double	cb;
	double	aa;
	double	bb;
	int		iter_max;
	int		limit;
	int		(*ft_calc)(double, double, struct s_window *);
}			t_fractal;
typedef struct	s_mouse
{
	int		last_x;
	int		last_y;
	bool	button_pressed;
}			t_mouse;
struct	s_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_fractal	*fractal;
	int			width;
	int			height;
	int			offset_x;
	int			offset_y;
	double		scale;
	bool		rebuilding;
	t_mouse		mouse;
};

//fract-ol.c
void	ft_exit(char *msg);
void	ft_exit_loop(char *msg, t_window *window);

//input_parser.c
void	ft_parse_input(int argc, char **argv, t_fractal *fractal);

//algorithm.c
int		ft_calc_mandelbrot(double a, double b, t_window *window);

//mlxmanager.c
void	ft_rebuild_fractal(t_window *window);

//mlxhooks.c
void	ft_resize_hook(int width, int height, void *window);
void	ft_scroll_hook(double xdelta, double ydelta, void *param);
void	ft_key_hook(mlx_key_data_t keydata, void *param);
void	ft_loop_hook(void *param);

//utils.c
int		ft_get_rgba(int r, int g, int b, int a);
void	ft_prefill_window(t_window *window, t_fractal *fractal);
double	ft_map(double x, double in_min, double in_max, double out_min, double out_max);

#endif
