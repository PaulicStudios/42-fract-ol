/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:59:34 by pgrossma          #+#    #+#             */
/*   Updated: 2023/10/13 13:09:59 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	if (n == 0)
		count++;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_fill(char *str, int n, int *i)
{
	if (n / 10 > 0)
		ft_fill(str, n / 10, i);
	str[(*i)++] = n % 10 + '0';
}

static void	ft_edgecase(char *str, int n, int *i)
{
	str[(*i)++] = '-';
	str[(*i)++] = '2';
	n = 147483648;
	ft_fill(str, n, i);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*str;
	int		i;

	count = ft_numlen(n);
	str = malloc((count + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	if (n == -2147483648)
		ft_edgecase(str, n, &i);
	else
	{
		if (n < 0)
		{
			str[i++] = '-';
			n = -n;
		}
		ft_fill(str, n, &i);
	}
	str[i] = 0;
	return (str);
}
