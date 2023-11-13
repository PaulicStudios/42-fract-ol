/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:46:28 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/13 15:52:54 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(double nbr, double power)
{
	double	result;

	result = 1;
	while (power > 0)
	{
		result *= nbr;
		power--;
	}
	return (result);
}
