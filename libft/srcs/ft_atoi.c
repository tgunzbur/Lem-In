/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:21:16 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 10:44:17 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	int c;
	int count;
	int signe;
	int	count2;

	c = 0;
	count = 0;
	signe = 1;
	while ((nptr[c] >= 7 && nptr[c] <= 13) ||
			(nptr[c] == ' ' && nptr[c] != '\0'))
		c++;
	if (nptr[c] == '-')
		signe = -1;
	if (nptr[c] == '+' || nptr[c] == '-')
		c++;
	count2 = 0;
	while (nptr[c + count2] >= '0' && nptr[c + count2] <= '9')
		count = (count * 10) + (nptr[c + count2++] - '0');
	return (count * signe);
}
