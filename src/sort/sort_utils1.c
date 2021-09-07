/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:37:30 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/07 13:37:40 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	closest_below_k(t_stack *stack, int k)
{
	int	i;

	i = 0;
	while (stack->value > k)
	{
		stack = stack->next;
		i++;
	}
	if (i / len(stack) <= 0.5)
		return (1);
	return (2);
}
