/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:59:30 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/07 03:50:57 by lraffin          ###   ########.fr       */
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

typedef struct s_quart
{
	int	q1;
	int	q2;
	int	q3;
}	t_quart;

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_board
{
	t_stack	*a;
	t_stack	*b;
	int		moves;
	int		length;
}	t_board;

typedef struct s_chunk
{
	int	one;
}	t_chunk;

/* exit */

void	terminate(char *error_message, t_board *stack);
void	free_all(t_board *stack);
void	free_split(char **args, size_t size);

/* parsing */

void	check_input(int ac, char **av, t_board *stack);
int		empty_string(char *av);

/* init */

t_board	*init_board(void);

/* lists */

t_stack	*new_cell(int value);
void	print_stack(t_stack *stack, char *name);
void	print_board(t_board *stack);
void	addback(t_stack **stack, t_stack *cell);
void	addfront(t_stack **stack, t_stack *cell);
t_stack	*getlast(t_stack *stack);
int		len(t_stack *stack);
int		smallest(t_stack *stack);
int		largest(t_stack *stack);
int		where_is(int x, t_stack *stack);
int		is_on_top(t_stack *stack, int x);
int		is_empty(t_stack *stack);
int		is_sorted(t_stack *stack);
void	bring_on_top_a(t_board *stack, int x);
void	bring_on_top_b(t_board *stack, int x);
void	bring_b_push_a(t_board *stack, int x);
void	bring_a_push_b(t_board *stack, int x);
void	get_quartiles(t_stack *stack, t_quart *quart);

/* actions */

void	sa(t_board *stack, int print);
void	sb(t_board *stack, int print);
void	ss(t_board *stack, int print);
void	pa(t_board *stack, int print);
void	pb(t_board *stack, int print);
void	ra(t_board *stack, int print);
void	rb(t_board *stack, int print);
void	rr(t_board *stack, int print);
void	rra(t_board *stack, int print);
void	rrb(t_board *stack, int print);
void	rrr(t_board *stack, int print);

/* sort */

void	small_sort(t_board *stack);
void	sort_2(t_board *stack);
void	sort_3(t_board *stack);
void	prep_4_5(t_board *stack);
void	sort_4_5(t_board *stack);
void	medium_sort(t_board *stack);
void	sort_array(int *array, int n);
void	get_array(t_stack *stack, int *array);
void	large_sort(t_board *stack);

/* sort utils */

void	pb_q2(t_board *stack, t_quart *quart);
void	sort_rest_a(t_board *stack);
void	half_on_a(t_board *stack, t_quart *quart);
void	ra_sorted_half_on_b(t_board *stack, t_quart *quart, int max);

#endif
