/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:59:30 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/13 03:58:13 by lraffin          ###   ########.fr       */
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
	int				index;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct s_board
{
	t_stack	*a;
	t_stack	*b;
	int		moves;
	int		length;
}	t_board;

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
void	print_stack_index(t_stack *stack, char *name);
void	print_board_index(t_board *stack);
void	addback(t_stack **stack, t_stack *cell);
t_stack	*getlast(t_stack *stack);
int		len(t_stack *stack);
int		smallest(t_stack *stack);
int		largest(t_stack *stack);
int		where_is(int x, t_stack *stack);
int		is_on_top(t_stack *stack, int x);
int		is_empty(t_stack *stack);
int		is_sorted(t_stack *stack);
void	bring_a_push_b(t_board *stack, int x);

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

int		count_args(char **av);

void	sort_array(int *array, int n);
void	get_array(t_stack *stack, int *array);
void	small_sort(t_board *stack);
void	sort_2(t_board *stack);
void	sort_3(t_board *stack);
void	prep_4_5(t_board *stack);
void	sort_4_5(t_board *stack);
void	large_sort(t_board *stack);
void	push_swap(t_board *stack);
void	backtrack(t_board *stack, int max);

/* sort utils */

int		where_is_index(int x, t_stack *stack);
int		largest_index(t_stack *stack);
int		smallest_index(t_stack *stack);
int		get_size(t_stack *stack, int max);
int		get_avg(t_stack *stack);
int		get_avg_limit(t_stack *stack, int max);
void	split_to_a(t_board *stack, int avg, int size);
void	split_to_b(t_board *stack);
void	smart_rotate(t_board *stack);
void	get_max_to_a(t_board *stack);

#endif
