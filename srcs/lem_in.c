/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:02:56 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/02/05 17:23:23 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		free_room(t_room *room, t_wae waes)
{
	int	count;

	count = 0;
	while (count < room->nb_links)
	{
		free(room->links[count]->links);
		free(room->links[count]->name);
		free(room->links[count]);
		count++;
	}
	free(room->links);
	free(room);
	count = 0;
	while (count < waes.nb)
		free(waes.name[count++]);
	free(waes.name);
	free(waes.length);
}

t_room		*find_start(t_room *room)
{
	int		count;
	t_room	*start;

	count = 0;
	while (count < room->nb_links && room->links[count]->end != -1)
		count++;
	if (count >= room->nb_links)
		return (NULL);
	start = room->links[count++];
	while (count < room->nb_links && room->links[count]->end != -1)
		count++;
	if (count < room->nb_links)
		return (NULL);
	count = 0;
	while (count < room->nb_links && room->links[count]->end != 1)
		count++;
	if (count++ >= room->nb_links)
		return (NULL);
	while (count < room->nb_links && room->links[count]->end != 1)
		count++;
	if (count < room->nb_links)
		return (NULL);
	return (start);
}

int			calc_max_wae(t_room *room)
{
	int	count;
	int	max_wae;

	count = 0;
	while (count < room->nb_links && room->links[count]->end != -1)
		count++;
	if (count == room->nb_links || room->links[count]->end != -1)
		return (0);
	max_wae = room->links[count]->nb_links;
	count = 0;
	while (count < room->nb_links && room->links[count]->end != 1)
		count++;
	if (count == room->nb_links || room->links[count]->end != 1)
		return (0);
	if (max_wae > room->links[count]->nb_links)
		max_wae = room->links[count]->nb_links;
	return (max_wae);
}

int			main(void)
{
	t_wae	wae;
	t_room	*rooms[2];
	char	*line;
	int		nb_ants;
	int		max_wae;

	if (!(rooms[0] = malloc(sizeof(t_room))))
		return (ft_put("Error 1\n"));
	rooms[0]->nb_links = 0;
	rooms[0]->links = NULL;
	if (!get_next_line(0, &line) || (nb_ants = ft_atoi(line)) <= 0)
		return (ft_put("Error 2\n"));
	if (create_rooms(rooms[0], line, &max_wae) == MEMORY_ERROR)
		return (ft_put("Error 3\n"));
	max_wae = calc_max_wae(rooms[0]);
	if (max_wae == 0 || !(rooms[1] = find_start(rooms[0])))
		return (ft_put("Error 4\n"));
	wae = algo(*rooms[1], nb_ants, max_wae);
	if (wae.nb == 0)
		return (ft_put("Error 5\n"));
	print_results(wae, nb_ants);
	free_room(rooms[0], wae);
	return (0);
}
