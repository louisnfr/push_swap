/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:48:00 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/02 14:58:00 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate_a(t_board *stack)
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

void	rotate_b(t_board *stack)
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

void	rotate_ab(t_board *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}
