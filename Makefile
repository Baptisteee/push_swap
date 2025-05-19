# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babodere <babodere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 11:59:34 by babodere          #+#    #+#              #
#    Updated: 2025/05/17 17:26:38 by babodere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = srcs/

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(addprefix ${SRCS_DIR}, push_swap.c parsing.c rotate_nodes.c push_nodes.c swap_nodes.c utils.c cost.c algo.c small_algo.c)

INCLUDES = ${SRCS_DIR}

OBJS_DIR = .objs/

CREATE_OBJS_DIR = mkdir -p $(OBJS_DIR)

OBJS = $(SRCS:${SRCS_DIR}%.c=${OBJS_DIR}%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -ggdb

NAME = push_swap

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} $^ -o $@ -I ${INCLUDES}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	@${CREATE_OBJS_DIR}
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

${LIBFT}:
	make bonus -C ${LIBFT_DIR}

clean:
	make fclean -C ${LIBFT_DIR}
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f ${NAME}

re: fclean all
