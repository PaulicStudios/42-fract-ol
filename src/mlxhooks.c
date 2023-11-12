/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:53:50 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/12 16:16:38 by pgrossma         ###   ########.fr       */
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
	ft_printf("Key: %d| Action: %d\n", keydata.key, keydata.action);
}

void	ft_loop_hook(void *param)
{
	t_window	*window;
	int			mouse_x;
	int			mouse_y;

	window = (t_window *) param;
	if (mlx_is_mouse_down(window->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		mlx_get_mouse_pos(window->mlx, &mouse_x, &mouse_y);
		if (window->mouse.button_pressed)
		{
			window->offset_x += mouse_x - window->mouse.last_x;
			window->offset_y += mouse_y - window->mouse.last_y;
			window->mouse.last_x = mouse_x;
			window->mouse.last_y = mouse_y;
			ft_rebuild_fractal(window);
		}
		else
		{
			window->mouse.button_pressed = true;
			window->mouse.last_x = mouse_x;
			window->mouse.last_y = mouse_y;
		}
	}
	else
		window->mouse.button_pressed = false;
}
