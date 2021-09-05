/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:29:59 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/05 22:37:20 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	get_quartiles(t_board *stack, int *array, t_quart *quart)
{
	if (stack->length % 2 == 0)
	{
		quart->q1 = array[stack->length * 1 / 4];
		quart->q2 = (array[(stack->length * 2 / 4)]
				+ array[(stack->length - 1) * 2 / 4]) / 2;
		quart->q3 = array[stack->length * 3 / 4];
	}
	else
	{
		quart->q1 = array[stack->length * 1 / 4];
		quart->q2 = array[stack->length * 2 / 4];
		quart->q3 = array[stack->length * 3 / 4];
	}
}

void	sort_5_100(t_board *stack, t_quart *quart)
{
	while (smallest(stack->a) <= quart->q1)
	{
		if (stack->a->value <= quart->q1)
			pb(stack);
		else
			ra(stack);
	}
	while (smallest(stack->a) <= quart->q2)
	{
		if (stack->a->value <= quart->q2)
			pb(stack);
		else
			ra(stack);
	}
	while (smallest(stack->a) <= quart->q3)
	{
		if (stack->a->value <= quart->q3)
			pb(stack);
		else
			ra(stack);
	}
	while (!is_empty(stack->a) && (!is_sorted(stack->a)))
		bring_a_push_b(stack, smallest(stack->a));
	while (!is_empty(stack->b))
		bring_b_push_a(stack, largest(stack->b));
}

void	medium_sort(t_board *stack)
{
	t_quart	*quart;
	int		*array;

	quart = malloc(sizeof(t_quart));
	array = malloc(sizeof(int) * stack->length);
	if (!array || !quart)
		terminate(ERROR, stack);
	get_array(stack->a, array);
	sort_array(array, stack->length);
	get_quartiles(stack, array, quart);
	free(array);
	sort_5_100(stack, quart);
	free(quart);
}
