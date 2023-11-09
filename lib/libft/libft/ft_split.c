/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:52:33 by pgrossma          #+#    #+#             */
/*   Updated: 2023/11/01 21:28:34 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		found;

	i = 0;
	count = 0;
	while (s[i])
	{
		found = 0;
		while (s[i] && s[i] != c)
		{
			found = 1;
			i++;
		}
		if (found)
			count++;
		else
			i++;
	}
	return (count);
}

static void	ft_freearray(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

static int	ft_fillarray(char const *s, char c, char **array, size_t count)
{
	size_t	i;
	size_t	cc;
	size_t	len;

	i = 0;
	cc = 0;
	while (cc < count)
	{
		while (s[i] && s[i] == c)
			i++;
		len = 0;
		while (s[i + len] && s[i + len] != c)
			len++;
		array[cc] = malloc((len + 1) * sizeof(char));
		if (!array[cc])
			return (0);
		ft_strlcpy(array[cc], &s[i], len + 1);
		i += len;
		cc++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**array;

	if (!s)
		return (0);
	count = ft_wordcount(s, c);
	array = malloc((count + 1) * sizeof(char *));
	if (!array)
		return (0);
	if (!ft_fillarray(s, c, array, count))
	{
		ft_freearray(array);
		return (0);
	}
	array[count] = 0;
	return (array);
}
