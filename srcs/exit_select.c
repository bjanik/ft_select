/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 14:24:22 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/28 12:59:15 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	free_data(void)
{
	t_arg	*ptr;

	ptr = g_select->head;
	while (ptr)
	{
		g_select->head = g_select->head->next;
		ft_strdel(&ptr->arg_name);
		ft_memdel((void**)&ptr);
		ptr = g_select->head;
	}
	ft_memdel((void**)&g_select);
}

void		exit_select_escape(void)
{
	reinit_term();
	free_data();
	exit(0);
}

void		exit_select_return(t_arg *head)
{
	t_arg	*ptr;
	int		first;

	ptr = head;
	first = 0;
	reinit_term();
	while (ptr)
	{
		if (ptr->selected)
		{
			ft_printf("%.*s%s", first, " ", ptr->arg_name);
			if (!first)
				first = 1;
		}
		ptr = ptr->next;
	}
	free_data();
	exit(0);
}
