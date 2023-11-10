/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxmanager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:40:59 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/09 15:56:04 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	ft_create_image(t_window *window)
{
	int			x;
	int			y;
	int			iter;
	t_fractal	*fractal;

	fractal = window->fractal;
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

void	ft_rebuild_fractal(t_window *window)
{
	if (!ft_create_image(window))
		return ; //exit
	mlx_image_to_window(window->mlx, window->image, 0, 0);
}

void	ft_resize_hook(int width, int height, t_window *window)
{
	window->width = width;
	window->height = height;
	ft_rebuild_fractal(window);
}
