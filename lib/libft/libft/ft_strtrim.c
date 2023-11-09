/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:49:43 by pgrossma          #+#    #+#             */
/*   Updated: 2023/10/12 12:48:04 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	ib;
	size_t	ie;
	size_t	len_s1;

	if (!s1 || !set)
		return (0);
	ib = 0;
	while (s1[ib] && ft_strchr(set, s1[ib]))
		ib++;
	len_s1 = ft_strlen(s1);
	if (ib == len_s1 || len_s1 == 0)
		return (ft_strdup(""));
	ie = 0;
	ie = len_s1 - 1;
	while (s1[ie] && ft_strchr(set, s1[ie]) && ie > 0)
		ie--;
	return (ft_substr(s1, ib, ie - ib + 1));
}
