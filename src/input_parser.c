/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:11:35 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/13 16:00:34 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	ft_print_usage()
{
	ft_printf("Usage: ./fract-ol <mandelbrot|julia> --options\n"
				"Available options:\n"
				"-i <int>	Maximum number of iterations\n"
				"-l <int>	Limit for the absolute value of the complex number\n"
				"-ca <double>	Real part of the complex number for the julia set\n"
				"-cb <double>	Imaginary part of the complex number for the julia set\n");
	exit(1);
}

void	ft_parse_options(int argc, char **argv, t_fractal *fractal)
{
	int		arg;

	arg = 2;
	while (argc > arg + 1)
	{
		if (ft_strncmp(argv[arg], "-i", 3) == 0)
		{
			fractal->iter_max = ft_atoi(argv[arg + 1]);
			arg += 2;
		}
		else if (ft_strncmp(argv[arg], "-l", 3) == 0)
		{
			fractal->limit = ft_atoi(argv[arg + 1]);
			arg += 2;
		}
		else if (ft_strncmp(argv[arg], "-ca", 4) == 0)
		{
			fractal->ca = ft_atof(argv[arg + 1]);
			arg += 2;
		}
		else if (ft_strncmp(argv[arg], "-cb", 4) == 0)
		{
			fractal->cb = ft_atof(argv[arg + 1]);
			arg += 2;
		}
	}
}

void	ft_parse_input(int argc, char **argv, t_fractal *fractal)
{
	if (argc < 2)
		ft_print_usage();
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		fractal->ft_calc = ft_calc_mandelbrot;
		fractal->limit = 4;
		fractal->iter_max = 30;
	}
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		fractal->ft_calc = ft_calc_julia;
		fractal->limit = 4;
		fractal->iter_max = 30;
		fractal->ca = -1;
		fractal->cb = 0.6;
	}
	else
		ft_print_usage();
	ft_parse_options(argc, argv, fractal);
}
