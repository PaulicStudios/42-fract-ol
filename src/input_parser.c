/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:11:35 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/13 18:24:27 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_usage(void)
{
	ft_printf("Usage: ./fract-ol <mandelbrot|julia> --options\n"
		"Available options:\n"
		"-i <int>	Maximum number of iterations\n"
		"-l <int>	Limit for the absolute value of the complex number\n"
		"-ca <double>	Real part of the julia set\n"
		"-cb <double>	Imaginary part of the julia set\n");
	exit(1);
}

void	ft_parse_options(int argc, char **argv, t_fract *fract)
{
	int	arg;

	arg = 2;
	while (argc > arg + 1)
	{
		if (ft_strncmp(argv[arg], "-i", 3) == 0)
			fract->iter_max = ft_atoi(argv[arg + 1]);
		else if (ft_strncmp(argv[arg], "-l", 3) == 0)
			fract->limit = ft_atoi(argv[arg + 1]);
		else if (ft_strncmp(argv[arg], "-ca", 4) == 0)
			fract->ca = ft_atof(argv[arg + 1]);
		else if (ft_strncmp(argv[arg], "-cb", 4) == 0)
			fract->cb = ft_atof(argv[arg + 1]);
		arg += 2;
	}
}

void	ft_parse_input(int argc, char **argv, t_fract *fract)
{
	if (argc < 2)
		ft_print_usage();
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		fract->ft_calc = ft_calc_mandelbrot;
		fract->limit = 4;
		fract->iter_max = 30;
	}
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		fract->ft_calc = ft_calc_julia;
		fract->limit = 4;
		fract->iter_max = 30;
		fract->ca = -0.78;
		fract->cb = 0.1275;
	}
	else
		ft_print_usage();
	ft_parse_options(argc, argv, fract);
}
