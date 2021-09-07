/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 03:46:17 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/08 00:31:23 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_board	*stack;

	stack = init_board();
	check_input(ac, av, stack);
	if (is_sorted(stack->a))
		free_all(stack);

	large_sort(stack);


	// if (stack->length <= 20)
	// 	small_sort(stack);
	// else if (stack->length <= 100)
	// 	medium_sort(stack);
	// else
	// 	large_sort(stack);
	free_all(stack);
	return (0);
}
