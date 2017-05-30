/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:27:32 by bjanik            #+#    #+#             */
/*   Updated: 2017/05/30 15:00:00 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_term(t_term *term)
{
	struct winsize	ws;

	if (ioctl(STDIN, TIOCGWINSZ, &ws))
		exit(-1);
	term->nb_col = ws.ws_col;
	term->nb_line = ws.ws_row;
}

int	check_term()
{
	char			*termtype;
	struct termios	term;
	char			*tty;

	if (!isatty(STDIN))
		exit(-1);
	if (!ttyname(STDIN))
		exit(-1);
	if ((termtype = getenv("TERM")) == NULL)
	{
		ft_printf("Missing TERM variable\n");
		exit(-1);
	}
	tgetent(NULL, termtype);
	tcgetattr(0, &term);
	term.c_lflag &= ~ (ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	//term->c_oflag &= ~ (OPOST);
	if (tcsetattr(0, TCSANOW, &term) == -1)
	{
		ft_printf("Unable to set terminal\n");
		exit(-1);
	}
	return (0);
}
