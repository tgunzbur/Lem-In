/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:23:03 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/16 11:28:06 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_cwords(char const *s, char c)
{
	int		count;
	int		nb_words;

	nb_words = 0;
	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == c)
		{
			if (count != 0)
				nb_words++;
			while (s[count] == c)
				count++;
		}
		else
			count++;
	}
	if (s[count - 1] != c)
		nb_words++;
	return (nb_words);
}

static char	**ft_splitwords(char const *s, char c, char **split, int words)
{
	int				count;
	unsigned int	start;
	size_t			length;

	length = 0;
	count = 0;
	while (s[count] != '\0')
	{
		while (s[count] == c && s[count] != '\0')
			count++;
		start = count;
		while (s[count] != c && s[count] != '\0')
		{
			length++;
			count++;
		}
		if (length != 0)
		{
			split[words] = ft_strsub(s, start, length);
			words++;
			length = 0;
		}
	}
	return (split);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		words;

	if (s == NULL)
	{
		if ((split = (char **)malloc(sizeof(char *))) == NULL)
			return (NULL);
		split[0] = 0;
		return (split);
	}
	words = 0;
	if ((split = (char**)malloc(sizeof(char*) * ft_cwords(s, c) + 1)) == NULL)
		return (NULL);
	split = ft_splitwords(s, c, split, words);
	split[ft_cwords(s, c)] = 0;
	return (split);
}
