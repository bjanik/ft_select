/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:01:59 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/28 12:58:46 by bjanik           ###   ########.fr       */
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

void		get_key(char *buff)
{
	if (buff[0] == ESC && buff[1] == '[' && buff[2] == 'A')
		arrow_up(g_select->head);
	else if (buff[0] == ESC && buff[1] == '[' && buff[2] == 'B')
		arrow_down(g_select->head);
	else if (buff[0] == ESC && buff[1] == '[' && buff[2] == 'C')
		arrow_right(g_select->head);
	else if (buff[0] == ESC && buff[1] == '[' && buff[2] == 'D')
		arrow_left(g_select->head);
	else if (buff[0] == DEL || (buff[0] == ESC && buff[1] == '[' &&
				buff[2] == '3' && buff[3] == '~'))
		remove_item(&g_select->head);
	else if (buff[0] == ESC && buff[1] == '[' && buff[2] == 'H')
		home_key(g_select->head);
	else if (buff[0] == ESC && buff[1] == '[' && buff[2] == 'F')
		end_key(g_select->head);
	else if (buff[0] == ' ')
		select_arg(g_select->head);
	else if (buff[0] == '\n')
		exit_select_return(g_select->head);
	else if (buff[0] == ESC && !buff[1])
		exit_select_escape();
}
