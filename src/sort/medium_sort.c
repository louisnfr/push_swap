/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:29:59 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/06 18:04:23 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	get_quartiles(t_stack *stack, t_quart *quart)
{
	int		*array;

	array = malloc(sizeof(int) * len(stack));
	if (!array)
	{
		free(array);
		return ;
	}
	get_array(stack, array);
	sort_array(array, len(stack));
	if (len(stack) % 2 == 0)
	{
		quart->q1 = (array[(len(stack) * 1 / 4)]
			+ array[(len(stack) - 1) * 1 / 4]) / 2;
		quart->q2 = (array[(len(stack) * 2 / 4)]
			+ array[(len(stack) - 1) * 2 / 4]) / 2;
		quart->q3 = (array[(len(stack) * 3 / 4)]
			+ array[(len(stack) - 1) * 3 / 4]) / 2;
	}
	else
	{
		quart->q1 = array[len(stack) * 1 / 4];
		quart->q2 = array[len(stack) * 2 / 4];
		quart->q3 = array[len(stack) * 3 / 4];
	}
	free(array);
}

void	sort_5_100(t_board *stack)
{
	t_quart	*quart;

	quart = malloc(sizeof(t_quart));
	if (!quart)
		return ;
	get_quartiles(stack->a, quart);
	while (smallest(stack->a) <= quart->q2)
	{
		if (stack->a->value <= quart->q2)
			pb(stack);
		else
			ra(stack);
		printf("%d\n%d\n", quart->q2, smallest(stack->a));
	}

	// get_quartiles(stack->b);
	// while (largest(stack->b) >= stack->b->q1)
	// {
	// 	if (stack->b->value == smallest(stack->b))
	// 	{
	// 		pa(stack);
	// 		ra(stack);
	// 	}
	// 	if (stack->b->value == largest(stack->b))
	// 		pa(stack);
	// 	if (stack->b->value >= stack->b->q1)
	// 		pa(stack);
	// 	rb(stack);
	// }
	// while (!is_empty(stack->b))
	// {
	// 	if (stack->b->value == smallest(stack->b))
	// 	{
	// 		pa(stack);
	// 		ra(stack);
	// 	}
	// 	else if (stack->b->value == largest(stack->b))
	// 		pa(stack);
	// 	rb(stack);
	// 	bring_b_push_a(stack, smallest(stack->b));
	// 	ra(stack);
	// }
	// while (stack->a->value <= stack->b->q2)
	// 	pb(stack);
	// while (largest(stack->b) >= stack->b->q2)
	// {
	// 	if (stack->b->value == smallest(stack->b))
	// 	{
	// 		pa(stack);
	// 		ra(stack);
	// 	}
	// 	if (stack->b->value == largest(stack->b))
	// 		pa(stack);
	// 	if (stack->b->value >= stack->b->q2)
	// 		pa(stack);
	// 	else
	// 		rb(stack);
	// }
	// while (!is_empty(stack->b))
	// {
	// 	if (stack->b->value == smallest(stack->b))
	// 	{
	// 		pa(stack);
	// 		ra(stack);
	// 	}
	// 	else if (stack->b->value == largest(stack->b))
	// 		pa(stack);
	// 	else
	// 		rb(stack);
	// 	// bring_b_push_a(stack, smallest(stack->b));
	// 	// ra(stack);
	// }

}

void	medium_sort(t_board *stack)
{
	sort_5_100(stack);
}

/*
old medium sort

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
 */


// void	get_quartiles(t_board *stack, int *array, t_quart *quart)
// {
// 	if (stack->length % 2 == 0)
// 	{
// 		quart->q1 = array[stack->length * 1 / 4];
// 		quart->q2 = (array[(stack->length * 2 / 4)]
// 				+ array[(stack->length - 1) * 2 / 4]) / 2;
// 		quart->q3 = array[stack->length * 3 / 4];
// 	}
// 	else
// 	{
// 		quart->q1 = array[stack->length * 1 / 4];
// 		quart->q2 = array[stack->length * 2 / 4];
// 		quart->q3 = array[stack->length * 3 / 4];
// 	}
// }
