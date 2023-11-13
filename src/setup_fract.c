/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:26:42 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/13 20:27:18 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_setup_mandelbrot(t_fract *fract)
{
	fract->type = MANDELBROT;
	fract->ft_calc = ft_calc_mandelbrot;
	fract->limit = 4;
	fract->iter_max = 30;
}

void	ft_setup_julia(t_fract *fract)
{
	fract->type = JULIA;
	fract->ft_calc = ft_calc_julia;
	fract->limit = 4;
	fract->iter_max = 30;
	fract->ca = -0.78;
	fract->cb = 0.1275;
}

void	ft_setup_ship(t_fract *fract)
{
	fract->type = SHIP;
	fract->ft_calc = ft_calc_ship;
	fract->limit = 4;
	fract->iter_max = 100;
}
