/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:29:11 by pgrossma          #+#    #+#             */
/*   Updated: 2023/10/11 11:46:18 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len_src;

	len_src = ft_strlen(s1) + 1;
	ptr = malloc(len_src * sizeof(char));
	if (ptr)
		ft_strlcpy(ptr, s1, len_src);
	return (ptr);
}
