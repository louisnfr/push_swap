/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:00:03 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/08 19:26:44 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putstr("\n---\n");
	print_stack(stack->a, "a");
	ft_putstr("---\n");
	print_stack(stack->b, "b");
	ft_putstr("---\n\n");
}

void	print_stack_index(t_stack *stack, char *name)
{
	ft_putstr(name);
	ft_putstr("(id): ");
	while (stack)
	{
		ft_putnbr(stack->index);
		ft_putstr(" > ");
		stack = stack->next;
	}
	ft_putstr("NULL\n");
}

void	print_board_index(t_board *stack)
{
	print_stack_index(stack->a, "a");
	print_stack_index(stack->b, "b");
}
