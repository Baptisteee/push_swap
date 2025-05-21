# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babodere <babodere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 11:59:34 by babodere          #+#    #+#              #
#    Updated: 2025/05/21 06:22:19 by babodere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = srcs/

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(addprefix ${SRCS_DIR}, push_swap.c parsing.c rotate_nodes.c push_nodes.c swap_nodes.c utils.c cost.c algo.c small_algo.c median.c)

CHECKER_SRCS = $(addprefix $(SRCS_DIR), checker.c parsing.c rotate_nodes.c push_nodes.c swap_nodes.c utils.c)
OBJS_CHECKER = $(SRCS:${CHECKER_SRCS}%.c=${OBJS_DIR}%.o)

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

bonus:
	$(CC) $(CFLAGS) -c $(CHECKER_SRCS) -o $(CHECKER_SRCS) -I.

clean:
	make fclean -C ${LIBFT_DIR}
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f ${NAME}

re: fclean all
