/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:34:53 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/06 00:07:59 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	large_sort(t_board *stack)
{
	t_quart	*quart;
	int		*array;

	quart = malloc(sizeof(t_quart));
	array = malloc(sizeof(int) * stack->length);
	if (!array || !quart)
	{
		free(quart);
		free(array);
		terminate(ERROR, stack);
	}
	get_array(stack->a, array);
	sort_array(array, stack->length);
	free(array);
	free(quart);
}
