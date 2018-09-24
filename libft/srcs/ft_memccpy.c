/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:56:21 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 10:47:29 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			c1;
	unsigned char	*temp;
	unsigned char	*temp2;

	c1 = 0;
	temp = (unsigned char*)dest;
	temp2 = (unsigned char*)src;
	while (c1 < n && temp2[c1] != (unsigned char)c)
	{
		temp[c1] = temp2[c1];
		c1++;
	}
	if (c1 < n && temp2[c1] == (unsigned char)c)
	{
		temp[c1] = temp2[c1];
		return (&(dest[c1 + 1]));
	}
	return (NULL);
}
