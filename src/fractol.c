/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:13:06 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/14 13:21:15 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit(char *msg)
{
	if (msg)
		ft_printf("Error: %s\n", msg);
	exit(1);
}

void	ft_exit_loop(char *msg, t_win *win)
{
	if (msg)
		ft_printf("Error: %s\n", msg);
	mlx_close_window(win->mlx);
}

int	main(int argc, char **argv)
{
	t_win	win;
	t_fract	fract;

	ft_prefill_win(&win, &fract);
	ft_parse_input(argc, argv, &win);
	win.mlx = mlx_init(win.width, win.height, "Fract-ol", true);
	if (!win.mlx)
		ft_exit("Could not initialize mlx");
	ft_rebuild_fract(&win);
	mlx_resize_hook(win.mlx, ft_resize_hook, (void *) &win);
	mlx_scroll_hook(win.mlx, ft_scroll_hook, &win);
	mlx_key_hook(win.mlx, ft_key_hook, &win);
	mlx_loop_hook(win.mlx, ft_loop_hook, &win);
	mlx_loop(win.mlx);
	mlx_terminate(win.mlx);
	return (0);
}
