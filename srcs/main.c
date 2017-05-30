/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:27:32 by bjanik            #+#    #+#             */
/*   Updated: 2017/05/30 17:52:11 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	my_putchar(int c)
{
	return (ft_putchar(c));
}

void	init_terminal(struct termios *term)
{
	tcgetattr(0, term);
	term->c_lflag &= ~ (ICANON | ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	//term->c_oflag &= ~ (OPOST);
	if (tcsetattr(0, TCSADRAIN, term) == -1)
	{
		ft_printf("Unable to set terminal\n");
		exit(-1);
	}
		return ;
}
void	move_cursor(struct termios term)
{
	char	buff[MAX_KEY_LENGHT + 1];
	char	*str;
	char	*line;

	tputs(tgetstr("cl", NULL), 1, my_putchar);
	tputs(tgetstr("sc", NULL), 1, my_putchar);
	//tputs(tgetstr("vi", NULL), 1, my_putchar);
	tputs(tgetstr("mr", NULL), 1, my_putchar);
	tputs(tgoto(tgetstr("cm", NULL), 1, 5), 1, &my_putchar);
	while (42)
	{
		ft_bzero(buff, MAX_KEY_LENGHT);
		read(0, buff, MAX_KEY_LENGHT);
		if (buff[0] == 'u')
			tputs(tgetstr("us", NULL), 1, my_putchar);
		if (buff[0] == ' ')
			tputs(tgetstr("ue", NULL), 1, my_putchar);
		if (buff[0] == 27 && buff[1] == 91 && buff[2] == 68)
			tputs(tgetstr("le", NULL), 1, my_putchar);
		else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 67)
			tputs(tgetstr("nd", NULL), 1, my_putchar);
		else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 65)
			tputs(tgetstr("up", NULL), 1, my_putchar);
		else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 66)
			tputs(tgetstr("do", NULL), 1, my_putchar);
		else if (buff[0] == 'a')
			tputs(tgetstr("rc", NULL), 1, my_putchar);
		else if (buff[0] == 's')
			tputs(tgetstr("sc", NULL), 1, my_putchar);
		else if (buff[0] == 'd')
			tputs(tgetstr("dm", NULL), 1, my_putchar);
		else if (buff[0] == 127)
			tputs(tgetstr("le", NULL), 1, my_putchar);
		else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 72)
			tputs(tgetstr("ho", NULL), 1, my_putchar);
		else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 51 && buff[3] == 126)
			write(1, "DEL", 3);
		else if (buff[0] == 27)
		{
			tputs(tgetstr("rc", NULL), 1, my_putchar);
			tputs(tgetstr("ce", NULL), 1, my_putchar);
			tputs(tgetstr("ve", NULL), 1, my_putchar);
			exit(1);
		}
		else if (buff[0] == 105)
			tputs(tgetstr("mr", NULL), 1, my_putchar);
		else if (buff[0] == 106)
			tputs(tgetstr("me", NULL), 1, my_putchar);
		else
			write(0, &buff, 1);
	}
}

void	handler(int signum)
{
	if (signum == SIGWINCH)
		printf("WINDOW SIZE CHANGED!\n");

}

int	main(int argc, char **argv, char **env)
{
	char	buff[MAX_KEY_LENGHT + 1];
	int		i;
	t_arg	*head;
	t_term	term;

	i = 1;
	if (argc == 1)
		return (0);
	head = NULL;
	while (argv[i])
		push_back(&head, argv[i++]);
	check_term();
	tputs(tgetstr("cl", NULL), 1, my_putchar);
	tputs(tgetstr("sc", NULL), 1, my_putchar);
	while (head)
	{
		ft_putendl_fd(head->arg_name, 0);
		head = head->next;
	}
 	while (42)
	{
		ft_bzero(buff, MAX_KEY_LENGHT);
		read(STDIN, buff, MAX_KEY_LENGHT);
		if (buff[0] == 27 && !buff[1])
		{
			tputs(tgetstr("rc", NULL), 1, my_putchar);
			tputs(tgetstr("cd", NULL), 1, my_putchar);
			tputs(tgetstr("ve", NULL), 1, my_putchar);
			exit(1);
		}
		else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 65)
			
		if (buff[0] == 'r')
			tputs(tgetstr("rc", NULL), 1, my_putchar);
	}
	//move_cursor(term);
	return (0);
}
