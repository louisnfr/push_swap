/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 03:46:17 by lraffin           #+#    #+#             */
/*   Updated: 2021/08/28 23:05:10 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init(t_stack **stack, char **av)
{
	*stack = malloc(sizeof(t_stack));
	if (!(*stack))
		ft_terminate(MALLOC);
	(*stack)->value = ft_atoi(av[1]);
	(*stack)->next = NULL;
}

void	init_empty(t_stack **stack)
{
	*stack = malloc(sizeof(t_stack));
	if (!(*stack))
		ft_terminate(MALLOC);
	// (*stack)->value = 0;
	(*stack)->next = NULL;
}

int	main(int ac, char **av)
{
	if (ac < 2)
		ft_terminate(ERROR);
	// ft_fill_stack(av);

	t_stack *a;
	t_stack *b;

	init(&a, av);
	init_empty(&b);

	addback(&a, new_cell(42));
	addback(&a, new_cell(24));
	print_stack(a, "a");
	print_stack(b, "b");
	return (0);
}
