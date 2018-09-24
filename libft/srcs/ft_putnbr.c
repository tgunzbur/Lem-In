/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:40:21 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 10:50:22 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_mypow(int n, int pow)
{
	int s;

	s = n;
	if (pow == 0)
		return (1);
	while (pow > 1)
	{
		s = s * n;
		pow--;
	}
	return (s);
}

static int	ft_countlength(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void		ft_putnbr(int n)
{
	int		count;

	count = ft_countlength(n);
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		count = 0;
		n = 1;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (count == 1)
	{
		ft_putchar(n + '0');
		count = 0;
	}
	while (count > 0)
	{
		count--;
		ft_putchar((n / ft_mypow(10, count)) + '0');
		n = n - (n / ft_mypow(10, count) * ft_mypow(10, count));
	}
}
