#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "libft.h"
# include "ft_printf.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct	s_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			width;
	int			height;
	double		scale;
}				t_window;
typedef struct	s_fractal
{
	double	ca;
	double	cb;
	double	aa;
	double	bb;
	int		iter_max;
	int		limit;
	int		(*ft_calc)(double, double, struct s_fractal *, t_window *);
}			t_fractal;

int		ft_create_image(t_window *window, t_fractal *fractal);
int		ft_get_rgba(int r, int g, int b, int a);
void	ft_prefill_window(t_window *window);
int	ft_calc_mandelbrot(double a, double b, t_fractal *fractal, t_window *window);
double	ft_map(double x, double in_min, double in_max, double out_min, double out_max);
void	ft_parse_input(int argc, char **argv, t_fractal *fractal);

#endif
