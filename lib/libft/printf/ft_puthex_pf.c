/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:41:19 by pgrossma          #+#    #+#             */
/*   Updated: 2023/10/14 00:46:17 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_pf_loop(unsigned long i, int len, const char *base)
{
	char	c;
	int		wl;

	if (i / 16 > 0)
		len = ft_putptr_pf_loop(i / 16, len, base);
	if (len == -1)
		return (-1);
	c = base[i % 16];
	wl = write(1, &c, 1);
	if (wl == -1 || len == -1)
		return (-1);
	return (len + wl);
}

int	ft_putptr_pf(void *ptr, int len)
{
	int	wl;

	wl = write(1, "0x", 2);
	if (wl == -1 || len == -1)
		return (-1);
	len += wl;
	return (ft_putptr_pf_loop((unsigned long) ptr, len, "0123456789abcdef"));
}

int	ft_putlhex_pf(unsigned int n, int len)
{
	return (ft_putptr_pf_loop((unsigned long) n, len, "0123456789abcdef"));
}

int	ft_putuhex_pf(unsigned int n, int len)
{
	return (ft_putptr_pf_loop((unsigned long) n, len, "0123456789ABCDEF"));
}
