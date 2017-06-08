/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 12:58:18 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/08 18:50:39 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	simulate_susp(void)
{
	struct termios	term;
	char			cp[2];

	cp[0] = term.c_cc[VSUSP];
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
		signal(signum, SIG_DFL);
		simulate_susp();
	}
	else if (signum == SIGCONT)
	{
		check_term();
		calcul_display();
	}
	else
	{
		reinit_term();
		exit(signum);
	}
}

void		handle_signals(void)
{
	signal(SIGWINCH, handler);
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	signal(SIGTSTP, handler);
	signal(SIGCONT, handler);
	signal(SIGHUP, handler);
	signal(SIGILL, handler);
	signal(SIGKILL, handler);
	signal(SIGTRAP, handler);
	signal(SIGABRT, handler);
	signal(SIGFPE, handler);
	signal(SIGBUS, handler);
	signal(SIGSEGV, handler);
	signal(SIGSYS, handler);
	signal(SIGPIPE, handler);
	signal(SIGALRM, handler);
	signal(SIGTERM, handler);
	signal(SIGURG, handler);
	signal(SIGCHLD, handler);
	signal(SIGTTIN, handler);
	signal(SIGTTOU, handler);
	signal(SIGXCPU, handler);
}
