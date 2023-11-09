/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:47:53 by pgrossma          #+#    #+#             */
/*   Updated: 2023/10/14 00:54:43 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_edgeminus(int *n)
{
	int		wl;

	wl = 0;
	if (*n == -2147483648)
	{
		wl = write(1, "-2147483648", 11);
		return (wl);
	}
	if (*n < 0)
	{
		wl = write(1, "-", 1);
		*n = -(*n);
	}
	return (wl);
}

int	ft_putnbr_pf(int n, int len)
{
	char	c;
	int		wl;

	wl = ft_edgeminus(&n);
	if (wl == 11)
		return (wl);
	if (wl == -1 || len == -1)
		return (-1);
	len += wl;
	if (n / 10 > 0)
		len = ft_putnbr_pf(n / 10, len);
	if (len == -1)
		return (-1);
	c = n % 10 + '0';
	wl = write(1, &c, 1);
	if (wl == -1 || len == -1)
		return (-1);
	return (len + wl);
}
