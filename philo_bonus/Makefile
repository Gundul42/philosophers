# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 15:31:24 by graja             #+#    #+#              #
#    Updated: 2021/10/06 11:30:18 by graja            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo_bonus

CC		= gcc

SRC		= src/main.c

FLAGS		= -Wall -Wextra -Werror -pthread

COMMON		= common/cmdline.c common/ft_atoi.c common/ft_bzero.c \
		  common/ft_calloc.c common/ft_isdigit.c common/time.c \
		  common/ft_strlen.c common/init.c common/process.c \
		  common/cleanup.c common/foodanddeath.c

$(NAME)		 :	$(SRC) $(COMMON)
	$(CC) $(FLAGS) $(COMMON) $(SRC) -o $(NAME)

all		:	$(NAME)

clean		:

fclean		:
	rm -f $(NAME)

re		:	fclean all
