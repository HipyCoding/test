# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: candrese <candrese@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 18:11:58 by candrese          #+#    #+#              #
#    Updated: 2024/05/13 20:43:18 by candrese         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
CFLAGS	:= -Wall -Wextra -Werror #-g3 -fsanitize=address

SRCS	:= main.c utils.c split.c init_to_winit.c handle_args.c\
	push_and_swap.c rotate.c rev_rotate.c

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(LIB):
	@make -sC $(LIB_PATH)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LIB) -o $(NAME)

clean:
	@echo "cleaning up..."
	@rm -rf $(OBJS)

fclean: clean
	@echo "full cleaning up..."
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
