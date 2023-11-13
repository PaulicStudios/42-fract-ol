/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:29:43 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/13 20:37:02 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_drag_mouse(int mouse_x, int mouse_y, t_win *win)
{
	if (win->mouse.button_pressed)
	{
		win->off_x += mouse_x - win->mouse.last_x;
		win->off_y += mouse_y - win->mouse.last_y;
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
	win->fract->ca = ft_map(mouse_x,
			ft_create_map(0, win->width, -1, 1));
	win->fract->cb = ft_map(mouse_y,
			ft_create_map(0, win->height, -1, 1));
	ft_rebuild_fract(win);
}

void	ft_normal_zoom(double *mouse_x, double *mouse_y, t_win *win)
{
	*mouse_x = (double)*mouse_x - ((double)win->width / 2);
	*mouse_y = (double)*mouse_y - ((double)win->height / 2);
	*mouse_x *= 1.35;
	*mouse_y *= 1.35;
}

void	ft_ship_zoom(double *mouse_x, double *mouse_y, t_win *win)
{
	*mouse_x = (double)*mouse_x - (double)win->width;
	*mouse_y = (double)*mouse_y - (double)win->height;
}
