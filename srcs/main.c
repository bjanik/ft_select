/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:27:32 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/04 17:49:28 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	my_putchar(int c)
{
	return (ft_putchar(c));
}

int	main(int argc, char **argv)
{
	char	buff[MAX_KEY_LENGHT + 1];

	if (argc == 1)
	{
		ft_putstr_fd("Set at least one argument\n", 2);
		return (0);
	}
	check_term(argv);
	tputs(tgetstr("cl", NULL), 1, my_putchar);
	get_win_size();
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
	tputs(tgetstr("vi", NULL), 1, my_putchar);
 	while (42)
	{
		signal(SIGWINCH, new_size);
		signal(SIGCONT, new_size);
		if (!get_col_line())
			display_args(g_term->head);
		else
		{
			tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
			ft_printf("Window is too small\n");
		}
		ft_bzero(buff, MAX_KEY_LENGHT);
		if (read(STDIN, buff, MAX_KEY_LENGHT) < 1)
			exit(-1);
		get_key(buff);
	}
	return (0);
}
