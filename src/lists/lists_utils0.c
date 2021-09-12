/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 22:00:29 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/13 00:15:40 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_cell(int value)
{
	t_stack	*cell;

	cell = malloc(sizeof(t_stack));
	if (!cell)
		return (NULL);
	cell->value = value;
	cell->next = NULL;
	cell->previous = NULL;
	return (cell);
}

t_stack	*getlast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	addback(t_stack **stack, t_stack *cell)
{
	t_stack	*last;

	if (!*stack)
		*stack = cell;
	else
	{
		last = getlast(*stack);
		last->next = cell;
		cell->previous = last;
	}
}

int	len(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	is_empty(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	return (0);
}
