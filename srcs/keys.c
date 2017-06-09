/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:01:59 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/09 12:21:16 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	home_key(t_arg *head)
{
	t_arg	*arg;

	if (head)
	{
		arg = get_current_arg(head);
		arg->current = 0;
		head->current = 1;
	}
}

static void	end_key(t_arg *head)
{
	t_arg	*arg;

	if (head)
	{
		arg = get_current_arg(head);
		arg->current = 0;
		while (arg->next)
			arg = arg->next;
		arg->current = 1;
	}
}

void	get_key(char *buff)
{
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 65)
		arrow_up(g_select->head);
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 66)
		arrow_down(g_select->head);
	/*else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 67)
		arrow_right(g_select->head);
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 68)
		arrow_left(g_select->head);*/
	else if (buff[0] == 127 || (buff[0] == 27 && buff[1] == 91 &&
				buff[2] == 51 && buff[3] == 126))
		remove_item(&g_select->head);
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 72)
		home_key(g_select->head);
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 70)
		end_key(g_select->head);
	else if (buff[0] == 32)
		select_arg(g_select->head);
	else if (buff[0] == 10)
		exit_select_return(g_select->head);
	else if (buff[0] == 27 && !buff[1])
		exit_select_escape();
}
