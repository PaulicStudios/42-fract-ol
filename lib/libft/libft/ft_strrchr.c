/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:48:07 by pgrossma          #+#    #+#             */
/*   Updated: 2023/10/10 21:02:32 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	cc;

	cc = (char) c;
	i = ft_strlen(s) - 1;
	if (cc == 0)
		return ((char *) &s[i + 1]);
	while (s[i] && s[i] != cc && i > 0)
		i--;
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (0);
}
