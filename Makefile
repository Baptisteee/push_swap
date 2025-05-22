# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babodere <babodere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 11:59:34 by babodere          #+#    #+#              #
#    Updated: 2025/05/22 03:47:39 by babodere         ###   ########.fr        #
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

CFLAGS = -Wall -Wextra -Werror -ggdb

NAME = push_swap
CHECKER_NAME = checker

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	cc ${CFLAGS} $^ -o $@ -I ${INCLUDES}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	@${CREATE_OBJS_DIR}
	cc ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

${LIBFT}:
	make bonus -C ${LIBFT_DIR}

bonus: $(LIBFT)
	cc $(CFLAGS) $(CHECKER_SRCS) -o $(CHECKER_NAME) -I.  -Llibft -lft

clean:
	make fclean -C ${LIBFT_DIR}
	rm -rf $(OBJS_DIR)
	rm -rf $(CHECKER_NAME)

fclean: clean
	rm -f ${NAME}

re: fclean all
