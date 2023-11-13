/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxmanager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:40:59 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/13 17:39:16 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	ft_color(int iter, t_fractal *fractal)
{
	int		r;
	int		g;
	int		b;
	double	t;

	t = (double) iter / (double) fractal->iter_max;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (ft_get_rgba(r, g, b, 255));
}

void	ft_fill_image(t_window *window)
{
	int			x;
	int			y;
	int			iter;
	t_fractal	*fractal;

	fractal = window->fractal;
	x = 1;
	y = 1;
	while (y < window->height)
	{
		x = 0;
		while (x < window->width)
		{
			iter = fractal->ft_calc(x, y, window);
			mlx_put_pixel(window->image, x, y, ft_color(iter, fractal));
			x++;
		}
		y++;
	}
}

void	ft_rebuild_fractal(t_window *window)
{
	if (window->rebuilding)
		return ;
	window->rebuilding = true;
	if (!window->image)
	{
		window->image = mlx_new_image(window->mlx, window->width, window->height);
		if (!window->image)
			ft_exit("Could not create image");
		if (mlx_image_to_window(window->mlx, window->image, 0, 0) == -1) {
			ft_exit("Could not put image to window");
		};
	}
	mlx_resize_image(window->image, window->width, window->height);
	ft_fill_image(window);
	window->rebuilding = false;
}
