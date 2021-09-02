/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 03:46:17 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/02 17:34:21 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_board	*init_board(void)
{
	t_board	*stack;

	stack = malloc(sizeof(t_board));
	stack->a = malloc(sizeof(t_stack));
	stack->b = malloc(sizeof(t_stack));
	if (!stack || !stack->a || !stack->b)
		terminate(MALLOC, stack);
	stack->a = NULL;
	stack->b = NULL;
	return (stack);
}

int	main(int ac, char **av)
{
	t_board	*stack;

	stack = init_board();
	check_input(ac, av, stack);
	sa(stack);
	sb(stack);
	ss(stack);
	pa(stack);
	pb(stack);
	ra(stack);
	rb(stack);
	rr(stack);
	rra(stack);
	rrb(stack);
	rrr(stack);
	print_board(stack);
	return (0);
}
