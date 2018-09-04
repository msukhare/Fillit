# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhache <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:07:24 by jhache            #+#    #+#              #
#    Updated: 2017/11/22 16:03:28 by msukhare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

LIBDIR = libft

LIB = $(LIBDIR)/libft.a

SRCS = ft_checkerrors.c ft_map.c ft_readfile.c ft_lstsplit.c\
	  ft_posrela.c ft_resolve.c main.c

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(LIB):
	@make -C $(LIBDIR)

$(NAME): $(LIB)
	$(CC) -c $(FLAGS) $(SRCS)
	$(CC) -o $(NAME) $(OBJS) -L$(LIBDIR) -lft

clean:
	/bin/rm -f $(OBJS)
	@make clean -C $(LIBDIR)

fclean: clean
	/bin/rm -f $(NAME)
	@make fclean -C $(LIBDIR)

re: fclean all

.PHONY: all clean fclean re
