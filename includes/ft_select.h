/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:58:05 by bjanik            #+#    #+#             */
/*   Updated: 2017/05/30 16:39:40 by bjanik           ###   ########.fr       */
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

typedef struct		s_term
{
	int				nb_col;
	int				nb_line;
	int				nb_text_col;
	int				nb_text_line;
	int				max_arg_len;
}					t_term;

typedef struct		s_arg
{
	char			*arg_name;
	int				len_arg;
	int				selected;
	int				current;
	int				index;
	int				top;
	int				bottom;
	struct s_arg	*next;
	struct s_arg	*prev;
}					t_arg;

t_arg				*add_arg(char *arg_name);
void				push_back(t_arg **head, char *arg_name);
void				init_term(t_term *term);
int					check_term(void);
int					list_len(t_arg * head);
int					get_max_arg_len(t_arg *head);
#endif
