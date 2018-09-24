/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:42:48 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:27:41 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;
	size_t	count2;
	size_t	start;

	count = 0;
	count2 = 0;
	start = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (count <= len && haystack[count] != '\0')
	{
		start = count;
		while (count <= len && haystack[count] == needle[count2])
		{
			count++;
			count2++;
			if (count <= len && needle[count2] == '\0')
				return ((char *)&(haystack[start]));
		}
		count = start;
		count2 = 0;
		count++;
	}
	return (NULL);
}
