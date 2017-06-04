/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:27:32 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/04 18:21:14 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	get_win_size(void)
{
	struct winsize	w;

	if (ioctl(STDIN, TIOCGWINSZ, &w))
		exit(-1);
	g_term->nb_col = w.ws_col;
	g_term->nb_line = w.ws_row;
}

void	init_term(char **argv)
{
	int	i;

	i = 1;
	if (!(g_term = (t_term*)malloc(sizeof(t_term))))
		exit(-1);
	g_term->nb_col = 0;
	g_term->nb_line = 0;
	g_term->nb_text_col = 0;
	g_term->nb_text_line = 0;
	g_term->head = NULL;
	while (argv[i])
		push_back(&g_term->head, argv[i++]);
	g_term->max_arg_len = get_max_arg_len(g_term->head);
}

int	check_term(char **argv)
{
	char			*termtype;
	struct termios	term;

	if (!isatty(STDIN))
		exit(-1);
	if (!ttyname(STDIN))
		exit(-1);
	if ((termtype = getenv("TERM")) == NULL)
	{
		ft_printf("Missing term variable\n");
		exit(-1);
	}
	tgetent(NULL, termtype);
	tcgetattr(0, &term);
	term.c_lflag &= ~ (ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
	{
		ft_printf("Unable to set terminal\n");
		exit(-1);
	}
	init_term(argv);
	return (0);
}

int	get_col_line(void)
{
	int	cpt;
	int	nb_arg;

	cpt = 1;
	nb_arg = list_len(g_term->head);
	if (g_term->max_arg_len > g_term->nb_col)
		return (-1);
	else
	{
		while (g_term->nb_col / cpt > g_term->max_arg_len + 1)
			cpt++;
		if (g_term->max_arg_len + 1 > g_term->nb_col / cpt)
			return (-1);
		g_term->nb_text_col = cpt;
		g_term->nb_text_line = nb_arg / cpt;
		if (nb_arg % cpt)
			g_term->nb_text_line++;
		if (g_term->nb_text_line > g_term->nb_line)
			return (-1);
	}
	return (0);
}

void	new_size(int signum)
{
	if (signum == SIGWINCH || signum == SIGCONT)
	{
		tputs(tgetstr("cl", NULL), 1, my_putchar);
		get_win_size();
		if (!get_col_line())
			display_args(g_term->head);
		else
		{
			tputs(tgetstr("cl", NULL), 1, my_putchar);
			ft_printf("Window is too small\n");
		}
	}
}
