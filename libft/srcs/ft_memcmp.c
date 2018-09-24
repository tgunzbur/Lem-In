/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:09:09 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 10:48:00 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*temp1;
	unsigned char	*temp2;

	count = 0;
	temp1 = (unsigned char*)s1;
	temp2 = (unsigned char*)s2;
	while (count < n && temp1[count] == temp2[count])
		count++;
	if (count >= n)
		return (0);
	return (temp1[count] - temp2[count]);
}
