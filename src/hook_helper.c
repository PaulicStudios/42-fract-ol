/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:29:43 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/14 13:18:09 by pgrossma         ###   ########.fr       */
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
