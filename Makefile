# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapohlen <rapohlen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 10:29:07 by rapohlen          #+#    #+#              #
#    Updated: 2025/12/02 14:28:00 by rapohlen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
AR		= ar rcs
CFLAGS	= -Wall -Wextra -Werror

SRCS	= libmalloc_malloc.c \
		  libmalloc_free.c \
		  libmalloc_free_all.c

OBJS	= $(SRCS:.c=.o)

NAME	= libmalloc.a

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $@ $^

bonus:		$(OBJS)
			$(AR) $(NAME) $^

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: clean fclean all
