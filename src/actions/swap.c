/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:47:58 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/02 16:57:44 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

void	sa(t_board *stack)
{
	stack->a = swap(stack->a);
	write(1, "sa\n", 3);
}

void	sb(t_board *stack)
{
	stack->b = swap(stack->b);
	write(1, "sb\n", 3);
}

void	ss(t_board *stack)
{
	stack->a = swap(stack->a);
	stack->b = swap(stack->b);
	write(1, "ss\n", 3);
}
