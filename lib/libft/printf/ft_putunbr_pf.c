/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:47:53 by pgrossma          #+#    #+#             */
/*   Updated: 2023/10/14 00:16:20 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_pf(unsigned int n, int len)
{
	char	c;
	int		wl;

	if (n / 10 > 0)
		len = ft_putunbr_pf(n / 10, len);
	c = n % 10 + '0';
	if (len == -1)
		return (-1);
	wl = write(1, &c, sizeof(c));
	return (len + wl);
}
