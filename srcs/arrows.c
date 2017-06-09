/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 13:30:24 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/09 13:04:05 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	arrow_down(t_arg *head)
{
	t_arg	*arg;

	if (head)
	{
		arg = get_current_arg(head);
		arg->current = 0;
		if (!arg->next)
			arg = head;
		else
			arg = arg->next;
		arg->current = 1;
	}
}

void	arrow_up(t_arg *head)
{
	t_arg	*arg;

	if (head)
	{
		arg = get_current_arg(head);
		arg->current = 0;
		if (!arg->prev)
		{
			while (arg->next)
				arg = arg->next;
		}
		else
			arg = arg->prev;
		arg->current = 1;
	}
}

void	arrow_right(t_arg *head)
{
	int		cpt;
	t_arg	*arg;

	cpt = 0;
	if (head)
	{
		arg = get_current_arg(head);
		arg->current = 0;
		while (cpt < g_select->nb_text_line)
		{
			cpt++;
			arg = arg->next;
			if (!arg)
				arg = head;
		}
		arg->current = 1;
	}
}

void	arrow_left(t_arg *head)
{
	int		cpt;
	t_arg	*arg;

	cpt = 0;
	if (head)
	{
		arg = get_current_arg(head);
		arg->current = 0;
		while (cpt < g_select->nb_text_line && arg->prev)
		{
			cpt++;
			arg = arg->prev;
		}
		arg->current = 1;
	}
}

void	select_arg(t_arg *head)
{
	t_arg *arg;

	if (head)
	{
		arg = get_current_arg(head);
		if (arg->selected)
			arg->selected = 0;
		else
			arg->selected = 1;
		arg->current = 0;
		if (arg->next)
			arg->next->current = 1;
		else
			head->current = 1;
	}
}
