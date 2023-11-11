/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:11:35 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/11 18:56:14 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	ft_print_usage()
{
	ft_printf("Usage: ./fract-ol <mandelbrot|julia>\n");
	exit(1);
}

void	ft_parse_input(int argc, char **argv, t_fractal *fractal)
{
	if (argc < 2)
		ft_print_usage();
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		fractal->ft_calc = ft_calc_mandelbrot;
		fractal->limit = 8;
		fractal->iter_max = 50;
	}
	// else if (ft_strncmp(argv[1], "julia") == 0)
		// fractal->ft_calc = ft_calc_julia;
	else
		ft_print_usage();
}
