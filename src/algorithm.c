/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:34:20 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/13 17:39:32 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	ft_calc_mandelbrot(double x, double y, t_window *window)
{
	int		iter;
	double	a;
	double	b;
	double	aa;
	double	bb;
	t_fractal	*fractal;

	fractal = window->fractal;
	// a = ft_map(a, 0, window->height, -2.5 * window->scale, 1.5 * window->scale * ((double) window->width/window->height));
	// b = ft_map(b, 0, window->width, -2 * window->scale, 2 * window->scale * ((double) window->height/window->width));
	a = ft_map(x, 0 + window->offset_x, 800 + window->offset_x, -1.5, 2.5);
	b = ft_map(y, 0 + window->offset_y, 800 + window->offset_y, -1, 3);
	a = a - ((double) window->width / window->height);
	b = b - ((double) window->height / window->width);
	a = a * window->scale;
	b = b * window->scale;

	// a = ft_map(x, 0, window->height, (-2.5 - ((double) window->height / window->width)) * window->scale, (1.5 + ((double) window->height / window->width)) * window->scale);
	// b = ft_map(y, 0, window->width, (-2 - ((double) window->width / window->height)) * window->scale, (2 + ((double) window->width / window->height)) * window->scale);
	fractal->ca = a;
	fractal->cb = b;
	iter = 0;
	while (iter < fractal->iter_max)
	{
		aa = a * a;
		bb = b * b;
		fractal->aa = aa - bb;
		fractal->bb = 2 * a * b;
		a = fractal->aa + fractal-> ca;
		b = fractal->bb + fractal->cb;
		if (aa + bb > fractal->limit)
			break ;
		iter++;
	}
	return (iter);
}

int	ft_calc_julia(double x, double y, t_window *window)
{
	int		iter;
	double	a;
	double	b;
	t_fractal	*fractal;

	fractal = window->fractal;
	// a = ft_map(a, 0, window->height, -2.5 * window->scale, 1.5 * window->scale * ((double) window->width/window->height));
	// b = ft_map(b, 0, window->width, -2 * window->scale, 2 * window->scale * ((double) window->height/window->width));
	a = ft_map(x, 0 + window->offset_x, 800 + window->offset_x, -1, 3);
	b = ft_map(y, 0 + window->offset_y, 800 + window->offset_y, -1, 3);
	a = a - ((double) window->width / window->height);
	b = b - ((double) window->height / window->width);
	a = a * window->scale;
	b = b * window->scale;

	// a = ft_map(x, 0, window->height, (-2.5 - ((double) window->height / window->width)) * window->scale, (1.5 + ((double) window->height / window->width)) * window->scale);
	// b = ft_map(y, 0, window->width, (-2 - ((double) window->width / window->height)) * window->scale, (2 + ((double) window->width / window->height)) * window->scale);
	iter = 0;
	while (iter < fractal->iter_max)
	{
		fractal->aa = a * a - b * b;
		fractal->bb = 2 * a * b;
		a = fractal->aa + fractal-> ca;
		b = fractal->bb + fractal->cb;
		if (a * a + b * b > fractal->limit)
			break ;
		iter++;
	}
	return (iter);
}
