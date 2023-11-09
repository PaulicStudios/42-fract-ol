/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:04:43 by pgrossma          #+#    #+#             */
/*   Updated: 2023/10/11 11:46:17 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	cc;

	i = 0;
	cc = (char) c;
	if (cc == 0)
	{
		while (s[i] != cc)
			i++;
	}
	else
	{
		while (s[i] != 0 && s[i] != cc)
			i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (0);
}
