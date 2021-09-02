/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:17:28 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/02 13:30:52 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_board *stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = stack->a;
	second = stack->a->next;
	third = second->next;
	first->next = third;
	second->next = first;
	stack->a = second;
}

void	swap_b(t_board *stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = stack->b;
	second = stack->b->next;
	third = second->next;
	first->next = third;
	second->next = first;
	stack->b = second;
}

void	swap_ab(t_board *stack)
{
	swap_a(stack);
	swap_b(stack);
}

void	push_a(t_board *stack)
{
	t_stack	*tmp;

	tmp = stack->b;
	if (stack->a && stack->b)
	{
		stack->b = stack->b->next;
		tmp->next = stack->a;
		stack->a = tmp;
	}
	else if (stack->b && !stack->a)
	{
		stack->b = stack->b->next;
		tmp->next = NULL;
		stack->a = tmp;
	}
}

void	push_b(t_board *stack)
{
	t_stack	*tmp;

	tmp = stack->a;
	if (stack->a && stack->b)
	{
		stack->a = stack->a->next;
		tmp->next = stack->b;
		stack->b = tmp;
	}
	else if (stack->a && !stack->b)
	{
		stack->a = stack->a->next;
		tmp->next = NULL;
		stack->b = tmp;
	}
}

void	rotate_a(t_board *stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stack->a)
		return ;
	last = getlast(stack->a);
	tmp = stack->a;
	stack->a = stack->a->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	rotate_b(t_board *stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stack->b)
		return ;
	last = getlast(stack->b);
	tmp = stack->b;
	stack->b = stack->b->next;
	tmp->next = NULL;
	last->next = tmp;
}
