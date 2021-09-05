/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:29:59 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/05 19:33:55 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	get_quartiles(t_board *stack, int *array, t_math *math)
{
	if (stack->length % 2 == 0)
	{
		math->q1 = array[stack->length * 1 / 4];
		math->q2 = (array[(stack->length * 2 / 4)]
				+ array[(stack->length - 1) * 2 / 4]) / 2;
		math->q3 = array[stack->length * 3 / 4];
	}
	else
	{
		math->q1 = array[stack->length * 1 / 4];
		math->q2 = array[stack->length * 2 / 4];
		math->q3 = array[stack->length * 3 / 4];
	}
}

void	sort_5_100(t_board *stack, t_math *math)
{
	while (smallest(stack->a) <= math->q1)
	{
		if (stack->a->value <= math->q1)
			pb(stack);
		else
			ra(stack);
	}
	while (smallest(stack->a) <= math->q2)
	{
		if (stack->a->value <= math->q2)
			pb(stack);
		else
			ra(stack);
	}
	while (smallest(stack->a) <= math->q3)
	{
		if (stack->a->value <= math->q3)
			pb(stack);
		else
			ra(stack);
	}
	while (!is_empty(stack->a))
		bring_a_push_b(stack, smallest(stack->a));
	while (!is_empty(stack->b))
		bring_b_push_a(stack, largest(stack->b));
}

void	medium_sort(t_board *stack)
{
	t_math	*math;
	int		*array;

	math = malloc(sizeof(t_math));
	array = malloc(sizeof(int) * stack->length);
	if (!array || !math)
		terminate(ERROR, stack);
	get_array(stack->a, array);
	sort_array(array, stack->length);
	get_quartiles(stack, array, math);
	free(array);
	sort_5_100(stack, math);
	free(math);
}
