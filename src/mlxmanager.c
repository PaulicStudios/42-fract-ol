/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxmanager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:40:59 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/11 13:21:15 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

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
			mlx_put_pixel(window->image, x, y, ft_get_rgba(255, 255, 255, ft_map(iter, 0, fractal->iter_max, 0, 255)));
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
			return ;
		mlx_image_to_window(window->mlx, window->image, 0, 0);
	}
	mlx_resize_image(window->image, window->width, window->height);
	ft_fill_image(window);
	window->rebuilding = false;
}

void	ft_resize_hook(int width, int height, void *param)
{
	t_window	*window;

	ft_printf("Width: %d\n", width);
	ft_printf("Height: %d\n", height);
	window = (t_window *) param;
	window->width = width;
	window->height = height;
	ft_rebuild_fractal(window);
}
