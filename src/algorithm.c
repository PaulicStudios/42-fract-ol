/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:34:20 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/11 16:43:38 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	ft_calc_mandelbrot(double a, double b, t_window *window)
{
	int	iter;
	t_fractal	*fractal;

	fractal = window->fractal;
	// a = ft_map(a, 0, window->height, -2.5 * window->scale, 1.5 * window->scale * ((double) window->width/window->height));
	// b = ft_map(b, 0, window->width, -2 * window->scale, 2 * window->scale * ((double) window->height/window->width));
	a = ft_map(a, 0, window->height, (-2 - ((double) window->height / window->width)) * window->scale, (2 + ((double) window->height / window->width)) * window->scale);
	b = ft_map(b, 0, window->width, (-2 - ((double) window->width / window->height)) * window->scale, (2 + ((double) window->width / window->height)) * window->scale);
	fractal->ca = a;
	fractal->cb = b;
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
