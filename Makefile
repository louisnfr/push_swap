# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 04:32:29 by lraffin           #+#    #+#              #
#    Updated: 2021/08/28 19:13:37 by lraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC      = gcc
FLAGS  = -Wall -Wextra -Werror

### EXECUTABLE ###
NAME   = push_swap

### INCLUDES ###
HEADER = include
LIBFT  = libft
SRC_PATH  = src
OBJ_PATH  = obj

### SOURCE FILES ###
SOURCES = main.c

### OBJECTS ###
SRC = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJ = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

### RULES ###

all: lib tmp $(NAME)

lib:
	@echo "$(GREEN)Creating lib files$(CYAN)"
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -L $(LIBFT) -o $@ $^
	@echo "$(GREEN)Project successfully compiled"

tmp:
	@mkdir -p obj

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/$(NAME).h
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

clean:
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_PATH)

fclean:
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

norm:
	-@norminette $(SRC)
	-@norminette $(HEADER)

push:
	git add .
	git status
	git commit -m push_swap
	git push

.PHONY:	re, clean, fclean, tmp, norm, push
