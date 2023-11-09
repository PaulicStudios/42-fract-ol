/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:57:00 by pgrossma          #+#    #+#             */
/*   Updated: 2023/10/11 11:46:10 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_c;
	const unsigned char	*src_c;

	if (dst == src)
		return (dst);
	dst_c = (unsigned char *) dst;
	src_c = (unsigned char *) src;
	if (src > dst)
	{
		while (n--)
			*dst_c++ = *src_c++;
	}
	else
	{
		dst_c += n - 1;
		src_c += n - 1;
		while (n--)
			*dst_c-- = *src_c--;
	}
	return (dst);
}
