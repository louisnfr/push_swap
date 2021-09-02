/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:00:03 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/02 15:00:27 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
