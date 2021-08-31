/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:17:28 by lraffin           #+#    #+#             */
/*   Updated: 2021/08/31 18:03:48 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void	swap_a(t_board **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = (*stack)->a;
	second = (*stack)->a->next;
	third = second->next;

	first->next = third;
	second->next = first;
	(*stack)->a = second;
}

void	swap_b(t_board **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = (*stack)->b;
	second = (*stack)->b->next;
	third = second->next;

	first->next = third;
	second->next = first;
	(*stack)->b = second;
}

void	swap_ab(t_board **stack)
{
	swap_a(stack);
	swap_b(stack);
}


