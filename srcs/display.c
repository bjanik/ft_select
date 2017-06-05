/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 18:15:26 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/05 18:52:15 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	display_arg(t_arg *arg)
{
	if (arg->current)
		tputs(tgetstr("us", NULL), 1, my_putchar);
	if (arg->selected)
		tputs(tgetstr("mr", NULL), 1, my_putchar);
	ft_putstr_fd(arg->arg_name, 0);
	tputs(tgetstr("me", NULL), 1, my_putchar);
}

void	display_args(t_arg *head)
{
	int	col;
	int	line;

	tputs(tgetstr("cl", NULL), 1, my_putchar);
	col = 0;
	while (col < g_select->nb_text_col)
	{
		line = 0;
		while (line < g_select->nb_text_line && head)
		{
			tputs(tgoto(tgetstr("cm", NULL), col * (g_select->max_arg_len + 1),
						line), 1, my_putchar);
			display_arg(head);
			line++;
			head = head->next;
		}
		col++;
	}
}
