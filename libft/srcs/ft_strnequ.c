/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:56:39 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:27:24 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	c;

	if (s1 == NULL || s2 == NULL || n == 0)
		return (1);
	c = 0;
	while (s1[c] == s2[c] && s1[c] != '\0' && s2[c] != '\0' && c < n)
		c++;
	if (c >= n)
		c--;
	if (s1[c] != s2[c])
		return (0);
	return (1);
}
