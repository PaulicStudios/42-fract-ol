/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fern_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:30:02 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/24 17:31:49 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	ft_random_nbr(void)
{
	int				fd;
	unsigned int	nbr;
	int				read_bytes;

	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
		return (0);
	read_bytes = read(fd, &nbr, sizeof(unsigned int));
	close(fd);
	return (nbr);
}

double	ft_random_zero_one(void)
{
	return (ft_random_nbr() / (double) UINT_MAX);
}

void	ft_fill_white(t_win *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < win->height)
	{
		x = 0;
		while (x < win->width)
		{
			mlx_put_pixel(win->image, x, y, ft_get_rgba(255, 255, 255, 255));
			x++;
		}
		y++;
	}
}
