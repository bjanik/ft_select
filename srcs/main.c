/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:27:32 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/09 15:38:45 by bjanik           ###   ########.fr       */
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
		ft_error_msg("Set at least one argument");
	handle_signals();
	init_select();
	create_arg_list(argv);
	check_term();
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
		display_args(g_select->head);
	}
	return (0);
}
