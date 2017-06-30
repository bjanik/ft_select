/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 12:58:18 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/28 14:17:24 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	simulate_susp(void)
{
	char	cp[2];

	cp[0] = '\x1A';
	cp[1] = '\0';
	ioctl(STDIN, TIOCSTI, cp);
}

static void	handler(int signum)
{
	if (signum == SIGWINCH)
		calcul_display();
	else if (signum == SIGTSTP)
	{
		reinit_term();
		signal(SIGTSTP, SIG_DFL);
		simulate_susp();
	}
	else if (signum == SIGCONT)
	{
		check_term();
		handle_signals();
		calcul_display();
	}
	else
	{
		reinit_term();
		exit(128 + signum);
	}
}

void		handle_signals(void)
{
	int	signum;

	signum = 1;
	while (signum < 32)
	{
		signal(signum, handler);
		signum++;
	}
}
