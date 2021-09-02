/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:47:58 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/02 14:12:12 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
