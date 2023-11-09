/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:00:20 by pgrossma          #+#    #+#             */
/*   Updated: 2023/10/11 13:14:26 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_char;
	unsigned char	c_char;

	if (n == 0)
		return (0);
	i = 0;
	s_char = (unsigned char *) s;
	c_char = (unsigned char) c;
	while (s_char[i] != c_char && i < n - 1)
		i++;
	if (s_char[i] == c_char)
		return ((void *) &s_char[i]);
	return (0);
}
