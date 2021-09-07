/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:29:59 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/07 15:02:51 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_quartiles(t_stack *stack, t_quart *quart)
{
	int		*array;

	array = malloc(sizeof(int) * len(stack));
	if (!array)
		return (free(array));
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

void	sort_10_100(t_board *stack, t_quart *quart)
{
	int	max;

	get_quartiles(stack->a, quart);
	pb_q2(stack, quart);
	get_quartiles(stack->b, quart);
	max = largest(stack->b);
	half_on_a(stack, quart);
	sort_rest_a(stack);
	ra_sorted_half_on_b(stack, quart->q2, max);
	sort_rest_a(stack);
	while (stack->a->value >= quart->q2 && stack->a->value <= max)
		ra(stack, 1);
	while (stack->a->value >= max)
		pb(stack, 1);
	get_quartiles(stack->b, quart);
	max = largest(stack->b);
	half_on_a(stack, quart);
	sort_rest_a(stack);
	ra_sorted_half_on_b(stack, quart->q2, max);
	sort_rest_a(stack);
	while (stack->a->value >= quart->q2 && stack->a->value <= max)
		ra(stack, 1);
}

void	medium_sort(t_board *stack)
{
	t_quart	*quart;

	quart = malloc(sizeof(t_quart));
	if (!quart)
		return ;
	sort_10_100(stack, quart);
	free(quart);
}
