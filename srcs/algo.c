/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:38:42 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/02/05 17:36:37 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	find_da_wae(t_room *rooms, char **da_wae, int length)
{
	int	i;

	i = -1;
	if (rooms->ant)
		return (0);
	if (!length)
	{
		if (rooms->end == 1)
			da_wae[length] = rooms->name;
		else
			return (0);
		return (1);
	}
	da_wae[length] = rooms->name;
	if (rooms->end != -1)
		rooms->ant = 1;
	while (++i < rooms->nb_links)
		if (find_da_wae(rooms->links[i], da_wae, length - 1))
			return (1);
	da_wae[length] = NULL;
	rooms->ant = 0;
	return (0);
}

static char	**find_wae(t_room *rooms, int *min, int max)
{
	char	**wae;

	max = (max > 10000 ? 10000 : max);
	if (!(wae = (char**)malloc(sizeof(char *) * (*min + 1))))
		return (NULL);
	if (find_da_wae(rooms, wae, *min - 1))
		return (wae);
	free(wae);
	(*min)++;
	if (max != 0 && *min > max)
		return (NULL);
	return (find_wae(rooms, min, max));
}

t_wae		algo(t_room rooms, int ant, int max_wae)
{
	int		i;
	int		min;
	int		sum;
	t_wae	waes;

	i = 0;
	min = 1;
	sum = 0;
	if (!(waes.name = (char ***)malloc(sizeof(char **) * ant)))
		waes.nb = 0;
	waes.length = (int *)malloc(sizeof(int) * max_wae);
	while (i < max_wae &&
(waes.name[i] = find_wae(&rooms, &min, i == 0 ? 0 : (ant + sum + 1) / (i + 1))))
	{
		if ((i >= 1 && !(ft_strcmp(waes.name[i][0], waes.name[i - 1][0])) &&
			!(ft_strcmp(waes.name[i][1], waes.name[i - 1][1]))))
		{
			waes.nb = i;
			return (waes);
		}
		waes.length[i] = min;
		sum += waes.length[i++];
	}
	waes.nb = i;
	return (waes);
}

int			move_ants(t_wae waes, int **ant_pos, int ants, int *f)
{
	int k;
	int i;
	int j;
	int n;

	k = (*f == 1 ? 1 : 0);
	i = -1;
	n = 0;
	while (++i < waes.nb)
	{
		j = -1;
		while (++j < waes.length[i] - 1)
			if ((j == 0 || !ant_pos[i][j]) && ant_pos[i][j + 1])
			{
				ant_pos[i][j] = ant_pos[i][j + 1];
				ft_put("L%d-%s ", ant_pos[i][j + 1], waes.name[i][j]);
				k++;
				ant_pos[i][j + 1] = 0;
			}
		if ((*f <= ants) && (!i || !(n / (ants - *f + 1) > waes.length[i])))
			ant_pos[i][waes.length[i] - 1] = (*f)++;
		n += waes.length[i];
	}
	ft_putchar('\n');
	return (k + ants - *f + 1);
}

int			print_results(t_wae waes, int ants)
{
	int **ant_pos;
	int count;
	int i;
	int j;

	if (!(ant_pos = (int**)malloc(sizeof(int*) * waes.nb)))
		return (0);
	i = -1;
	while (++i < waes.nb && (j = -1))
	{
		if (!(ant_pos[i] = (int*)malloc(sizeof(int) * waes.length[i])))
			return (0);
		while (++j < waes.length[i])
			ant_pos[i][j] = 0;
	}
	j = 1;
	count = 0;
	while (move_ants(waes, ant_pos, ants, &j) > 0)
		count++;
	ft_put("%d\n", count - 1);
	count = 0;
	while (count < waes.nb)
		free(ant_pos[count++]);
	free(ant_pos);
	return (1);
}
