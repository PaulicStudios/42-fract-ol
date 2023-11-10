/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxmanager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:40:59 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/10 19:20:29 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

mlx_image_t	*ft_create_image(t_window *window)
{
	int			x;
	int			y;
	int			iter;
	t_fractal	*fractal;
	mlx_image_t	*image;

	fractal = window->fractal;
	image = mlx_new_image(window->mlx, window->height, window->width);
	if (!image)
		return (0);
	x = 1;
	y = 1;
	while (y < window->height)
	{
		x = 0;
		while (x < window->width)
		{
			iter = fractal->ft_calc(x, y, window);
			mlx_put_pixel(image, x, y, ft_get_rgba(255, 255, 255, ft_map(iter, 0, fractal->iter_max, 0, 255)));
			x++;
		}
		y++;
	}
	return (image);
}

void	ft_rebuild_fractal(t_window *window)
{
	mlx_image_t	*image;
	mlx_image_t	*old_image;

	if (window->rebuilding)
		return ;
	window->rebuilding = true;
	image = ft_create_image(window);
	if (!image)
		return ; //exit
	old_image = window->image;
	window->image = image;
	mlx_image_to_window(window->mlx, window->image, 0, 0);
	mlx_delete_image(window->mlx, old_image);
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
