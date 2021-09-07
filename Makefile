# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 04:32:29 by lraffin           #+#    #+#              #
#    Updated: 2021/09/07 02:12:59 by lraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC      = gcc
FLAGS  = -Wall -Wextra -Werror

### EXECUTABLE ###
NAME   = push_swap
CHECKER = checker
### INCLUDES ###
INCLUDE = include
LIBFT_PATH  = libft
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
		sort/utils0.c \
		lists/utils0.c \
		lists/utils1.c \
		lists/utils2.c \
		lists/print.c \
		exit/terminate.c \
		exit/free.c

SOURCES_CH = checker.c \
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
		sort/utils0.c \
		lists/utils0.c \
		lists/utils1.c \
		lists/utils2.c \
		lists/print.c \
		exit/terminate.c \
		exit/free.c

### OBJECTS ###
SRC = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJ = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

SRC_CH = $(addprefix $(SRC_PATH)/,$(SOURCES_CH))
OBJ_CH = $(addprefix $(OBJ_PATH)/,$(SOURCES_CH:.c=.o))

### COLORS ###
NOC         = \033[0m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
WHITE       = \033[1;37m

### RULES ###

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(OBJ)
	@echo "$(YELLOW)libft...$(NOC)"
	@make -sC $(LIBFT_PATH)
	@$(CC) $(FLAGS) -L $(LIBFT_PATH) -o $@ $^ -lft
	@echo "$(GREEN)$@$(NOC)"

$(CHECKER): $(OBJ_CH)
	@echo "$(YELLOW)libft...$(NOC)"
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



# ### PATHS ###
# INCLUDE		=	include
# COMMON_PATH	=	common
# SORTER_PATH	=	sorter
# CHECKER_PATH =	checker
# LIBFT_PATH	=	libft

# ### SOURCES ###
# SRC_COMMON	=	./src/common/actions/push.c \
# 				./src/common/actions/swap.c \
# 				./src/common/actions/rotate.c \
# 				./src/common/actions/reverse_rotate.c \
# 				./src/common/exit/terminate.c \
# 				./src/common/exit/free.c \
# 				./src/common/init/init.c \
# 				./src/common/lists/utils0.c \
# 				./src/common/lists/utils1.c \
# 				./src/common/lists/utils2.c \
# 				./src/common/lists/print.c \
# 				./src/common/parsing/check_input.c

# SRC_SORTER	=	./src/sorter/main.c \
# 				./src/sorter/small_sort.c \
# 				./src/sorter/medium_sort.c \
# 				./src/sorter/large_sort.c \
# 				./src/sorter/array.c \
# 				./src/sorter/utils0.c

# SRC_CHECKER	=	./src/checker/checker.c

# ### OBJECTS ###
# OBJ_COMMON	=	$(SRC_COMMON:.c=.o)
# OBJ_SORTER	=	$(SRC_SORTER:.c=.o)
# OBJ_CHECKER	=	$(SRC_CHECKER:.c=.o)

# ### COMPILATION ###
# CC			=	gcc
# FLAGS		=	-Wall -Wextra -Werror

# ### EXECUTABLES ###
# NAME		=	push_swap
# NAME_CHECKER =	checker

# all: $(NAME) $(NAME_CHECKER)

# .c.o:
# 	$(CC) $(FLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

# $(NAME): $(LIBFT) $(OBJ_COMMON) $(OBJ_SORTER)
# 	$(CC) $(FLAGS) -I$(INCLUDE) -L $(LIBFT_PATH) -lft -o $(NAME) $^

# $(NAME_CHECKER): $(LIBFT) $(OBJ_COMMON) $(OBJ_CHECKER)
# 	$(CC) $(FLAGS) -I$(INCLUDE) -L $(LIBFT_PATH) -lft -o $(NAME_CHECKER) $^

# $(LIBFT):
# 	make -C $(LIBFT_PATH)

# clean:
# 	make clean -C $(LIBFT_PATH)
# 	rm -rf $(OBJ_COMMON) $(OBJ_SORTER) $(OBJ_CHECKER)

# fclean: clean
# 	make fclean -C $(LIBFT_PATH)
# 	rm -rf $(NAME) $(NAME_CHECKER)

# re: fclean all

# norm:
# 	-@norminette src/
# 	-@norminette $(INCLUDE)

# push:
# 	git add .
# 	git status
# 	git commit -m push_swap
# 	git push

# .PHONY:	all, clean, fclean, re, norm, push
