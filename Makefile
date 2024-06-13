# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: candrese <candrese@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 18:11:58 by candrese          #+#    #+#              #
#    Updated: 2024/06/13 05:09:25 by candrese         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
CFLAGS	:= -Wall -Wextra -Werror -g3 #-fsanitize=address

SRCS	:= main.c utils.c split.c init_to_winit.c handle_args.c\
	push_and_swap.c rotate.c rev_rotate.c free_exit.c checks.c\
	sort.c sorting_utils.c

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
