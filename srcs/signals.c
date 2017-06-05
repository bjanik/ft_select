/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 12:58:18 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/05 19:22:11 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	handler(int signum)
{
	if (signum == SIGWINCH)
	{
		get_win_size();
		if (!get_col_line())
			display_args(g_select->head);
		else
		{
			tputs(tgetstr("cl", NULL), 1, my_putchar);
			ft_putendl_fd("Window is too small", 2);
		}
	}
	if (signum == SIGINT)
	{
		reinit_term();
		exit(-1);
	}
	if (signum == SIGTSTP)
	{
		reinit_term();
	}
	if (signum == SIGCONT)
	{
		init_term();
		signal(SIGCONT, SIG_DFL);
	}
}

void		handle_signals(void)
{
	signal(SIGWINCH, handler);
	signal(SIGINT, handler);
	signal(SIGTSTP, handler);
}
