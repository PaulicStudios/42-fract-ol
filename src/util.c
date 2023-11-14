/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:37:20 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/14 13:19:09 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_get_rgba(int r, int g, int b, int a)
{
	return ((unsigned int)r << 24 | (unsigned int)g << 16
		| (unsigned int)b << 8 | (unsigned int)a);
}

void	ft_prefill_win(t_win *win, t_fract *fract)
{
	win->height = HEIGHT;
	win->width = WIDTH;
	win->scale = 4;
	win->fract = fract;
	win->image = NULL;
	win->rebuilding = false;
	win->off_x = 0;
	win->off_y = 0;
}

double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}
