/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 10:54:58 by gpirro        #+#    #+#                 */
/*   Updated: 2022/04/21 14:00:00 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*list_init(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == 0)
		exit (0);
	list->top = 0;
	list->len = 0;
	return (list);
}

void	free_elems(t_elem *elem, int free_data)
{
	if (elem->next)
		free_elems(elem->next, free_data);
	if (free_data)
		free(elem->data);
	free(elem);
}

void	free_list(t_list *list, int free_data)
{
	if (list->top)
		free_elems(list->top, free_data);
	free(list);
}

void	*list_add(t_list *list, void *data)
{	
	t_elem	*new_elem;
	t_elem	*tmp;

	new_elem = malloc(sizeof(t_elem));
	if (new_elem == 0)
		exit (0);
	new_elem->data = data;
	new_elem->next = 0;
	if (list->top == NULL)
	{
		list->top = new_elem;
		new_elem->prev = 0;
	}
	else
	{
		tmp = list->top;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_elem;
		new_elem->prev = tmp;
	}
	list->len++;
	return (data);
}

void	**list_to_array(t_list *list)
{
	void	**res;
	int		i;
	t_elem	*elem;

	res = malloc(sizeof(void *) * list->len);
	if (res == 0)
	{
		free_list(list, 1);
		return (0);
	}
	i = 0;
	elem = list->top;
	while (elem)
	{
		res[i] = elem->data;
		elem = elem->next;
		i++;
	}
	free_list(list, 0);
	return (res);
}
