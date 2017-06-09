/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 18:15:26 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/09 18:23:33 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		calcul_display(void)
{
	get_win_size();
	if (!get_col_line())
		display_args(g_select->head);
	else
	{
		tputs(tgetstr("cl", NULL), 1, my_putchar);
		ft_putendl_fd("Window is too small", STDIN);
	}
}

static void	double_colors(char *c1, char *c2)
{
	ft_putstr_fd(c1, STDIN);
	ft_putstr_fd(c2, STDIN);
}

static void	set_colors(char *arg_name)
{
	struct stat	info;

	lstat(arg_name, &info);
	if (S_ISBLK(info.st_mode))
		double_colors(BLU, BACK_CYN);
	else if (S_ISCHR(info.st_mode))
		double_colors(BLU, BACK_YEL);
	else if (S_ISLNK(info.st_mode))
		ft_putstr_fd(MAG, STDIN);
	else if (S_ISDIR(info.st_mode) && ((info.st_mode & S_IXOTH) &&
				info.st_mode & S_ISVTX))
		ft_putstr_fd(GRN, STDIN);
	else if (S_ISDIR(info.st_mode))
		ft_putstr_fd(BOLD_CYAN, STDIN);
	else if (S_ISFIFO(info.st_mode))
		ft_putstr_fd(YEL, STDIN);
	else if (S_ISSOCK(info.st_mode))
		ft_putstr_fd(GRN, STDIN);
	else if (S_ISREG(info.st_mode) && (info.st_mode & S_IXUSR ||
			info.st_mode & S_IXGRP || info.st_mode & S_IXOTH))
		ft_putstr_fd(RED, STDIN);
}

void		display_arg(t_arg *arg)
{
	set_colors(arg->arg_name);
	if (arg->current)
		tputs(tgetstr("us", NULL), 1, my_putchar);
	if (arg->selected)
		tputs(tgetstr("mr", NULL), 1, my_putchar);
	ft_putstr_fd(arg->arg_name, 0);
	tputs(tgetstr("me", NULL), 1, my_putchar);
}

void		display_args(t_arg *head)
{
	int	col;
	int	line;

	tputs(tgetstr("cl", NULL), 1, my_putchar);
	col = 0;
	while (col < g_select->nb_text_col)
	{
		line = 0;
		while (line < g_select->nb_text_line && head)
		{
			tputs(tgoto(tgetstr("cm", NULL), col * (g_select->max_arg_len + 1),
						line), 1, my_putchar);
			display_arg(head);
			line++;
			head = head->next;
		}
		col++;
	}
}
