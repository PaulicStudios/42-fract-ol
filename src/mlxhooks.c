/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:53:50 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/11 18:58:44 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	ft_resize_hook(int width, int height, void *param)
{
	t_window	*window;

	window = (t_window *) param;
	window->width = width;
	window->height = height;
	ft_rebuild_fractal(window);
}

void	ft_scroll_hook(double xdelta, double ydelta, void *param)
{
	t_window	*window;

	xdelta = 0;
	window = (t_window *) param;
	if (ydelta > 0)
		window->scale *= 1.1;
	else
		window->scale /= 1.1;
	ft_rebuild_fractal(window);
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_window	*window;

	window = (t_window *) param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		ft_exit_loop(NULL, window);
	}
}
