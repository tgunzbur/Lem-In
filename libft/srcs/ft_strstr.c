/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:35:08 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:28:13 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	count;
	int	count2;
	int start;

	count = 0;
	count2 = 0;
	start = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[count] != '\0')
	{
		start = count;
		while (haystack[count] == needle[count2])
		{
			count++;
			count2++;
			if (needle[count2] == '\0')
				return ((char *)&(haystack[start]));
		}
		count = start;
		count2 = 0;
		count++;
	}
	return (NULL);
}
