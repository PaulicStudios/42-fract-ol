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
struct	s_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_fractal	*fractal;
	int			width;
	int			height;
	double		scale;
	bool		rebuilding;
};

void	ft_resize_hook(int width, int height, void *window);
int		ft_get_rgba(int r, int g, int b, int a);
void	ft_prefill_window(t_window *window, t_fractal *fractal);
int		ft_calc_mandelbrot(double a, double b, t_window *window);
double	ft_map(double x, double in_min, double in_max, double out_min, double out_max);
void	ft_parse_input(int argc, char **argv, t_fractal *fractal);
void	ft_rebuild_fractal(t_window *window);

#endif
