# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjanik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 10:30:25 by bjanik            #+#    #+#              #
#    Updated: 2017/06/05 13:17:28 by bjanik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT  = libft
LIBFT_INC  = libft/includes
LIB = libft/libft.a

HEADER = includes

SRC_PATH = srcs
OBJ_PATH = obj

SRC_NAME = keys.c \
	   main.c \
	   term.c \
	   list.c \
	   arrows.c \
	   remove.c \
	   exit_select.c \
	   display.c \
	   signals.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIB) -ltermcap -o $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	$(CC) $(CFLAGS) -I$(HEADER) -I$(LIBFT_INC) -c $< -o $@

clean :
	rm -rf $(OBJ_PATH)
	make clean -C $(LIBFT)

fclean : clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re : fclean all
