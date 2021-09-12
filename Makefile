# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 04:32:29 by lraffin           #+#    #+#              #
#    Updated: 2021/09/12 23:53:40 by lraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC		= clang
FLAGS	= -Wall -Wextra -Werror

### EXECUTABLE ###
NAME	= push_swap
CHECKER	= checker
### INCLUDES ###
INCLUDE	= include
LIBFT_PATH	= libft
SRC_PATH	= src
OBJ_PATH	= obj

### SOURCE FILES ###
SOURCES = main.c \
		init/init.c \
		parsing/check_input.c \
		parsing/parse_utils.c \
		actions/push.c \
		actions/swap.c \
		actions/rotate.c \
		actions/reverse_rotate.c \
		sort/small_sort.c \
		sort/medium_sort.c \
		sort/large_sort.c \
		sort/array.c \
		sort/sort_utils0.c \
		sort/sort_utils1.c \
		lists/lists_utils0.c \
		lists/lists_utils1.c \
		lists/lists_utils2.c \
		lists/print.c \
		exit/terminate.c \
		exit/free.c

SOURCES_CH = checker.c \
		init/init.c \
		parsing/check_input.c \
		parsing/parse_utils.c \
		actions/push.c \
		actions/swap.c \
		actions/rotate.c \
		actions/reverse_rotate.c \
		sort/small_sort.c \
		sort/medium_sort.c \
		sort/large_sort.c \
		sort/array.c \
		sort/sort_utils0.c \
		sort/sort_utils1.c \
		lists/lists_utils0.c \
		lists/lists_utils1.c \
		lists/lists_utils2.c \
		lists/print.c \
		exit/terminate.c \
		exit/free.c

### OBJECTS ###
SRC	= $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJ	= $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

SRC_CH	= $(addprefix $(SRC_PATH)/,$(SOURCES_CH))
OBJ_CH	= $(addprefix $(OBJ_PATH)/,$(SOURCES_CH:.c=.o))

### COLORS ###
NOC		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m

### RULES ###

all: $(NAME)

bonus : $(CHECKER)

$(NAME): $(OBJ)
	@echo "$(YELLOW)libft..$(NOC)"
	@make -sC $(LIBFT_PATH)
	@$(CC) $(FLAGS) -L $(LIBFT_PATH) -o $@ $^ -lft
	@echo "$(GREEN)$@$(NOC)"

$(CHECKER): $(OBJ_CH)
	@echo "$(YELLOW)libft..$(NOC)"
	@make -sC $(LIBFT_PATH)
	@$(CC) $(FLAGS) -L $(LIBFT_PATH) -o $@ $^ -lft
	@echo "$(GREEN)$@$(NOC)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDE)/$(NAME).h
	@mkdir -p obj/actions obj/exit obj/sort obj/parsing obj/init obj/lists
	@$(CC) $(FLAGS) -I$(INCLUDE) -c -o $@ $<
	@echo "$(BLUE)gcc $(WHITE)$(notdir $@)$(NOC)"

clean:
	@echo "$(RED)clean$(NOC)"
	@make clean -sC $(LIBFT_PATH)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "$(RED)fclean$(NOC)"
	@make fclean -sC $(LIBFT_PATH)
	@rm -f $(NAME) $(CHECKER)

re: fclean all

norm:
	-@norminette $(SRC_PATH)
	-@norminette $(INCLUDE)

push:
	git add .
	git status
	git commit -m push_swap
	git push

.PHONY:	all, clean, fclean, re, checker, norm, push, bonus
