/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:34:53 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/07 19:24:01 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_to_b(t_board *stack, t_quart *quart)
{
	get_quartiles(stack->a, quart);
	pb_q2(stack, quart);
}

void	split_to_a(t_board *stack, t_quart *quart)
{
	int size;

	size = len(stack->b);
	get_quartiles(stack->b, quart);
	while (size-- > 0)
	{
		if (len(stack->b) < 13)
			bring_b_push_a(stack, largest(stack->b));
		else
		{
			if (stack->b->value == smallest(stack->b))
			{
				pa(stack, 1);
				ra(stack, 1);
			}
			else if (stack->b->value >= quart->q2)
				pa(stack, 1);
			else
				rb(stack, 1);
		}
	}
}

void	push_swap(t_board *stack, t_quart *quart)
{
	// int max;

	// max = largest(stack->b);
	if (len(stack->b) == 0)
		return ;
	split_to_a(stack, quart);
	push_swap(stack, quart);
	while (stack->a->value <= quart->q3 && !is_sorted(stack->a))
		ra(stack, 1);

}

void	sort_100_500(t_board *stack, t_quart *quart)
{
	split_to_b(stack, quart);
	push_swap(stack, quart);
}

void	large_sort(t_board *stack)
{
	t_quart	*quart;

	quart = malloc(sizeof(t_quart));
	if (!quart)
		return ;
	sort_100_500(stack, quart);
	free(quart);
}
