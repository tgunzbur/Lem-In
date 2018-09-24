/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplacechar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:38:43 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:27:58 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strreplacechar(char *str, char toreplace, char replace)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == toreplace)
			str[count] = replace;
		count++;
	}
	return (str);
}
