/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:27:32 by bjanik            #+#    #+#             */
/*   Updated: 2017/05/30 16:16:00 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_arg	*add_arg(char *arg_name)
{
	t_arg	*new;

	if (!(new = (t_arg*)malloc(sizeof(t_arg))))
		exit(-1);
	new->arg_name = ft_strdup(arg_name);
	new->selected = 0;
	new->current = 0;
	new->index = 0;
	new->top = 0;
	new->bottom = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	push_back(t_arg **head, char *arg_name)
{
	t_arg	*ptr;

	if (*head)
	{
		ptr = *head;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = add_arg(arg_name);
	}
	else
		*head = add_arg(arg_name);
}

int	list_len(t_arg *head)
{
	int	len;

	len = 0;
	while (head)
	{
		head = head->next;
		len++;
	}
	return (len);
}

int	get_max_arg_len(t_arg *head)
{
	int	max_len;
	int	len;

	max_len = 1;
	len = 0;
	while (head)
	{
		if ((len = ft_strlen(head->arg_name)) > max_len)
			max_len = len;
		head = head->next;
	}
	return (max_len);
}

t_arg	*get_current_arg(t_arg *head)
{
	t_arg	*ptr;

	ptr = head;
	while (ptr)
	{
		if (ptr->current)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

