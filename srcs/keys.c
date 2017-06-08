/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:01:59 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/07 17:51:50 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	get_key(char *buff)
{
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 65)
		arrow_up(g_select->head);
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 66)
		arrow_down(g_select->head);
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 67)
		arrow_right(g_select->head);
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 68)
		arrow_left(g_select->head);
	else if (buff[0] == 127 || buff[0] == 8)
		remove_item(&g_select->head);
	else if (buff[0] == 32)
		select_arg(g_select->head);
	else if (buff[0] == 10)
		exit_select_return(g_select->head);
	else if (buff[0] == 27 && !buff[1])
		exit_select_escape();
}
