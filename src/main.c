/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 03:46:17 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/02 13:05:48 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_board(t_board **stack)
{
	*stack = malloc(sizeof(t_board));
	if (!(*stack))
		ft_terminate(MALLOC, *stack);
	(*stack)->a = NULL;
	(*stack)->b = NULL;
}

int	main(int ac, char **av)
{
	t_board	*stack;

	init_board(&stack);
	check_input(ac, av, stack);
	rotate_a(stack);
	print_board(stack);
	return (0);
}
