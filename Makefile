# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 04:32:29 by lraffin           #+#    #+#              #
#    Updated: 2021/09/07 00:19:00 by lraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### PATHS ###
INCLUDE		=	include
COMMON_PATH	=	common
SORTER_PATH	=	sorter
CHECKER_PATH =	checker
LIBFT_PATH	=	libft

### SOURCES ###
SRC_COMMON	=	./src/common/actions/push.c \
				./src/common/actions/swap.c \
				./src/common/actions/rotate.c \
				./src/common/actions/reverse_rotate.c \
				./src/common/exit/terminate.c \
				./src/common/exit/free.c \
				./src/common/init/init.c \
				./src/common/lists/utils0.c \
				./src/common/lists/utils1.c \
				./src/common/lists/utils2.c \
				./src/common/lists/print.c \
				./src/common/parsing/check_input.c

SRC_SORTER	=	./src/sorter/main.c \
				./src/sorter/small_sort.c \
				./src/sorter/medium_sort.c \
				./src/sorter/large_sort.c \
				./src/sorter/array.c \
				./src/sorter/utils0.c

SRC_CHECKER	=	./src/checker/checker.c

### OBJECTS ###
OBJ_COMMON	=	$(SRC_COMMON:.c=.o)
OBJ_SORTER	=	$(SRC_SORTER:.c=.o)
OBJ_CHECKER	=	$(SRC_CHECKER:.c=.o)

### COMPILATION ###
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

### EXECUTABLES ###
NAME		=	push_swap
NAME_CHECKER =	checker

all: $(NAME) $(NAME_CHECKER)

.c.o:
	$(CC) $(FLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME): $(LIBFT) $(OBJ_COMMON) $(OBJ_SORTER)
	$(CC) $(FLAGS) -I$(INCLUDE) -L $(LIBFT_PATH) -o $(NAME) $^ -lft

$(NAME_CHECKER): $(LIBFT) $(OBJ_COMMON) $(OBJ_CHECKER)
	$(CC) $(FLAGS) -I$(INCLUDE) -L $(LIBFT_PATH) -o $(NAME_CHECKER) $^ -lft

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJ_COMMON) $(OBJ_SORTER) $(OBJ_CHECKER)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME) $(NAME_CHECKER)

re: fclean all

norm:
	-@norminette src/
	-@norminette $(INCLUDE)

push:
	git add .
	git status
	git commit -m push_swap
	git push

.PHONY:	all, clean, fclean, re, norm, push


# ### OBJECTS ###
# OBJ = $(addprefix $(OBJ_PATH)/,$(SRCS:.c=.o))
# OBJ_CHECKER = $(addprefix $(OBJ_PATH)/,$(SRCS_CHECKER:.c=.o))

# ### COLORS ###
# NOC         = \033[0m
# BOLD        = \033[1m
# UNDERLINE   = \033[4m
# BLACK       = \033[1;30m
# RED         = \033[1;31m
# GREEN       = \033[1;32m
# YELLOW      = \033[1;33m
# BLUE        = \033[1;34m
# VIOLET      = \033[1;35m
# CYAN        = \033[1;36m
# WHITE       = \033[1;37m

# ### RULES ###

# all: lib dir $(NAME) $(CHECKER)

# lib:
# 	@echo "$(YELLOW)Creating lib files$(NOC)"
# 	@make -C $(LIBFT)

# $(NAME): $(OBJ)
# 	-$(CC) $(FLAGS) -L $(LIBFT) -o $(NAME) $^ -lft
# 	@echo "$(GREEN)Project successfully compiled$(NOC)"

# $(CHECKER): $(OBJ) $(OBJ_CHECKER)
# 	-$(CC) $(FLAGS) -L $(LIBFT) -o $(CHECKER) $^ -lft
# 	@echo "$(GREEN)Checker created$(NOC)"

# dir:
# 	@mkdir -p obj/actions obj/parsing obj/lists obj/exit obj/sort obj/init obj/checker
