/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:27:42 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/23 16:49:25 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	void	put_param(va_list ap, char param)
{
	if (param == 's')
		ft_putstr(va_arg(ap, char *));
	if (param == 'd')
		ft_putnbr(va_arg(ap, int));
	if (param == 'c')
		ft_putchar((char)va_arg(ap, int));
}

int				ft_put(const char *format, ...)
{
	int		count;
	va_list	ap;

	if (!format)
		return (0);
	va_start(ap, format);
	count = 0;
	while (format[count])
	{
		if (format[count] == '%' && ft_strchr("sdc", format[count + 1]))
			put_param(ap, format[++count]);
		else
			ft_putchar(format[count]);
		count++;
	}
	va_end(ap);
	return (1);
}
