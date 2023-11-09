/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:41:32 by pgrossma          #+#    #+#             */
/*   Updated: 2023/10/14 00:16:24 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(const char s, va_list *args)
{
	if (s == 'c')
		return (ft_putchar_pf(va_arg(*args, int)));
	else if (s == 's')
		return (ft_putstr_pf(va_arg(*args, char *)));
	else if (s == 'p')
		return (ft_putptr_pf(va_arg(*args, void *), 0));
	else if (s == 'd' || s == 'i')
		return (ft_putnbr_pf(va_arg(*args, int), 0));
	else if (s == 'u')
		return (ft_putunbr_pf(va_arg(*args, unsigned int), 0));
	else if (s == 'x')
		return (ft_putlhex_pf(va_arg(*args, unsigned int), 0));
	else if (s == 'X')
		return (ft_putuhex_pf(va_arg(*args, unsigned int), 0));
	else if (s == '%')
		return (ft_putchar_pf('%'));
	return (-1);
}

int	ft_loop(const char *str, va_list *args)
{
	int	i;
	int	count;
	int	newcount;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
			newcount = ft_parse(str[++i], args);
		else
			newcount = ft_putchar_pf(str[i]);
		i++;
		if (newcount == -1)
			return (newcount);
		count += newcount;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = ft_loop(str, &args);
	va_end(args);
	return (count);
}
