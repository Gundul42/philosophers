# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 15:31:24 by graja             #+#    #+#              #
#    Updated: 2021/09/21 17:31:15 by graja            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

CC		= gcc

SRC		= src/main.c

FLAGS		= -Wall -Wextra -Werror

COMMON		= common/cmdline.c common/ft_atoi.c common/ft_bzero.c \
		  common/ft_calloc.c common/ft_isdigit.c common/time.c

$(NAME)		 :	$(SRC) $(COMMON)
	$(CC) $(FLAGS) $(COMMON) $(SRC) -o $(NAME)

all		:	$(NAME)
