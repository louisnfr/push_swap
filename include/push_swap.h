/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:59:30 by lraffin           #+#    #+#             */
/*   Updated: 2021/08/31 17:59:39 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "libft.h"

# define ERROR "Error\n"
# define MALLOC "Malloc failed\n"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_board
{
	t_stack	*a;
	t_stack	*b;
}	t_board;

/* errors */

void	ft_terminate(char *error_message, t_board *stack);
void	check_input(int ac, char **av, t_board *stack);

/* lists */

t_stack	*new_cell(int value);
void	print_stack(t_stack *stack, char *name);
void	print_board(t_board *stack);
void	addback(t_stack **stack, t_stack *cell);

/* lists */

void	swap_a(t_board **stack);

#endif
