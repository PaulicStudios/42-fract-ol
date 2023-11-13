/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:30:42 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/13 15:56:46 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_after_point(const char *str)
{
	size_t	i;
	double	result;

	i = 0;
	while (ft_isdigit(str[i]))
		++i;
	result = ft_atoi(str) / ft_pow(10, i);
	return (result);
}

double	ft_atof(const char *str)
{
	size_t	i;
	int		minus;
	double	result;

	i = 0;
	minus = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
		result += ft_after_point(str + i + 1);
	return (result * minus);
}
