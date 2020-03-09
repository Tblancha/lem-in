#include "lem-in.h"

t_salle		*lem_list_new(intmax_t index, char *name)
{
	t_salle	*newroom;

	if(!(newroom = malloc(sizeof(t_salle))))
		return (NULL);
	newroom->index = index;
	newroom->name = ft_strdup(name);
	newroom->next = NULL;
	return (newroom);
}

t_salle		*lem_list_add(t_salle *room, intmax_t index, char *name)
{
	if (room == NULL)
		room = lem_list_new(index, name);
	else
	{
		while (room->next != NULL)
			room = room->next;
		room->next = lem_list_new(index, name);
	}
	return (room->next);
}

void		lem_list_del(t_info *info)
{
	t_salle		*current;

	while (info->begin != NULL)
	{
		current = info->begin;
		info->begin = info->begin->next;
		ft_strdel(info->name[current->index]);
		if (current->link)
		{
			free(current->link);
			current->link = NULL;
		}
		ft_strdel(current->name);
		current->x = 0;
		current->y = 0;
		current->index = 0;
	}
	if (info->name)
	{
		free(info->name);
		info->name = NULL;
	}
}