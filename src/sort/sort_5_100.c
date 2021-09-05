/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:29:59 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/05 17:21:24 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_array(int *array, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (array[i] > array[i + 1])
		{
			ft_swap(&array[i], &array[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

void	get_array(t_stack *stack, int *array)
{
	int	i;

	i = 0;
	while (stack)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
}

void	get_quartiles(t_board *stack, int *array, int *q1, int *q2, int *q3)
{
	if (stack->length % 2 == 0)
	{
		*q1 = array[stack->length * 1 / 4];
		*q2 = (array[(stack->length * 2 / 4)]
				+ array[(stack->length - 1) * 2 / 4]) / 2;
		*q3 = array[stack->length * 3 / 4];
	}
	else
	{
		*q1 = array[stack->length * 1 / 4];
		*q2 = array[stack->length * 2 / 4];
		*q3 = array[stack->length * 3 / 4];
	}
}

void	sort_5_100(t_board *stack)
{
	int		*array;
	int		q1;
	int		q2;
	int		q3;

	array = malloc(sizeof(int) * stack->length);
	if (!array)
		terminate(ERROR, stack);
	get_array(stack->a, array);
	sort_array(array, stack->length);
	for (int i=0; i<stack->length; i++)
		printf("%d ", array[i]);
	get_quartiles(stack, array, &q1, &q2, &q3);
	free(array);
	while (smallest(stack->a) <= q1)
	{
		if (stack->a->value <= q1)
			pb(stack);
		else
			ra(stack);
	}
	while (smallest(stack->a) <= q2)
	{
		if (stack->a->value <= q2)
			pb(stack);
		else
			ra(stack);
	}
	while (smallest(stack->a) <= q3)
	{
		if (stack->a->value <= q3)
			pb(stack);
		else
			ra(stack);
	}
	while (!is_empty(stack->a))
		pb(stack);
	while (!is_empty(stack->b))
	{
		bring_on_top_b(stack, largest(stack->b));
		pa(stack);
	}
}
