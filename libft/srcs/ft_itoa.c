/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:30:48 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 10:46:34 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_setstring(int n, int count, char *nb)
{
	if (n < 0)
	{
		n *= -1;
		nb[0] = '-';
	}
	nb[count] = '\0';
	if (n == 0)
		nb[0] = '0';
	while (n > 0)
	{
		nb[--count] = n % 10 + '0';
		n /= 10;
	}
	return (nb);
}

static int	ft_intlength(int n)
{
	int count;

	count = 0;
	if (n == 0)
		count++;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*nb;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		if ((nb = (char*)malloc(sizeof(char) * 12)) == NULL)
			return (NULL);
		ft_strcpy(nb, "-2147483648");
		return (nb);
	}
	count = ft_intlength(n);
	if ((nb = (char*)malloc(sizeof(char) * (count + 1))) == NULL)
		return (NULL);
	return (ft_setstring(n, count, nb));
}
