/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:34:53 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/05 23:08:51 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * get array
 * sort array
 * get number of values
 * split in 5 chunks
 * find first number of chunk 1 each direction
 * get closest one on top
**/

void	large_sort(t_board *stack)
{
	// t_chunk	*chunks;
	// int		*array;
	// int		divide;

	// chunks = malloc(sizeof(t_chunk));
	// array = malloc(sizeof(int) * stack->length);
	// if (!array || !chunks)
	// {
	// 	free(array);
	// 	free(chunks);
	// 	terminate(ERROR, stack);
	// }
	// get_array(stack->a, array);
	// sort_array(array, stack->length);

	while (!is_sorted(stack->a))
	{
		if (stack->a->value > stack->a->next->value)
			sa(stack);
		ra(stack);
	}

	// free(array);
	// free(chunks);
}
