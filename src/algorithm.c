/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:34:20 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/13 18:44:44 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_calc_mandelbrot(double x, double y, t_win *win)
{
	int		iter;
	t_fract	*fract;

	fract = win->fract;
	fract->a = (ft_map(x, ft_create_map(0 + win->off_x, 800 + win->off_x, -1.5,
					2.5)) - ((double) win->width / win->height)) * win->scale;
	fract->b = (ft_map(y, ft_create_map(0 + win->off_y, 800 + win->off_y, -1,
					3)) - ((double) win->height / win->width)) * win->scale;
	fract->ca = fract->a;
	fract->cb = fract->b;
	iter = 0;
	while (iter < fract->iter_max)
	{
		fract->ca_aa = fract->a * fract->a;
		fract->ca_bb = fract->b * fract->b;
		fract->aa = fract->ca_aa - fract->ca_bb;
		fract->bb = 2 * fract->a * fract->b;
		fract->a = fract->aa + fract->ca;
		fract->b = fract->bb + fract->cb;
		if (fract->ca_aa + fract->ca_bb > fract->limit)
			break ;
		iter++;
	}
	return (iter);
}

int	ft_calc_julia(double x, double y, t_win *win)
{
	int		iter;
	double	aa;
	double	bb;
	t_fract	*fract;

	fract = win->fract;
	fract->a = (ft_map(x, ft_create_map(0 + win->off_x, 800 + win->off_x, -1,
					3)) - ((double) win->width / win->height)) * win->scale;
	fract->b = (ft_map(y, ft_create_map(0 + win->off_y, 800 + win->off_y, -1,
					3)) - ((double) win->height / win->width)) * win->scale;
	iter = 0;
	while (iter < fract->iter_max)
	{
		aa = fract->a * fract->a;
		bb = fract->b * fract->b;
		fract->aa = aa - bb;
		fract->bb = 2 * fract->a * fract->b;
		fract->a = fract->aa + fract->ca;
		fract->b = fract->bb + fract->cb;
		if (aa + bb > fract->limit)
			break ;
		iter++;
	}
	return (iter);
}
