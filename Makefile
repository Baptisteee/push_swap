# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babodere <babodere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 11:59:34 by babodere          #+#    #+#              #
#    Updated: 2025/04/27 14:54:08 by babodere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = srcs/

LIBFT_DIR = libft/

LIBFT = libft.a

SRCS = $(addprefix ${SRCS_DIR}, push_swap.c parsing.c)

INCLUDES = $(addprefix ${SRCS_DIR}, push_swap.h)

OBJS_DIR = .objs/

CREATE_OBJS_DIR = mkdir -p $(OBJS_DIR)

OBJS = $(SRCS:${SRCS_DIR}%.c=${OBJS_DIR}%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

all: ${LIBFT} ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} libft/libft.a ${OBJS} -o ${NAME} -I ${INCLUDES}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	@${CREATE_OBJS_DIR}
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

${LIBFT}:
	make -C ${LIBFT_DIR}

clean:
	make fclean -C ${LIBFT_DIR}
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f ${NAME}

re: fclean all
