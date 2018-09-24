/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:05:26 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:29:20 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*temp;

	count = 0;
	temp = (unsigned char *)s;
	if (n <= 0)
		return (NULL);
	while (count < n && temp[count] != (unsigned char)c)
		count++;
	if (count < n)
		return ((void *)&temp[count]);
	return (NULL);
}
