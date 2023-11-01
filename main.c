/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:13:06 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/01 18:18:19 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include <math.h>
#include <stdio.h>

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

double	map(double x, double in_min, double in_max, double out_min, double out_max)
{
	return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

int	mandelbrot(double x, double y)
{
	int			iter;
	double		real;
	double		imag;

	iter = 0;
	while (iter < 100)
	{
        double r2 = x * x;
        double i2 = y * y;
        if (r2 + i2 > 4.0) {
            break ;
        }
        imag = real * imag + imag;
        real = r2 - i2 + real;
		iter++;
	}
	return (get_rgba((iter % 8) * 32, (iter % 16) * 15, (iter % 32) * 8, 255));

}

int	main(void)
{
	mlx_t	*mlx;
	mlx_image_t	*image;
	double		x;
	double		y;

	mlx = mlx_init(1920, 1080, "Hello World!", true);

	image = mlx_new_image(mlx, 1920, 1080);
	x = 1;
	y = 1;
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			mlx_put_pixel(image, x, y, mandelbrot(map(x, 0, 1920, -2.5, 1), map(y, 0, 1080, -1, 1)));
			x++;
		}
		y++;
	}
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	return (0);
}