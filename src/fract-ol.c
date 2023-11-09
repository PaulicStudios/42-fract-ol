/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:13:06 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/08 16:02:37 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	main(int argc, char **argv)
{
	t_window	window;
	t_fractal	fractal;

	ft_parse_input(argc, argv, &fractal);
	ft_prefill_window(&window);
	window.mlx = mlx_init(window.width, window.height, "Fract-ol", false);
	if (!window.mlx)
		return (1);
	if (!ft_create_image(&window, &fractal))
		return (1);

	mlx_image_to_window(window.mlx, window.image, 0, 0);
	mlx_loop(window.mlx);
	return (0);
}
