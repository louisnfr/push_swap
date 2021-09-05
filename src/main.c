/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 03:46:17 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/05 22:46:44 by lraffin          ###   ########.fr       */
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
	if (stack->length <= 5)
		small_sort(stack);
	else if (stack->length <= 100)
		medium_sort(stack);
	else
		large_sort(stack);
	// print_board(stack);
	free_all(stack);
	return (0);
}
