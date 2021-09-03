/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:45:04 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/03 20:11:15 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

int	is_empty(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	return (0);
}
