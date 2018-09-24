/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:21:04 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/01/31 16:29:11 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H
# define MEMORY_ERROR -1
# define LINE_ERROR -2

# include "../libft/includes/libft.h"

typedef struct	s_vector2
{
	int			x;
	int			y;
}				t_vector2;

typedef struct	s_room
{
	int				ant;
	int				end;
	char			*name;
	struct s_room	**links;
	int				nb_links;
	t_vector2		pos;
}				t_room;

typedef struct	s_wae
{
	int			nb;
	int			*length;
	char		***name;
}				t_wae;

int				create_rooms(t_room *start, char *line, int *error);
int				create_room(t_room *room, char *line);
int				create_command_room(t_room *room, char *line);
int				create_tunnels(t_room *start, char *line, int *error);
int				create_tunnel(t_room *room, char *line);
t_room			**add_link(t_room *room, t_room *ptr);
int				is_commentary(char *line);
int				is_tunnel(char *line, t_room *start);
t_wae			algo(t_room rooms, int ants, int max_wae);
void			draw_rooms(t_room *room);
int				print_results(t_wae waes, int ants);
int				is_room(char *line);

#endif
