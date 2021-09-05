/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 03:46:17 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/05 16:18:24 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_board	*init_board(void)
{
	t_board	*stack;

	stack = malloc(sizeof(t_board));
	if (!stack)
		terminate(MALLOC, stack);
	stack->a = NULL;
	stack->b = NULL;
	stack->moves = 0;
	stack->length = 0;
	return (stack);
}

int	main(int ac, char **av)
{
	t_board	*stack;

	stack = init_board();
	check_input(ac, av, stack);
	if (is_sorted(stack->a))
		free_all(stack);
	if (stack->length <= 5)
		small_sort(stack);
	else
		sort_5_100(stack);
	// print_board(stack);
	free_all(stack);
	return (0);
}
