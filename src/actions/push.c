/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:47:56 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/03 16:37:30 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_board *stack)
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
	write(1, "pa\n", 3);
	stack->moves++;
}

void	pb(t_board *stack)
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
	write(1, "pb\n", 3);
	stack->moves++;
}
