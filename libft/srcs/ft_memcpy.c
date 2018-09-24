/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:51:55 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 10:48:09 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	count;
	char	*temp1;
	char	*temp2;

	count = 0;
	temp1 = (char*)dest;
	temp2 = (char*)src;
	while (count < n)
	{
		temp1[count] = temp2[count];
		count++;
	}
	return (temp1);
}
