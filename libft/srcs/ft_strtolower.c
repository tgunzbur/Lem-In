/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:36:23 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:28:33 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtolower(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		str[count] = ft_tolower(str[count]);
		count++;
	}
	return (str);
}
