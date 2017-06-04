/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:58:05 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/04 17:06:45 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"
# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <signal.h>
# include <sys/ioctl.h>

# define LEFT_ARROW "\027[D"
# define RIGHT_ARROW "\027[C"
# define UP_ARROW "\027[A"
# define DOWN_ARROW "\027[B"
# define MAX_KEY_LENGHT 5
# define STDIN 0

typedef struct		s_arg
{
	char			*arg_name;
	int				len_arg;
	int				selected;
	int				current;
	int				top;
	int				bottom;
	struct s_arg	*next;
	struct s_arg	*prev;
}					t_arg;

typedef struct		s_term
{
	int				nb_col;
	int				nb_line;
	int				nb_text_col;
	int				nb_text_line;
	int				max_arg_len;
	int				current_col;
	int				current_line;
	t_arg			*head;
}					t_term;

t_arg				*add_arg(char *arg_name);
void				push_back(t_arg **head, char *arg_name);
t_arg				*get_current_arg(t_arg *head);
void				init_term(char **argv);
int					check_term(char **argv);
int					list_len(t_arg * head);
int					get_max_arg_len(t_arg *head);
int					get_col_line(void);
void				get_win_size();
void				display_args(t_arg *head);
void				display_arg(t_arg *arg);
int					my_putchar(int c);
void				new_size(int signum);
void				get_key(char *buff);

void			arrow_down(t_arg *head);
void			arrow_up(t_arg *head);
void			arrow_right(t_arg *head);
void			arrow_left(t_arg *head);
void			select_arg(t_arg *head);
void			exit_select_escape(void);
void			exit_select_return(t_arg *head);

void			remove_item(t_arg **head);
t_term	*g_term;
#endif
