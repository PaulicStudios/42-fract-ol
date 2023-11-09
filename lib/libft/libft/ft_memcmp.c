/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:43:40 by pgrossma          #+#    #+#             */
/*   Updated: 2023/10/11 12:44:22 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_c;
	const unsigned char	*s2_c;
	size_t				i;

	if (n == 0)
		return (0);
	s1_c = (unsigned char *) s1;
	s2_c = (unsigned char *) s2;
	i = 0;
	while (s1_c[i] == s2_c[i] && i < n - 1)
		i++;
	return (s1_c[i] - s2_c[i]);
}
