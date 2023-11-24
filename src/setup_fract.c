/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:26:42 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/24 17:03:45 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_setup_mandelbrot(t_win *win)
{
	t_fract	*fract;

	fract = win->fract;
	fract->type = MANDELBROT;
	fract->ft_calc = ft_calc_mandelbrot;
	fract->limit = 3;
	fract->iter_max = 30;
	win->scale = 2.5;
	win->off_x = -200;
	win->off_y = 0;
}

void	ft_setup_julia(t_win *win)
{
	t_fract	*fract;

	fract = win->fract;
	fract->type = JULIA;
	fract->ft_calc = ft_calc_julia;
	fract->limit = 4;
	fract->iter_max = 30;
	fract->ca = -0.78;
	fract->cb = 0.1275;
	win->scale = 4;
	win->off_x = 0;
	win->off_y = 0;
}

void	ft_setup_ship(t_win *win)
{
	t_fract	*fract;

	fract = win->fract;
	fract->type = SHIP;
	fract->ft_calc = ft_calc_ship;
	fract->limit = 4;
	fract->iter_max = 100;
	win->off_x = -80;
	win->off_y = -80;
	win->scale = 3.5;
}

void	ft_setup_fern(t_win *win)
{
	t_fract	*fract;

	fract = win->fract;
	fract->type = FERN;
	fract->iter_max = 10000;
	win->scale = 0.75;
	win->off_x = -400;
	win->off_y = -400;
}
