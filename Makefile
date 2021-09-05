# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 04:32:29 by lraffin           #+#    #+#              #
#    Updated: 2021/09/05 18:45:10 by lraffin          ###   ########.fr        #
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
SOURCES = main.c \
		init/init.c \
		parsing/check_input.c \
		actions/push.c \
		actions/swap.c \
		actions/rotate.c \
		actions/reverse_rotate.c \
		sort/small_sort.c \
		sort/medium_sort.c \
		sort/large_sort.c \
		sort/array.c \
		lists/utils0.c \
		lists/utils1.c \
		lists/utils2.c \
		lists/print.c \
		exit/terminate.c \
		exit/free.c

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
	@echo "$(YELLOW)Creating lib files$(NOC)"
	@make -C $(LIBFT)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -L $(LIBFT) -o $@ $^ -lft
	@echo "$(GREEN)Project successfully compiled$(NOC)"

tmp:
	@mkdir -p obj/actions obj/parsing obj/lists obj/exit obj/sort obj/init

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/$(NAME).h
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(GREEN)[Done]$(NOC)"

clean:
	@echo "$(RED)Supressing libraries files$(NOC)"
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_PATH)

fclean:
	@echo "$(RED)Supressing libraries files$(NOC)"
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
