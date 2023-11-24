/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:29:43 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/24 17:46:45 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_drag_mouse(int mouse_x, int mouse_y, t_win *win)
{
	if (win->mouse.button_pressed)
	{
		win->off_x -= mouse_x - win->mouse.last_x;
		win->off_y -= mouse_y - win->mouse.last_y;
		win->mouse.last_x = mouse_x;
		win->mouse.last_y = mouse_y;
		ft_rebuild_fract(win);
	}
	else
	{
		win->mouse.button_pressed = true;
		win->mouse.last_x = mouse_x;
		win->mouse.last_y = mouse_y;
	}
}

void	ft_drag_mouse_shift(int mouse_x, int mouse_y, t_win *win)
{
	win->fract->ca = (double) mouse_x / win->width * 2.0 - 1.0;
	win->fract->cb = (double) mouse_y / win->height * 2.0 - 1.0;
	ft_rebuild_fract(win);
}

bool	ft_key_change_values(mlx_key_data_t keydata, t_win *win)
{
	if (keydata.key == MLX_KEY_1)
		ft_setup_julia(win);
	else if (keydata.key == MLX_KEY_2)
		ft_setup_mandelbrot(win);
	else if (keydata.key == MLX_KEY_3)
		ft_setup_ship(win);
	else if (keydata.key == MLX_KEY_4)
		ft_setup_fern(win);
	else if (keydata.key == MLX_KEY_MINUS)
		win->fract->iter_max -= 2;
	else if (keydata.key == MLX_KEY_EQUAL)
		win->fract->iter_max += 2;
	else if (keydata.key == MLX_KEY_LEFT_BRACKET)
		win->fract->limit -= 0.1;
	else if (keydata.key == MLX_KEY_RIGHT_BRACKET)
		win->fract->limit += 0.1;
	else
		return (false);
	return (true);
}

void	ft_scroll_not_fern(double *mouse_x, double *mouse_y, double *factor,
			t_win *win)
{
	*mouse_x = *mouse_x - (win->width / 2);
	*mouse_y = *mouse_y - ((win->height / ((double) win->height / win->width)
				/ 2));
	*factor = 1 / *factor;
}

double	ft_get_factor(double ydelta, t_win *win)
{
	double	factor;

	if (win->fract->type == FERN)
	{
		if (ydelta > 0)
			factor = 1.1;
		else
			factor = 0.9;
	}
	else
	{
		if (ydelta > 0)
			factor = 0.9;
		else
			factor = 1.1;
	}
	return (factor);
}
