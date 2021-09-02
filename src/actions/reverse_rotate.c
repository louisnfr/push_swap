/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:47:37 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/02 16:11:26 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*reverse_rotate(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!stack || !stack->next)
		return stack;
	tmp = stack;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = stack;
	stack = tmp;
	prev->next = NULL;
	return (stack);
}

void	reverse_rotate_a(t_board *stack)
{
	stack->a = reverse_rotate(stack->a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_board *stack)
{
	stack->b = reverse_rotate(stack->b);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_ab(t_board *stack)
{
	reverse_rotate(stack->a);
	reverse_rotate(stack->b);
	write(1, "rrr\n", 4);
}
