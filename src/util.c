/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:37:20 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/12 15:52:32 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	ft_get_rgba(int r, int g, int b, int a)
{
	return ((unsigned int)r << 24 | (unsigned int)g << 16 | (unsigned int)b << 8 | (unsigned int)a);
}

double	ft_map(double x, double in_min, double in_max, double out_min, double out_max)
{
	return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

void	ft_prefill_window(t_window *window, t_fractal *fractal)
{
	window->height = HEIGHT;
	window->width = WIDTH;
	window->scale = 1;
	window->fractal = fractal;
	window->image = NULL;
	window->rebuilding = false;
	window->offset_x = 0;
	window->offset_y = 0;
}
