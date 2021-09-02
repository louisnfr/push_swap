/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:48:00 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/02 16:34:00 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_board *stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stack->a || !stack->a->next)
		return ;
	last = getlast(stack->a);
	tmp = stack->a;
	stack->a = stack->a->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	rb(t_board *stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stack->b || !stack->b->next)
		return ;
	last = getlast(stack->b);
	tmp = stack->b;
	stack->b = stack->b->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	rr(t_board *stack)
{
	ra(stack);
	rb(stack);
}
