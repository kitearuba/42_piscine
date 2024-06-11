# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anleclab <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 12:37:41 by anleclab          #+#    #+#              #
#    Updated: 2018/11/06 12:47:35 by anleclab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SRC = ft_display_file.c
OBJ = $(SRC:.c=.o)

.PHONY: all, clean, fclean, re
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all
