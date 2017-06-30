/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:27:32 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/28 15:24:56 by bjanik           ###   ########.fr       */
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

static void	termcap_is_available(void)
{
	if (!tgetstr("cl", NULL))
		ft_error_msg("Termcap unavailable : cl");
	if (!tgetstr("us", NULL))
		ft_error_msg("Termcap unavailable : us");
	if (!tgetstr("mr", NULL))
		ft_error_msg("Termcap unavailable : mr");
	if (!tgetstr("me", NULL))
		ft_error_msg("Termcap unavailable : me");
	if (!tgetstr("cm", NULL))
		ft_error_msg("Termcap unavailable : cm");
	if (!tgetstr("ti", NULL))
		ft_error_msg("Termcap unavailable : ti");
	if (!tgetstr("te", NULL))
		ft_error_msg("Termcap unavailable : te");
	if (!tgetstr("vi", NULL))
		ft_error_msg("Termcap unavailable : vi");
	if (!tgetstr("ve", NULL))
		ft_error_msg("Termcap unavailable : ve");
}

int			main(int argc, char **argv)
{
	char	buff[MAX_KEY_LENGHT + 1];

	if (argc == 1)
		ft_error_msg("Set at least one argument");
	handle_signals();
	init_select();
	create_arg_list(argv);
	check_term();
	termcap_is_available();
	calcul_display();
	while (42)
	{
		ft_bzero(buff, MAX_KEY_LENGHT);
		if (read(STDIN, buff, MAX_KEY_LENGHT) < 1)
		{
			reinit_term();
			ft_error_msg("Reading standard input failed");
		}
		get_key(buff);
		calcul_display();
	}
	return (0);
}
