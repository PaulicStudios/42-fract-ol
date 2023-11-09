/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:09:13 by pgrossma          #+#    #+#             */
/*   Updated: 2023/10/11 11:46:11 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bc;
	unsigned char	cc;

	i = 0;
	bc = (unsigned char *) b;
	cc = (unsigned char) c;
	while (i < len)
	{
		bc[i] = cc;
		i++;
	}
	return (b);
}
