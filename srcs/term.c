/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:27:32 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/05 19:11:34 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	get_win_size(void)
{
	struct winsize	w;

	if (ioctl(STDIN, TIOCGWINSZ, &w))
		exit(-1);
	g_select->nb_col = w.ws_col;
	g_select->nb_line = w.ws_row;
}

void	init_term(void)
{
	int	i;

	i = 1;
	if (!(g_select = (t_term*)malloc(sizeof(t_term))))
	{
		ft_putendl_fd("Malloc failed", 2);
		exit(-1);
	}
	g_select->nb_col = 0;
	g_select->nb_line = 0;
	g_select->nb_text_col = 0;
	g_select->nb_text_line = 0;
	g_select->head = NULL;
}

void	reinit_term(void)
{
	struct termios	term;

	if (tcgetattr(STDIN, &term) == -1)
		exit(-1);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tputs(tgetstr("cl", NULL), 1, my_putchar);
	tputs(tgetstr("te", NULL), 1, my_putchar);
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	if (tcsetattr(STDIN, TCSANOW, &term) == -1)
	{
		ft_putendl_fd("Unable to set terminal", 2);
		exit(-1);
	}
}

int		check_term(void)
{
	char			*termtype;
	struct termios	term;

	if (!isatty(STDIN))
		exit(-1);
	if (!ttyname(STDIN))
		exit(-1);
	if ((termtype = getenv("TERM")) == NULL)
	{
		ft_putendl_fd("Missing term variable", 2);
		exit(-1);
	}
	tgetent(NULL, termtype);
	if (tcgetattr(STDIN, &term) == -1)
		exit(-1);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tputs(tgetstr("cl", NULL), 1, my_putchar);
	tputs(tgetstr("ti", NULL), 1, my_putchar);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
	tputs(tgetstr("vi", NULL), 1, my_putchar);
	if (tcsetattr(STDIN, TCSANOW, &term) == -1)
	{
		ft_putendl_fd("Unable to set terminal", 2);
		exit(-1);
	}
	init_term();
	return (0);
}

int		get_col_line(void)
{
	int	cpt;
	int	nb_arg;

	cpt = 1;
	nb_arg = list_len(g_select->head);
	if (g_select->max_arg_len > g_select->nb_col)
		return (-1);
	else
	{
		while (g_select->nb_col / cpt > g_select->max_arg_len + 1)
			cpt++;
		if (g_select->max_arg_len + 1 > g_select->nb_col / cpt)
			return (-1);
		g_select->nb_text_col = cpt;
		g_select->nb_text_line = nb_arg / cpt;
		if (nb_arg % cpt)
			g_select->nb_text_line++;
		if (g_select->nb_text_line > g_select->nb_line)
			return (-1);
	}
	return (0);
}
