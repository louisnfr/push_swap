/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 03:46:17 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/06 16:57:47 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_board	*stack;

	stack = init_board();
	check_input(ac, av, stack);
	if (is_sorted(stack->a))
		free_all(stack);
	get_quartiles(stack->a);
	printf("%d %d %d\n", stack->a->q1, stack->a->q2, stack->a->q3);
	// if (stack->length <= 5)
	// 	small_sort(stack);
	// /* else if (stack->length <= 100)
	// 	medium_sort(stack); */
	// else
	// 	medium_sort(stack);


	// print_board(stack);
	free_all(stack);
	return (0);
}
