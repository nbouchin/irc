# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouchin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/27 13:56:26 by nbouchin          #+#    #+#              #
#    Updated: 2018/11/09 15:02:52 by nbouchin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 =	ft_irc
CC      = 	clang
HEADER  = 	includes/
FLAGS   = 	-Wall -Wextra -Werror -g
SRCDIR  = 	srcs/
OBJDIR  = 	objs/

SRC		=  user.c \
		   main.c \
		   socket.c \
		   server.c \

SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(OBJDIR) $(NAME) ft_irc

ft_irc: $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -I $(HEADER) -o $(NAME) $(OBJS)

$(OBJDIR):
	mkdir -p $(OBJDIR)/srcs

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)user.h $(HEADER)socket.h $(HEADER)server.h
	$(CC) -o $@ -c $< $(FLAGS) -I $(HEADER)

clean:
	rm -rf objs

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
