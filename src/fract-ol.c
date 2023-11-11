/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:13:06 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/11 16:44:56 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	main(int argc, char **argv)
{
	t_window	window;
	t_fractal	fractal;

	ft_parse_input(argc, argv, &fractal);
	ft_prefill_window(&window, &fractal);
	window.mlx = mlx_init(window.width, window.height, "Fract-ol", true);
	if (!window.mlx)
		return (1);
	ft_rebuild_fractal(&window);
	mlx_resize_hook(window.mlx, ft_resize_hook, (void *) &window);
	mlx_scroll_hook(window.mlx, ft_scroll_hook, &window);
	mlx_loop(window.mlx);
	return (0);
}
