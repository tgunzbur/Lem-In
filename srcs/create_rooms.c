/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 12:31:18 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/31 16:40:44 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			is_room(char *line)
{
	int		count;

	count = 0;
	if (line[0] == 'L' || line[0] == '#')
		return (0);
	while (line[count] && line[count] != ' ')
		if (line[count++] == '-')
			return (0);
	if (!line[count++])
		return (0);
	while (line[count] && line[count] != ' ')
		if (!ft_isdigit(line[count++]))
			return (0);
	if (!line[count++])
		return (0);
	while (line[count])
		if (!ft_isdigit(line[count++]))
			return (0);
	return (1);
}

static int	is_command(char *line)
{
	if (line[0] == '#' && line[1] == '#')
		return (1);
	else
		return (0);
}

int			is_commentary(char *line)
{
	if (line[0] == '#')
		return (1);
	else
		return (0);
}

static int	free_line(int error, char *line)
{
	if (line)
		free(line);
	return (error);
}

int			create_rooms(t_room *start, char *line, int *error)
{
	ft_putendl(line);
	free(line);
	while (get_next_line(0, &line))
	{
		ft_putendl(line);
		if (is_room(line))
		{
			if ((*error = create_room(start, line)) <= 0)
				return (free_line(*error, line));
		}
		else if (is_command(line))
		{
			if ((*error = create_command_room(start, line)) <= 0)
				return (free_line(*error, line));
		}
		else if (is_tunnel(line, start))
			return (create_tunnels(start, line, error));
		else if (!is_commentary(line))
			return (free_line(LINE_ERROR, line));
		free(line);
	}
	return (1);
}
