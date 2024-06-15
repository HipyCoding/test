# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: candrese <candrese@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 18:11:58 by candrese          #+#    #+#              #
#    Updated: 2024/06/15 20:22:46 by candrese         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
CFLAGS	:= -Wall -Wextra -Werror -g3 #-fsanitize=address

SRCS	:= main.c utils.c split.c init_to_winit.c handle_args.c\
	operator_push_swap.c operator_rotate.c operator_rev_rotate.c\
	free_exit.c checks.c sort.c sorting_utils.c

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "\nCompiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(HEADERS) -o $(NAME)

clean:
	@echo "cleaning..."
	@rm -rf $(OBJS)

fclean: clean
	@echo "full clean..."
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
