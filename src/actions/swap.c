/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:47:58 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/07 02:05:50 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*third;

	if (!stack || !stack->next)
		return (stack);
	tmp = stack;
	third = stack->next->next;
	stack = stack->next;
	stack->next = tmp;
	tmp->next = third;
	return (stack);
}

void	sa(t_board *stack, int print)
{
	stack->a = swap(stack->a);
	if (print)
		write(1, "sa\n", 3);
	stack->moves++;
}

void	sb(t_board *stack, int print)
{
	stack->b = swap(stack->b);
	if (print)
		write(1, "sb\n", 3);
	stack->moves++;
}

void	ss(t_board *stack, int print)
{
	stack->a = swap(stack->a);
	stack->b = swap(stack->b);
	if (print)
		write(1, "ss\n", 3);
	stack->moves++;
}
