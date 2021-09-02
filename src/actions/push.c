/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:47:56 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/02 14:51:19 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_a(t_board *stack)
{
	t_stack	*tmp;

	if (!stack->b)
		return ;
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

	if (!stack->a)
		return ;
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
