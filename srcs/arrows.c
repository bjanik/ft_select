/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 13:30:24 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/04 18:18:03 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	arrow_down(t_arg *head)
{
	t_arg	*arg;

	arg = get_current_arg(head);
	arg->current = 0;
	if (!arg->next)
		arg = head;
	else
		arg = arg->next;
	arg->current = 1;
	display_args(head);
}

void	arrow_up(t_arg *head)
{
	t_arg	*arg;

	arg = get_current_arg(head);
	arg->current = 0;
	if (!arg->prev)
	{
		while (head->next)
			head = head->next;
		arg = head;
	}
	else
		arg = arg->prev;
	arg->current = 1;
	display_args(head);
}

void	arrow_right(t_arg *head)
{
	int		cpt;
	t_arg	*arg;

	cpt = 0;
	arg = get_current_arg(head);
	arg->current = 0;
	while (cpt < g_term->nb_text_line)
	{
		cpt++;
		arg = arg->next;
		if (!arg)
			arg = head;
	}
	arg->current = 1;
	display_args(head);
}

void	arrow_left(t_arg *head)
{
	int		cpt;
	t_arg	*arg;

	cpt = 0;
	arg = get_current_arg(head);
	arg->current = 0;
	while (cpt < g_term->nb_text_line && arg->prev)
	{
		cpt++;
		arg = arg->prev;
	}
	arg->current = 1;
	display_args(head);
}

void	select_arg(t_arg *head)
{
	t_arg *arg;

	arg = get_current_arg(head);
	if (arg->selected)
		arg->selected = 0;
	else
		arg->selected = 1;
	display_args(head);
}
