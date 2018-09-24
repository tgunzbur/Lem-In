/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:19:19 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:26:31 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t count;
	size_t count2;

	count = 0;
	count2 = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dest[count] != '\0' && count < size)
		count++;
	count2 = count;
	while (src[count - count2] != '\0' && count < size - 1)
	{
		dest[count] = src[count - count2];
		count++;
	}
	if (count2 < size)
		dest[count] = '\0';
	return (count2 + ft_strlen(src));
}
