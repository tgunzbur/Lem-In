/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:00:21 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 10:48:23 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	count;
	char	*temp_dest;
	char	*temp_src;

	temp_dest = (char *)dest;
	temp_src = (char *)src;
	count = 0;
	if (dest > src)
	{
		count = n;
		while (--count < n)
			temp_dest[count] = temp_src[count];
	}
	else
	{
		while (count < n)
		{
			temp_dest[count] = temp_src[count];
			count++;
		}
	}
	return (dest);
}
