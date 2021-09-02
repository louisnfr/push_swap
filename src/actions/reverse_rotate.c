/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:47:37 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/02 14:58:14 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverse_rotate_a(t_board *stack)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!stack->a || !stack->a->next)
		return ;
	tmp = stack->a;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = stack->a;
	stack->a = tmp;
	prev->next = NULL;
}

void	reverse_rotate_b(t_board *stack)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!stack->b || !stack->b->next)
		return ;
	tmp = stack->b;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = stack->b;
	stack->b = tmp;
	prev->next = NULL;
}

void	reverse_rotate_ab(t_board *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
}
