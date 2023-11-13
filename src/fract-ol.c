/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:13:06 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/13 17:31:03 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	ft_exit(char *msg)
{
	if (msg)
		ft_printf("Error: %s\n", msg);
	exit(1);
}

void	ft_exit_loop(char *msg, t_window *window)
{
	if (msg)
		ft_printf("Error: %s\n", msg);
	mlx_close_window(window->mlx);
}

int	main(int argc, char **argv)
{
	t_window	window;
	t_fractal	fractal;

	ft_parse_input(argc, argv, &fractal);
	ft_prefill_window(&window, &fractal);
	window.mlx = mlx_init(window.width, window.height, "Fract-ol", true);
	if (!window.mlx)
		ft_exit("Could not initialize mlx");
	ft_rebuild_fractal(&window);
	mlx_resize_hook(window.mlx, ft_resize_hook, (void *) &window);
	mlx_scroll_hook(window.mlx, ft_scroll_hook, &window);
	mlx_key_hook(window.mlx, ft_key_hook, &window);
	mlx_loop_hook(window.mlx, ft_loop_hook, &window);
	mlx_loop(window.mlx);
	mlx_terminate(window.mlx);
	// system("leaks fractol");
	return (0);
}
