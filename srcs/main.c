/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:27:32 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/05 19:11:21 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			my_putchar(int c)
{
	return (write(0, &c, 1));
}

static void	create_arg_list(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
		push_back(&g_select->head, argv[i++]);
	g_select->max_arg_len = get_max_arg_len(g_select->head);
}

int			main(int argc, char **argv)
{
	char	buff[MAX_KEY_LENGHT + 1];

	if (argc == 1)
	{
		ft_putendl_fd("Set at least one argument", 2);
		return (0);
	}
	handle_signals();
	check_term();
	create_arg_list(argv);
	get_win_size();
	if (!get_col_line())
		display_args(g_select->head);
	else
	{
		tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_putchar);
		ft_putstr_fd("Window is too small", STDIN);
	}
	while (42)
	{
		ft_bzero(buff, MAX_KEY_LENGHT);
		if (read(STDIN, buff, MAX_KEY_LENGHT) < 1)
		{
			ft_putendl_fd("Reading standard input failed", 2);
			exit(-1);
		}
		get_key(buff);
		display_args(g_select->head);
	}
	return (0);
}
