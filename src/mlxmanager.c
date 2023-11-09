/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxmanager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:40:59 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/08 16:05:37 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	ft_create_image(t_window *window, t_fractal *fractal)
{
	int	x;
	int	y;
	int	iter;

	window->image = mlx_new_image(window->mlx, window->height, window->width);
	if (!window->image)
		return (0);
	x = 1;
	y = 1;
	while (y < window->height)
	{
		x = 0;
		while (x < window->width)
		{
			iter = fractal->ft_calc(x, y, fractal, window);
			mlx_put_pixel(window->image, x, y, ft_get_rgba(255, 255, 255, ft_map(iter, 0, fractal->iter_max, 0, 255)));
			x++;
		}
		y++;
	}
	return (1);
}
