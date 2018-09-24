/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:34:50 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:28:40 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtoupper(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		str[count] = ft_toupper(str[count]);
		count++;
	}
	return (str);
}
