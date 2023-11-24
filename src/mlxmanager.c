/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxmanager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:40:59 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/24 13:35:04 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color(int iter, t_fract *fract)
{
	int		r;
	int		g;
	int		b;
	double	t;

	t = (double) iter / (double) fract->iter_max;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (ft_get_rgba(r, g, b, 255));
}

void	ft_fill_image(t_win *win)
{
	int		x;
	int		y;
	int		iter;
	t_fract	*fract;

	fract = win->fract;
	x = 1;
	y = 1;
	while (y < win->height)
	{
		x = 0;
		while (x < win->width)
		{
			iter = fract->ft_calc(x + win->off_x, y + win->off_y, win);
			mlx_put_pixel(win->image, x, y, ft_color(iter, fract));
			x++;
		}
		y++;
	}
}

void	ft_rebuild_fract(t_win *win)
{
	if (win->rebuilding)
		return ;
	win->rebuilding = true;
	if (!win->image)
	{
		win->image = mlx_new_image(win->mlx, win->width, win->height);
		if (!win->image)
			ft_exit_loop("Could not create image", win);
		if (mlx_image_to_window(win->mlx, win->image, 0, 0) == -1)
			ft_exit_loop("Could not put image to win", win);
	}
	if (!mlx_resize_image(win->image, win->width, win->height))
		ft_exit_loop("Could not resize image", win);
	if (win->fract->type == FERN)
		ft_fill_fern(win);
	else
		ft_fill_image(win);
	win->rebuilding = false;
}
