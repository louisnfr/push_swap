/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 22:00:29 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/02 14:56:03 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*new_cell(int value)
{
	t_stack	*cell;

	cell = malloc(sizeof(t_stack));
	if (!cell)
		return (NULL);
	cell->value = value;
	cell->next = NULL;
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
	}
}

void	addfront(t_stack **stack, t_stack *cell)
{
	cell->next = *stack;
	*stack = cell;
}

void	print_stack(t_stack *stack, char *name)
{
	ft_putstr(name);
	ft_putstr(": ");
	while (stack)
	{
		ft_putnbr(stack->value);
		ft_putstr(" > ");
		stack = stack->next;
	}
	ft_putstr("NULL\n");
}

void	print_board(t_board *stack)
{
	ft_putstr("---\n");
	print_stack(stack->a, "a");
	ft_putstr("---\n");
	print_stack(stack->b, "b");
	ft_putstr("---\n");
}
