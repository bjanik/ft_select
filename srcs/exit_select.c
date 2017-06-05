/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 14:24:22 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/05 18:58:01 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	exit_select_escape(void)
{
	reinit_term();
	exit(1);
}

void	exit_select_return(t_arg *head)
{
	t_arg	*ptr;
	int		first;

	ptr = head;
	first = 0;
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
	reinit_term();
	exit(1);
}
