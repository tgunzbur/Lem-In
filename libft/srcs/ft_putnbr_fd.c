/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:46:45 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 10:50:32 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_mypow_fd(int n, int pow)
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

static int	ft_countlength_fd(int n)
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

void		ft_putnbr_fd(int n, int fd)
{
	int		count;

	count = ft_countlength_fd(n);
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		count = 0;
		n = 1;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (count == 1)
	{
		ft_putchar_fd(n + '0', fd);
		count = 0;
	}
	while (count > 0)
	{
		count--;
		ft_putchar_fd((n / ft_mypow_fd(10, count)) + '0', fd);
		n = n - (n / ft_mypow_fd(10, count) * ft_mypow_fd(10, count));
	}
}
