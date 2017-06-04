/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 15:01:28 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/04 18:43:20 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_free_item(t_arg *arg)
{
	if (arg->next)
		arg->next->current = 1;
	else if (arg->prev)
		arg->prev->current = 1;
	ft_strdel(&arg->arg_name);
	arg->prev = NULL;
	arg->next = NULL;
	ft_memdel((void**)arg);
}

void	remove_item(t_arg **head)
{
	t_arg	*ptr;

	ptr = get_current_arg(*head);
	if (!ptr->next && !ptr->prev)
	{
		ft_free_item(ptr);
		exit_select_escape();
	}
	if (ptr == *head)
	{
		*head = (*head)->next;
		ft_free_item(ptr);
	}
	else
	{
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		ft_free_item(ptr);
	}
	tputs(tgetstr("cl", NULL), 1, my_putchar);
	g_term->max_arg_len = get_max_arg_len(*head);
	display_args(*head);
}
