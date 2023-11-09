/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:25:28 by pgrossma          #+#    #+#             */
/*   Updated: 2023/10/11 13:07:10 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hi;
	size_t	ni;

	if (!haystack && len == 0)
		return (0);
	if (needle[0] == 0)
		return ((char *) haystack);
	hi = 0;
	while (haystack[hi] && hi < len)
	{
		ni = 0;
		while (haystack[hi + ni] == needle[ni] && needle[ni] && hi + ni < len)
			ni++;
		if (needle[ni] == 0)
			return ((char *) &haystack[hi]);
		hi++;
	}
	return (0);
}
