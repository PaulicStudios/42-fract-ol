/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_fern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:29:48 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/24 17:39:06 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fern_transformation(t_fract *fract)
{
	double	random;

	random = ft_random_zero_one();
	if (random < 0.01)
	{
		fract->ca = 0;
		fract->cb = 0.16 * fract->b;
	}
	else if (random < 0.86)
	{
		fract->ca = 0.85 * fract->a + 0.04 * fract->b;
		fract->cb = -0.04 * fract->a + 0.85 * fract->b + 1.6;
	}
	else if (random < 0.93)
	{
		fract->ca = 0.2 * fract->a - 0.26 * fract->b;
		fract->cb = 0.23 * fract->a + 0.22 * fract->b + 1.6;
	}
	else
	{
		fract->ca = -0.15 * fract->a + 0.28 * fract->b;
		fract->cb = 0.26 * fract->a + 0.24 * fract->b + 0.44;
	}
}

void	ft_fill_fern(t_win *win)
{
	int		iter;
	t_fract	*fract;

	ft_fill_white(win);
	fract = win->fract;
	iter = 0;
	while (iter < fract->iter_max)
	{
		ft_fern_transformation(fract);
		fract->ca_int = -(int)((((fract->ca + 2.181887) / (2.181887 + 2.655766)
						- 0.5) * win->width) * win->scale + win->off_x);
		fract->cb_int = -(int)(((fract->cb / 9.998258 - 0.5) * (win->height
						/ ((double) win->height / win->width))) * win->scale
				+ win->off_y);
		if (fract->ca_int >= 0 && fract->ca_int < win->width
			&& fract->cb_int >= 0 && fract->cb_int < win->height)
			mlx_put_pixel(win->image, fract->ca_int, fract->cb_int,
				ft_get_rgba(0, 255, 0, 255));
		fract->a = fract->ca;
		fract->b = fract->cb;
		iter++;
	}
}
