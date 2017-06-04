/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 14:24:22 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/04 15:53:08 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	exit_select_escape(void)
{
	tputs(tgetstr("cl", NULL), 1, my_putchar);
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	exit(1);
}

void	exit_select_return(t_arg *head)
{
	t_arg	*ptr;

	ptr = head;
	tputs(tgetstr("cl", NULL), 1, my_putchar);
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	while (ptr)
	{
		if (ptr->selected)
			ft_printf("%s ", ptr->arg_name);
		ptr = ptr->next;
	}
	exit(1);

}
