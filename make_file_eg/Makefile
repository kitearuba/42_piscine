# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 16:08:27 by chrrodri          #+#    #+#              #
#    Updated: 2024/04/10 17:15:49 by chrrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = recursive
CC = cc
CFLAGS = -Wall -Wextra -Werror -I../../include
SRC = ft_recursive_factorial.c ../../src/utils.c
OBJ_DIR = build
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

# Default target
all: $(NAME)

# Link the executable
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# Create the build directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Include dependency files if they exist
-include $(DEP)

# Clean target to remove object files and dependency files
clean:
	rm -rf $(OBJ_DIR)

# Full clean target to remove everything, including the executable
fclean: clean
	rm -f $(NAME)

# Rebuild target to clean and rebuild the project
re: fclean all

.PHONY: all clean fclean re
