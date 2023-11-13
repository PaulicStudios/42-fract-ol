/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:37:20 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/13 19:22:40 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_get_rgba(int r, int g, int b, int a)
{
	return ((unsigned int)r << 24 | (unsigned int)g << 16
		| (unsigned int)b << 8 | (unsigned int)a);
}

double	ft_map(double x, t_ft_map map)
{
	return ((x - map.in_min) * (map.out_max - map.out_min)
		/ (map.in_max - map.in_min) + map.out_min);
}

t_ft_map	ft_create_map(double in_min, double in_max,
			double out_min, double out_max)
{
	t_ft_map	map;

	map.in_min = in_min;
	map.in_max = in_max;
	map.out_min = out_min;
	map.out_max = out_max;
	return (map);
}

void	ft_prefill_win(t_win *win, t_fract *fract)
{
	win->height = HEIGHT;
	win->width = WIDTH;
	win->scale = 1;
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
