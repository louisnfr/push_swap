/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:45:04 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/13 17:01:58 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest(t_stack *stack)
{
	int	smallest;

	smallest = stack->value;
	while (stack)
	{
		if (stack->value < smallest)
			smallest = stack->value;
		stack = stack->next;
	}
	return (smallest);
}

int	largest(t_stack *stack)
{
	int	largest;

	largest = stack->value;
	while (stack)
	{
		if (stack->value > largest)
			largest = stack->value;
		stack = stack->next;
	}
	return (largest);
}

int	where_is_index(int x, t_stack *stack)
{
	int	i;
	int	size;

	i = 1;
	if (!stack)
		return (-1);
	size = len(stack);
	while (stack)
	{
		if (stack->index == x)
		{
			if (i / size <= 0.5)
				return (1);
			else
				return (2);
		}
		stack = stack->next;
		i++;
	}
	return (-1);
}

int	where_is(int x, t_stack *stack)
{
	int	i;

	i = 1;
	if (!stack)
		return (-1);
	while (stack)
	{
		if (stack->value == x)
		{
			if (i / len(stack) <= 0.5)
				return (1);
			else
				return (2);
		}
		stack = stack->next;
		i++;
	}
	return (-1);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
